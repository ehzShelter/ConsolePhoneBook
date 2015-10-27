#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <regex>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Input
{
protected:
    string name;
    string number;

public:
    bool validate(const string&, const string&);
    string inputData(const string&,const string&);
    void setName(void);
    void setNumber(void);
    string getName(void);
    string getNumber(void);
};

#endif
