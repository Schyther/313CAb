#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#include "DLL.h"

using namespace std;

int main()
{
	DLL<int> l;
	cout << l.empty() << "\n";
	l.push_back(3);
	cout << l.front() << "\n";
	l.erase(0);
	l.push_back(4);
	l.push_front(2);
	l.erase(1);
	l.insert(0, 3);
	cout << l.empty() << "\n";
	cout << l;
	cout << l.back() << "\n";
	DLL<int> l2(l); //copy-constructor
	cout << l2;
	cout << l.getPos(3) << "\n";
	l.push_front(2);
	l.push_back(4);
	cout << l;
	l.pop_front();
	l.pop_back();
	cout << l;
	cout << "size " << l.length()<< "\n";
	l.push_front(2);
	l.push_back(4);
	DLL<int> l3;
	l3 = l; //copy-assignment
	l.pop_front();
	cout << l;
	l3.remove(3);
	cout << l3;
	cout << l.first()<< "\n";
	l.remove_next(l.first());
	cout << l;
	return 0;
}