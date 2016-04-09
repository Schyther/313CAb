#pragma once

#define MOD 100003
#define BASE 1867

template <typename Tkey, typename Tvalue>
struct Pair {
    Tkey first;
    Tvalue second;
};

template <typename Tkey, typename Tvalue>
class HashGen {
private:
    ResizableArray < Pair < Tkey, Tvalue > > *H;
    int Hmax;
public:
    // Constructor default
    HashGen() {
    }

    // Constructor
    HashGen(int Hmax);

    // Destructor
    ~HashGen();

    // Ridicare la putere in timp logaritmic. Returneaza (base^exponent) % MOD
    int logPow(int base, int exponent);
    int hashFunction(Tkey key);
    void insert(Tkey key, Tvalue value);

    Tvalue getValue(Tkey key); 

    // Metoda pentru a supaincarca "Subscripting operator" 
    ResizableArray < Pair < Tkey, Tvalue > > &operator[](int position);
};

// Constructor
template <typename Tkey, typename Tvalue>
HashGen < Tkey, Tvalue >::HashGen(int Hmax) {
    this->Hmax = Hmax;
    H = new ResizableArray < Pair < Tkey, Tvalue > > [Hmax];
}

// Destructor
template <typename Tkey, typename Tvalue>
HashGen < Tkey, Tvalue >::~HashGen() {
    delete[] H;
}

template <typename Tkey, typename Tvalue>
int HashGen < Tkey, Tvalue >::logPow(int base, int exponent) {
    int res = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            res = (1LL * res * base) % MOD;
        }

        base = (1LL * base * base) % MOD;
        exponent >>= 1;
    }
    return res;
}

template <typename Tkey, typename Tvalue>
int HashGen < Tkey, Tvalue >::hashFunction(Tkey key) {
    int sum = 0, sz = key.size();
    for (int i = 0; i < sz; ++i) {
        sum = (sum + (logPow(BASE, sz - i - 1) * (int)(key[i])) % MOD) % MOD;
    }
    return sum;
}

template <typename Tkey, typename Tvalue>
void HashGen < Tkey, Tvalue >::insert(Tkey key, Tvalue value) {
    Pair < Tkey, Tvalue > data;
    int hashKey = hashFunction(key);

    data.first = key;
    data.second = value;
    H[hashKey].push_back(data);
}

template <typename Tkey, typename Tvalue>
Tvalue HashGen < Tkey, Tvalue >::getValue(Tkey key) {    
    int hashKey = hashFunction(key);
    int sz = H[hashKey].size();

    for (int i = 0; i < sz; ++i) {
        if (H[hashKey][i].first == key) {
            return H[hashKey][i].second;
        }
    }

    return Tvalue(); 
}

template <typename Tkey, typename Tvalue>
ResizableArray < Pair < Tkey, Tvalue > >&  HashGen < Tkey, Tvalue >::operator[](int position) {
    if (position >= Hmax) {
        cerr << "Pozitie invalida!\n";
        return H[0];
    }

    return H[position];
}