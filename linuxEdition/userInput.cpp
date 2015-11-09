#include "userInput.h"

bool Input::validate(const string &data, const string &expression)
{
    regex validationExpression = regex(expression);
    return regex_match(data, validationExpression);
}

string Input::inputData(const string &fieldName, const string &expression)
{
    string data;

    cout << "Enter " << fieldName << ": ";
    cin >> data;

    // validate the data
    while ( !(validate(data, expression)))
    {
        cout << "Invalid " << fieldName << ".\n";
        cout << "Enter " << fieldName << ": ";

        cin >> data;
    }
    return data;
}

void Input::setName(void)
{
    this->name = inputData("name", "[A-Z][a-zA-Z]*");
}
string Input::getName(void)
{
    return name;
}

void Input::setNumber(void)
{
    this->number = inputData("number", "0\\d{8,10}");
}
string Input::getNumber(void)
{
    return number;
}

void Input::setEmail(void)
{
    this->email = inputData("email", "^(?!.*\\.{2})[\\w-]+(\\.[\\w-]i+)*@[\\w]+(\\.[\\w]+)*(\\.[a-z]{1,9})");
}
string Input::getEmail(void)
{
    return email;
}

void Input::setCity(void)
{
    this->city = inputData("city", "([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");
}
string Input::getCity(void)
{
    return city;
}

void Input::setState(void)
{
    this->state = inputData("state", "([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)");
}
string Input::getState(void)
{
    return state;
}

void Input::setZipCode(void)
{
    this->zipCode = inputData("zipCode", "\\d{4}");
}
string Input::getZipCode(void)
{
    return zipCode;
}

void Input::setPhoneModel(void)
{
    this->phoneModel = inputData("phoneModel", "(^[a-zA-Z][a-zA-Z\\.\\+\\-\\'\\d\\s]*)");
}
string Input::getPhoneModel(void)
{
    return phoneModel;
}
