#include <cstdio>
#include <cstring>
#include <iostream>
int PRIME[] = {2,     3,      5,      7,      17,      37,     79,    163,
               331,   667,    1339,   2683,   5371,    10747,  21499, 43003,
               86011, 172027, 344059, 688123, 1376251, 2752507};

static size_t hashCode(char s[]) {
    int h = 0;
    for (int i = strlen(s) - 1; i >= 0; --i) {
        h = (h << 5) | (h >> 27);
        h += (int)s[i];
    }
    return (size_t)h;
}

template <typename T> static size_t hashCode(T e) { return (size_t)e; }

template <typename T, typename Fn> void for_each(T begin, T end, Fn fun) {
    for (; begin != end; ++begin) {
        fun(begin);
    }
}

template <typename K, typename V> struct Entry {
    K key;
    V value;
    Entry(K k = K(), V v = V()) : key(k), value(v) {}
    Entry(Entry<K, V> const &e) : key(e.k), value(e.v) {}
};

template <typename K, typename V> class Hashtable {
  private:
    Entry<K, V> **ht;
    int M;
    int N;

    template <typename T> void release(T x) {
        if (x) {
            delete x;
        }
    }
    int primeNT(int c) {
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

    Bitmap *lazyReomval;

#define lazilyRemoved(x) (lazlyRemoval->test(x))
#define markAsRemoved(x) (lazlyRemoval->set(x))
  protected:
    int probe4Hit(const K &k) {
        int r = hashCode(k) % M;
        while ((ht[r] && (k != ht[r]->key)) || (!ht[r] && lazilyRemoved(r))) {
            r = (r + 1) % M;
        }
        return r;
    }
    int probe4Free(const K &k) {
        int r = hashCode(k) % M;
        while (ht[r]) {
            r = (r + 1) % M;
        }
        return r;
    }
    void rehash() {
        auto old_capacity = M;
        M = primeNT(M * 2);
        N = 0;
        auto old_ht = ht;
        memset(ht, 0, sizeof(Entry<K, V> *) * M);
        release(lazyReomval);
        lazyReomval = new Bitmap(M);
        for (int i = 0; i < old_capacity; ++i) {
            if (old_ht[i]) {
                put(old_ht[i]->key, old_ht[i]->value);
            }
        }
        release(old_ht);
    }

  public:
    Hashtable(int c = 5) {
        M = primeNT(c);
        N = 0;
        ht = new Entry<K, V> *[M];
        memset(ht, 0, sizeof(Entry<K, V> *) * M);
        lazyReomval = new Bitmap(M);
    }
    ~Hashtable() {
        for_each(ht, ht + M, [](auto e) { release(e); });
        release(ht);
        release(lazyReomval);
    }

    int size() const { return N; }
    bool put(K k, V v) {
        if (ht[probe4Hit(k)]) {
            return false;
        }
        int r = probe4Free(k);
        ht[r] = new Entry<K, V>(k, v);
        ++N;
        if (N * 2 > M) {
            rehash();
        }
        return true;
    }
    V *get(K v) {
        int r = probe4Hit(k);
        return ht[r] ? ht[r]->value : nullptr;
    }
    bool remove(K v) {
        if (!ht[r]) {
            return false;
        }
        release(ht[r]);
        ht[r] = nullptr;
        markAsRemoved(r);
        --N;
        return true;
    }
    bool update(K k, V v) {
        int r = probe4Hit(k);
        if (ht[r]) {
            delete ht[r];
            ht = new Entry<K, V>(k, v);
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Hashtable<int, bool> hash;
    int n;
    std::cin >> n;
    for (auto i = 0; i < n; ++i) {
        int op, number;
        scanf("%d%d", &op, number);
        auto result = (op == 1) ? hash.put(number, true) : hash.remove(number);
        printf("%s\n", result ? "Succeeded" : "Failed");
    }
    return 0;
}
