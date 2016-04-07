#ifndef _RESIZABLE_ARRAY_
#define _RESIZABLE_ARRAY_

template <typename T>
class ResizableArray {
private:
    T *array;
    unsigned int _capacity;
    unsigned int _size;
public: 
    // Constructor default
    ResizableArray() {
        _size = 0;
        _capacity = 1;
        array = new T[_capacity];
    }

    // Constructor
    ResizableArray(const unsigned int capacity) {
        _capacity = capacity;
        _size = 0;
        array = new T[capacity];
    }

    // Copy-constructor
    ResizableArray(const ResizableArray &other) {
        if (other.size() > 0) {
            _capacity = other.capacity();
            _size = other.size(); 
            array = new T[_capacity];

            for (unsigned int i = 0; i < other.size(); ++i) {
                array[i] = other.array[i];
            }
        }
    }

    // Copy assignement operator
    ResizableArray &operator=(const ResizableArray &other) {
        if (this != &other) {
            _size = other.size();
            _capacity = other.capacity();
            T *tmp = new T[other.capacity()];

            for (int i = 0; i < other.size(); ++i) {
                tmp[i] = other.array[i];
            }

            delete[] array;
            array = tmp;
        }

        return *this;
    }

    // Destructor
    ~ResizableArray() {
        delete[] array;
    }

    // Getter pentru size
    unsigned int size() const;

    // Getter pentru capacity
    unsigned int capacity() const;

    // Metoda care adauga un element nou
    void push_back(const T something);

    // Metoda pentru "Subscripting operator" 
    T &operator[](int position);

    // Metoda pentru a elimina elementul aflat la pozitia "position"
    void erase(const int position);

    // Metoda care returneaza primul indice pe care se afla un element cu
    // valoarea "value" si returneaza -1 daca elementul cautat nu se afla in
    // array
    int find(T value);
};

template <typename T>
unsigned int ResizableArray<T>::size() const{
    return _size;
}

template <typename T>
unsigned int ResizableArray<T>::capacity() const{
    return _capacity;
}

template <typename T>
void ResizableArray<T>::push_back(const T something) {
    // Verifica daca vectorul e plin
    if (_size == _capacity) {
        // Aloc un vector nou de demensiune 2 * capacity
        T *tmp = new T[_capacity << 1];

        // Copiez elementele in vectorul nou
        for (int i = 0; i < _size; ++i) {
            tmp[i] = array[i];
        }

        delete[] array;

        // Adaug elementul nou la finalul vectorului
        array = tmp;

        // Dublez capacitatea vectorului
        _capacity <<= 1;
    }

    array[_size++] = something;
}

template <typename T>
T& ResizableArray<T>::operator[](int position) {
    if (position > _size) {
        fprintf(stderr, "Pozitie invalida!\n");
        return array[0];
    }

    return array[position];
}

template < typename T>
void ResizableArray<T>::erase(const int position) {
    if (position >= _size || _size == 0) {
        return;
    }

    // Daca voi avea mai putin de jumatate de vector nefolosit, ii
    // injumatatesc capacitatea
    if (_size - 1 == _capacity >> 1) {
        T *tmp = new T[_capacity >> 1];

        for (int i = 0; i < position; ++i) {
            tmp[i] = array[i];
        }
        for (int i = position; i < _size; ++i) {
            tmp[i] = array[i + 1];
        }

        delete[] array;

        _size--;
        array = tmp;
        _capacity >>= 1;
    } else {
        for (int i = position; i < _size; ++i) {
            array[i] = array[i + 1];
            _size--;
        }
    }
    
    return;
}

template <typename T>
int ResizableArray<T>::find(T value) {
    for (unsigned int i = 0; i < _size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

#endif