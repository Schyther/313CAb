template < typename T >
T Min(T val1, T val2) {
    return val1 < val2 ? val1 : val2;
}

template < typename T >
T Max(T val1, T val2) {
    return val1 > val2 ? val1  : val2;
}

template <typename Tkey, typename Tvalue>
struct Pair {
    Tkey first;
    Tvalue second;
    Pair makePair(Tkey val1, Tvalue val2) {
        this->first = val1;
        this->second = val2;
        return *this;
    }

    Pair<Tkey, Tvalue> &operator=(const Pair<Tkey, Tvalue> &other) {
        this->first = other.first;
        this->second = other.second;
        return *this;
    }

    // am nevoie sa supraincarc == pentru atunci cand verific daca
    // o pereche de produse e deja in lista cu cele mai bine vandute perechi

    bool operator==(const Pair<Tkey, Tvalue> &other) const {
        if ( (this->first == other.first) && (this->second == other.second) ) {
            return true;
        }
        if ( (this->first == other.second) && (this->second == other.first) ) {
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& out, const Pair<Tkey, Tvalue> &pair) {
        out << pair.first << " " << pair.second;
        return out;
    }
};