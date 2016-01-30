#pragma once
#ifndef SECOND_H
#define SECOND_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "userInput.h"
using namespace std;

class Phone : public Input {
private:
    vector<Phone> object;
    vector<Phone>::iterator it;

public:
    void findAndChange(void);
    void callbyName(void);
    void eraseEntireBook(void);
    void addNewContact(Phone&);
    void printException(void);
    void fileRW(string&);
};

#endif
