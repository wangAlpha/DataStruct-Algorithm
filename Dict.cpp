#include <iostream>

template <class K, class V> struct Entry {
    K key;
    V value;
    Entry(K k = K(), V v = V()) : key(k), value(v) {}
    Entry(Entry<K, V> const &e) : key(e.k), value(e.v) {}
};

template <class K, class V> class Dict {
    int size() const = 0;
    bool put(K, V) = 0;
    V *get(K k) = 0;
    bool remove(K k) = 0;
};