#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<iostream>
#include<ctime>
#include<cstring>

using namespace std;

time_t convertTime(char *timeToConvert)	{
	struct tm newTime = { 0 };
	char *dates[7];
	char *p;
	int nr = 0;

	timeToConvert[strlen(timeToConvert)] = '\0';
	p = strtok(timeToConvert, "- : ");
	while (p != NULL) {
		dates[nr++] = p;
		p = strtok(NULL, "- : ");
	}

	newTime.tm_year = atoi(dates[0]) - 1900;
	newTime.tm_mon = atoi(dates[1]) - 1;
	newTime.tm_mday = atoi(dates[2]);
	newTime.tm_hour = atoi(dates[3]);
	newTime.tm_min = atoi(dates[4]);
	newTime.tm_sec = atoi(dates[5]);

	time_t temp = mktime(&newTime);
	

	return temp;
}



int main() {
	
	
	//test
	char *time = new char[30];
	cin.getline(time, 30);
	cout << time << endl;
	cout << convertTime(time) << endl;
	//test

	return 0;
}