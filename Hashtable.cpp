#include <iostream>

const int PRIME[] = {2,      3,      5,       7,      17,    37,
                     79,     163,    331,     667,    1339,  2683,
                     5371,   10747,  21499,   43003,  86011, 172027,
                     344059, 688123, 1376251, 2752507};

template <class K, class V> struct Pair {
    K key;
    V value;
    int removed;
    Pair(K k, V v) : key(k), value(v), removed(0);
};

template <class K, class V> class Hash {
    Hash *_ht;

    int probe4Hit(K const &k) {}

  public:
    Hash() {}
    bool put(K const &k, V const &v) { return true; }
    V get(K const &k) {
        auto r = probe4Hit(k);
        if (_ht[r] != nullptr) {
            return _ht[r]->value;
        }
        return 0;
    }
    bool remove(K const &k) { return false; }
    bool update(K const &k, V const &v) { return true; }
};

int main(int argc, char const *argv[]) {
    Hash<int, int> ht;
    int n;
    for (scanf("%d", &n); n > 0; --n) {
        int e, number;
        scanf("%d%d", &e, &number);
        auto result = (e == 1) ? ht.put(number, 1) : ht.remove(number);
        printf("%s\n", result ? "Succeeded" : "Failed");
    }

    return 0;
}
