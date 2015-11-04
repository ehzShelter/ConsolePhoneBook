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
    cin.ignore(INT_MAX, '\n');
    getline(cin, data);

    // validate the data
    while ( !(validate(data, expression)))
    {
        cout << "Invalid " << fieldName << ".\n";
        cout << "Enter " << fieldName << ": ";

        cin.clear();
        getline(cin, data);
    }
    return data;
}

void Input::setName(void)
{
    string userName;
    cout << "Enter Name: ";
    cin >> userName;
    this->name = userName;
}

void Input::setNumber(void)
{
    this->number = inputData("number", "0\\d{8,10}");
}

string Input::getName(void)
{
    return name;
}

string Input::getNumber(void)
{
    return number;
}
