#ifndef INPUT_H
#define INPUT_H

#define CALLRATE .9

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits.h>
#include <regex>
using namespace std;

class Input {
protected:
    static int totalSecond;
    static int numberOfCalls;
    string name;
    string number;
    string email;
    string address;
    string city;
    string state;
    string zipCode;
    string phoneModel;
    string choice;
    string text;
    string Amount;

public:
    bool validate(const string&, const string&);
    string inputData(const string&, const string&);

    void setName(void);
    string getName(void);
    void setNumber(void);
    string getNumber(void);
    void setEmail(void);
    string getEmail(void);
    void setCity(void);
    string getCity(void);
    void setState(void);
    string getState(void);
    void setZipCode(void);
    string getZipCode(void);
    void setPhoneModel(void);
    string getPhoneModel(void);
    void setChoice(void);
    int getChoice(void);
    void setAmount(void);
    int getAmount(void);
    void setText(void);
    string getText(void);
};

#endif
