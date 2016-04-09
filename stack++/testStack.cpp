#ifndef __IOSTREAM__
#define __IOSTREAM__
#include <iostream>
#endif

#include "DLL.h"
#include "stack.h"

int main() {
	Stack<int> s;
	cout << s.empty() << "\n";
	cout << s.top() << "\n";
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(3);
	cout << s;
	s.pop();
	cout << s;
	cout << s.empty() << "\n";
	cout << s.size() << "\n";
	cout << s.top() << "\n";
	Stack<int> s2;
	s2 = s;
	cout << s2;
	Stack<int> s3 = s2;
	cout << s3;

	return 0;
}