#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#include "resizablearray.h"

int main() {
    // Am folosit std::vector doar pentru testare, stiu ca nu avem voie sa-l
    // folosim la proiect.
    /*ResizableArray < vector<int> > a;
    vector < int > x; 
    x.push_back(3);
    x.push_back(3);
    x.push_back(3);
    a.push_back(x);
    cout << a[0][0] << '\n';
    cout << a.size() << ' ' << a.capacity() << '\n';
    vector < int > y; 
    y.push_back(4);
    y.push_back(4);
    y.push_back(4);
    a.push_back(y);
    cout << a[1][0] << '\n';
    cout << a.size() << ' ' << a.capacity() << '\n';
    a.push_back(y);
    cout << a.size() << ' ' << a.capacity() << '\n';
    vector <int> aux;
    aux.push_back(6);
    aux.push_back(7);
    aux.push_back(8);
    a[1] = aux;
    cout << a[1][0] << '\n';
    cout << a[1][1] << '\n';

    a.erase(1);
    cout << a.size() << ' ' << a.capacity() << '\n';

    vector < int > s2;
    cout << a.find(s2) << '\n';

    cout << a.size() << ' ' << a.capacity() << '\n';
    a.pop_back();
    cout << a.size() << ' ' << a.capacity() << '\n';

    a.push_back(x);
    a.push_back(x);
    a.push_back(x);
    a.push_back(x);

    cout << a.size() << ' ' << a.capacity() << '\n';
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();

    cout << a.size() << ' ' << a.capacity() << '\n';*/

    ResizableArray < int > a;
    a.push_back(6);
    a.push_back(1);
    a.push_back(2);
    a.push_back(5);
    a.push_back(0);
    a.push_back(10);

    a.QuickSort(0, a.size() - 1);

    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    } cout << '\n';

    cout << a.binarySearch(5) << '\n';
    return 0;  
}