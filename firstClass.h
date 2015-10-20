#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "firstClass.h"

using namespace std;

class mobile
{
private:
	string Number;

public:
	string number(void);
	void load(void);
	float bill(void);
	string date(void);
	int callTime(void);
	void callPerson(mobile&);
};
