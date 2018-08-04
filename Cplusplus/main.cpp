#include <cstring>
#include <iostream>

class Bitmap {
private:
    size_t *_data;
    size_t _size;
    void resize(size_t n) {
        if (_data != nullptr) {
            delete[] _data;
        }
        _size = n;
        _data = new size_t[n];
        memset(_data, 0, sizeof(size_t) * _size);
    }
    void expand() {
        auto old_data = _data;
        auto old_size = _size;
        _size <<= 1;
        _data = new size_t[_size];
        memset(_data, 0, sizeof(size_t) * _size);
        for (int i = 0; i < old_size; ++i) {
            _data[i] = old_data[i];
        }
        delete[] old_data;
    }

public:
    Bitmap(size_t n = 5) {
        _data = nullptr;
        resize((n >> 5) + 1);
    }
    ~Bitmap() { delete[] _data; }
    void set(size_t n) {
        auto pos = n % 32;
        auto index = n >> 5;
        if (_size <= index) {
            expand();
        }
        _data[n >> 5] |= 1 << pos;
    }
    bool get(size_t n) {
        auto pos = n % 32;
        return _data[n >> 5] & (1 << pos);
    }
    void remove(size_t n) {
        auto pos = n % 32;
        _data[n >> 5] &= ~(1 << pos);
    }
    bool test(size_t n) { return get(n); }
};

template <typename K, typename V> struct Entry {
    K key;
    V value;
    bool removed;
    Entry(K k = K(), V v = V()) : key(k), value(v) {}

    Entry(Entry<K, V> const &e) : key(e.k), value(e.v) {}

    bool operator<(Entry<K, V> const &e) { return key < e.key; }

    bool operator>(Entry<K, V> const &e) { return key > e.key; }

    Entry &operator=(Entry<K, V> const &e) {
        value = e.value;
        return *this;
    }

    bool operator==(Entry<K, V> const &e) { return key == e.key; }

    bool operator!=(Entry<K, V> const &e) { return key != e.key; }
};
const int PRIME[] = {2,      3,      5,       7,      17,    37,
                     79,     163,    331,     667,    1339,  2683,
                     5371,   10747,  21499,   43003,  86011, 172027,
                     344059, 688123, 1376251, 2752507};

size_t Hashcode(int n) { return (size_t)n; }

template <typename T, typename Fn> void for_each(T begin, T end, Fn fun) {
    for (; begin != end; ++begin) {
        fun(begin);
    }
}

template <typename K, typename V> class Hashtable {
private:
    // 哈希桶
    Entry<K, V> **_ht;
    // 桶的容量和已使用大小
    int M;
    int N;
    Bitmap *_lazy_removed;
    int probe4Hit(K const &k);
    int probe4Free(K const &k);
    int primeNT(int c);
    void rehash();

public:
    Hashtable();
    ~Hashtable();

    // 放入桶中
    bool put(K const &k, V const &v);
    V *get(K const &k);
    bool update(K const &k, V const &v);
    bool remove(K const &k);
};

template <typename K, typename V> Hashtable<K, V>::~Hashtable() {
    //    delete _lazy_removed;
    //    for (int r = 0; r < M; ++r) {
    //        remove(r);
    //    }
}

template <typename K, typename V> int Hashtable<K, V>::probe4Hit(const K &k) {
    int r = Hashcode(k) % M;
    while ((_ht[r] && _ht[r]->key != k) || (!_ht[r] && _lazy_removed->get(r))) {
        r = (r + 1) % M;
    }
    return r;
}

template <typename K, typename V> int Hashtable<K, V>::probe4Free(const K &k) {
    int r = Hashcode(k) % M;
    while (_ht[r]) {
        r = (r + 1) % M;
    }
    return r;
}

template <typename K, typename V> int Hashtable<K, V>::primeNT(int c) {
    int length = sizeof(PRIME) / sizeof(PRIME[0]);
    if (c < PRIME[length - 1]) {
        for (int i = 0; i < length; ++i) {
            if (PRIME[i] > c) {
                return PRIME[i];
            }
        }
    }
    return c;
}

template <typename K, typename V> Hashtable<K, V>::Hashtable() {
    M = primeNT(109);
    N = 0;
    _lazy_removed = new Bitmap(1000);
    _ht = new Entry<K, V> *[M];
}

template <typename K, typename V> bool Hashtable<K, V>::remove(const K &k) {
    int r = probe4Hit(k);
    //    std::cout << "r:" << r << std::endl;
    if (!_ht[r]) {
        return false;
    }
    _lazy_removed->remove(r);
    --N;
    //    std::cout << "---" << std::endl;
    delete _ht[r];
    _ht[r] = nullptr;
    //    std::cout << "------" << std::endl;
    return true;
}
template <typename K, typename V>
bool Hashtable<K, V>::put(const K &k, const V &v) {
    auto r = probe4Hit(k);
    //    std::cout << "r:" << r << std::endl;
    if (_ht[r]) {
        return false;
    }
    _ht[r] = new Entry<K, V>(k, v);
    _lazy_removed->set(r);
    return true;
}

template <typename K, typename V> V *Hashtable<K, V>::get(const K &k) {
    auto r = probe4Free(k);
    return ((_ht[r] != nullptr) ? &(_ht[r]->value) : nullptr);
}

template <typename K, typename V>
bool Hashtable<K, V>::update(const K &k, const V &v) {
    if (get(k)) {
        int r = probe4Hit(k);
        _ht[r]->value = v;
        return true;
    }
    return false;
}

template <typename K, typename V> void Hashtable<K, V>::rehash() {
    auto old_capcity = M;
    M = primeNT(M * 2);
    N = 0;
    auto old_ht = _ht;
    _ht = new Entry<K, V> *[M];
    memset(_ht, 0, sizeof(Entry<K, V> *) * M);
    delete[] _lazy_removed;
    _lazy_removed = new Bitmap(M);
    for (int r = 0; r < old_capcity; ++r) {
        if (_ht[r]) {
            put(old_ht[r]->key, old_ht[r]->value);
        }
    }
    delete[] old_ht;
}

int main() {
    int n;
    std::cin >> n;
    Hashtable<int, bool> hash;
    for (int i = 0; i < n; ++i) {
        int e, number;
        std::cin >> e >> number;
        // std::cout << "get:" << hash.get(number);
        auto result = (e == 1) ? hash.put(number, true) : hash.remove(number);
        printf("%s\n", (result == true) ? "Succeeded" : "Failed");
    }
    return 0;
}