#include "mobile.h"
#include "Phone.h"
#include "userInput.h"
#include <vector>
#include <limits.h>

int main(void)
{
	mobile client;
	Phone phoneRecord;

    int choice;
	cout << "Please press desired key to continue ... \n\n ";

	do
	{
		cout << "\nMENU\n\n"
			<< " 1 : for phone call\n"
			<< " 2 : add new contact\n"
			<< " 3 : find and change name\n"
			<< " 4 : Caution! Delete entire Phonebook\n"
			<< " 5 : Want to add credit\n"
			<< " 6 : Want to know your credit\n"
			<< " 7 : History\n"
			<< " 0 or character or string to quit the programm\n\n";

		cout << "Command: ";
		cin >> choice;
        cin.ignore(INT_MAX,'\n');

		switch (choice)
		{
			case 1: client.callPerson(client); break;
			case 2: phoneRecord.addNewContact(phoneRecord); break;
			case 3: phoneRecord.findAndChange(); break;
			case 4: phoneRecord.eraseEntireBook(); break;
			case 5: client.addCredit(); break;
			case 6: cout << "Your credit: " << client.getCredit() << " tk"; break;
			case 7: client.viewHistory(); break;
			default: phoneRecord.printException(); break;
			case 0: break;
		}
	}
	while (choice != 0);

	return 0;
}
