template < typename T >
T Min(T val1, T val2) {
    return val1 < val2 ? val1 : val2;
}

template < typename T >
T Max(T val1, T val2) {
    return val1 > val2 ? val1  : val2;
}

template <typename T1, typename T2, typename T3>
struct Bon {
    T1 idMag;
    T2 idBon;
    T3 timestamp;

    bool operator<(const Bon <T1, T2, T3> &other) {
        if (this->idMag < other.idMag) {
            return true;
        } else if (this->idMag == other.idMag && this->timestamp < other.timestamp) {
            return true;
        }

        return false;
    }
};

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

};


//double node
template<class T>
struct Node{
    T value;
    Node<T> *next, *prev;
    Node(T value) {
        this->value = value;
        next = NULL;
        prev = NULL;
    }
    Node() {
        next = NULL;
        prev = NULL;
    }
};

//simple node
template<class T>
struct sNode{
    T value;
    sNode<T> *next;
    sNode(T value) {
        this->value = value;
        next = NULL;
    }
    sNode() {
        next = NULL;
    }
};