#include "person.h"
#include "userInput.h"

#define MONTHCOST 400
#define CREDIT 10

int Input::totalSecond;
int Input::numberOfCalls;
int person::credit;

void person::setNewSim(void)
{
    this->sim = inputData("sim", "(^[a-zA-Z][a-zA-Z\\s]*)");
}

string person::getSim(void)
{
    return sim;
}

bool registerOnDemand(person& buddy)
{
    buddy.setNewSim();
    return true;
}

void person::registerPerson(person& instance)
{
	setName();
	setNumber();
    setEmail();
    setPhoneModel();
    setCity();
    setState();
    setZipCode();

	object.push_back(instance);

    if (registerOnDemand(instance))
    {
        cout << endl;
        cout << "The person is registered to " << instance.getSim() << " operator"
            << " on " << instance.getPhoneModel() << " SmartPhone\n";
        cout << endl;
    }
    else
    {
        exceptionhandle();
    }

    ofstream addRegisteredFile("registerPerson.txt", ios::app);

    if (!addRegisteredFile)
    {
        cerr << "File could not be opened to append" << endl;
        return;
    }
    else
    {
        addRegisteredFile <<  getName() << setw(30)
            << getEmail() << setw(30) << getPhoneModel() << endl;
        addRegisteredFile << endl;

        credit = credit + CREDIT;

        cout << "New registered person record has been added\n";

    }
}

void person::cost(void)
{
    cout << "Total cost of the previous month " << (totalSecond * CALLRATE) + MONTHCOST << " taka" << endl;
}

void person::averageCallLength(void)
{
    if (numberOfCalls <= 0)
    {
        cout << "No call has been made in this session\n";
        return;
    }
    else
    {
        cout << "average call length "
         << totalSecond / numberOfCalls << " seconds" << endl;
    }
}

void person::exceptionhandle(void)
{
	cout << "Something went wrong :(" << endl;
}

void person::totalCredit(void)
{
    cout << "Total Credit to all registered phone " << credit << " Taka" << endl;
}
