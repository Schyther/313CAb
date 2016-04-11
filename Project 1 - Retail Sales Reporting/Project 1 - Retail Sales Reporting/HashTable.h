#define MOD 100003
#define BASE 1867

// Hash pentru bonuri

template <typename Tkey, typename Tvalue>
struct Pair {
	Tkey first;
	Tvalue second;
};

template <typename Tkey, typename Tvalue>
class Hash {
private:
	ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > > *H;
	int Hmax;
public:
	// Constructor default
	Hash() {
	}

	// Constructor
	Hash(int Hmax);

	// Destructor
	~Hash();

	// Ridicare la putere in timp logaritmic. Returneaza (base^exponent) % MOD
	int logPow(int base, int exponent);
	int hashFunction(Tkey key);
	void insert(Tkey key, Tvalue value);

	// Metoda care returneaza continutul pentru cheia "key"
	ResizableArray < Tvalue > getValue(Tkey key);

	// Metoda pentru a supaincarca "Subscripting operator" 
	ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > > &operator[](int position);
};

// Constructor
template <typename Tkey, typename Tvalue>
Hash < Tkey, Tvalue >::Hash(int Hmax) {
	this->Hmax = Hmax;
	H = new ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > >[Hmax];
}

// Destructor
template <typename Tkey, typename Tvalue>
Hash < Tkey, Tvalue >::~Hash() {
	delete[] H;
}

template <typename Tkey, typename Tvalue>
int Hash < Tkey, Tvalue >::logPow(int base, int exponent) {
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
int Hash < Tkey, Tvalue >::hashFunction(Tkey key) {
	int sum = 0, sz = key.size();
	for (int i = 0; i < sz; ++i) {
		sum = (sum + (logPow(BASE, sz - i - 1) * (int)(key[i])) % MOD) % MOD;
	}
	return sum;
}

template <typename Tkey, typename Tvalue>
void Hash < Tkey, Tvalue >::insert(Tkey key, Tvalue value) {
	Pair < Tkey, ResizableArray < Tvalue > > data;

	int hashKey = hashFunction(key);
	int ok = 0;

	if (H[hashKey].size() > 0) {
		int sz = H[hashKey].size();
		for (int i = 0; i < sz && !ok; ++i) {
			if (H[hashKey][i].first == key) {
				H[hashKey][i].second.push_back(value);
				return;
			}
		}
	}

	data.first = key;
	data.second.push_back(value);
	H[hashKey].push_back(data);
}

template <typename Tkey, typename Tvalue>
ResizableArray < Tvalue > Hash < Tkey, Tvalue >::getValue(Tkey key) {
	int hashKey = hashFunction(key);
	int sz = H[hashKey].size();

	for (int i = 0; i < sz; ++i) {
		if (H[hashKey][i].first == key) {
			return H[hashKey][i].second;
		}
	}

	return ResizableArray < Tvalue >();
}

template <typename Tkey, typename Tvalue>
ResizableArray < Pair < Tkey, ResizableArray < Tvalue > > >&  Hash < Tkey, Tvalue >::operator[](int position) {
	if (position >= Hmax) {
		cerr << "Pozitie invalida!\n";
		return H[0];
	}

	return H[position];
}


// Hash generic

template <typename Tkey, typename Tvalue>
class HashGen {
private:
	ResizableArray < Pair < Tkey, Tvalue > > *H;
	int Hmax;
public:
	// Constructor
	HashGen(int Hmax) {
		this->Hmax = Hmax;
		H = new ResizableArray < Pair < Tkey, Tvalue > >[Hmax];
	}

	// Destructor
	~HashGen() {
		delete[] H;
	}


	int logPow(int base, int exponent) {
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

	int hashFunction(Tkey key) {
		int sum = 0, sz = key.size();
		for (int i = 0; i < sz; ++i) {
			sum = (sum + (logPow(BASE, sz - i - 1) * (int)(key[i])) % MOD) % MOD;
		}
		return sum;
	}

	void insert(Tkey key, Tvalue value) {
		Pair < Tkey, Tvalue > data;
		int hashKey = hashFunction(key);

		data.first = key;
		data.second = value;
		H[hashKey].push_back(data);
	}

	Tvalue getValue(Tkey key) {
		int hashKey = hashFunction(key);
		int sz = H[hashKey].size();

		for (int i = 0; i < sz; ++i) {
			if (H[hashKey][i].first == key) {
				return H[hashKey][i].second;
			}
		}

		return Tvalue();
	}

	ResizableArray<Tvalue> operator[](int position) {
		if (position >= Hmax) {
			cerr << "Pozitie invalida!\n";
			return H[0];
		}

		return H[position];
	}
};
