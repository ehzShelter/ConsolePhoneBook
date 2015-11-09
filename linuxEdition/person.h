#pragma once

#ifndef THIRD_H
#define THIRD_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "userInput.h"
using namespace std;

class person : public Input
{
    friend bool registerOnDemand(person &);
private:
	vector< person >object;
	vector< person >::iterator it;
    string sim;
    static int credit;

public:
	void registerPerson(person &);
    void setNewSim(void);
    string getSim(void);
	void exceptionhandle(void);
    void cost(void);
    void averageCallLength(void);
    void totalCredit(void);
};

#endif
