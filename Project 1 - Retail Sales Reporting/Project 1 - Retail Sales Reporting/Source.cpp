#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;


int main() {
	
	string s;

	ifstream f("bonuri.csv");


	getline(f, s, ',');
	
	cout << s <<'\n';

	

	return 0;
}