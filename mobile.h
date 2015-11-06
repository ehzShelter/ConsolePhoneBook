#ifndef FIRST_H
#define FIRST_H

#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <unistd.h>
#include <signal.h>
#include <vector>

#include "userInput.h"

#define CREDIT_LIMIT 500.00

using namespace std;

class mobile : public Input
{
private:
	double credit = 20.00;
	vector< mobile >callHistory;
	vector< mobile >::iterator it;

public:
	void load(void);
	void bill(void);
	string date(void);
	int callTime(void);
	void callPerson(mobile&);
	void addCredit(void);
	double getCredit(void);
	void addCallHistory(mobile&);
	void viewHistory(void);
};

#endif
