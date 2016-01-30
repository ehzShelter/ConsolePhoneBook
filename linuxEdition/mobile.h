#ifndef FIRST_H
#define FIRST_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <unistd.h>
#include <signal.h>
#include <vector>
#include <map>
#include "userInput.h"

using namespace std;

#define CREDIT_LIMIT 500.00

class mobile : public Input {
private:
    string dt;
    double credit = 200.00;
    vector<mobile> callHistory;
    vector<mobile> contact;
    vector<mobile> message;
    vector<mobile>::iterator it;
    map<string, int> myMap;
    vector<string> numberKey;

public:
    void load(void);
    void bill(void);
    string date(void);
    int callTime(void);
    void callPerson(mobile&, int);
    void addCredit(void);
    double getCredit(void);
    void addCallHistory(mobile&);
    void viewHistory(void);
    void fileRW(mobile&);
    void callbyName(mobile&);
    void favorite(void);
    void sendText(mobile&);
};

#endif
