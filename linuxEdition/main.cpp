#include "mobile.h"
#include "Phone.h"
#include "person.h"
#include "userInput.h"

int main(void)
{
	mobile client;
	Phone phoneRecord;
    person human;

    client.fileRW(client);
    Input data;

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
            << " 8 : Register new Person\n"
            << " 9 : call by name\n"
            << " 10: text messaging\n"
        	<< " 11: total cost of last month\n"
            << " 12: Average length of call\n"
            << " 13: TotalCredit\n"
            << " 14: Favorite\n"
			<< " 0 or any char || string : quit\n\n";

        data.setChoice();
        choice = data.getChoice();
		switch (choice)
		{
			case 1: client.callPerson(client,1); break;
			case 2: phoneRecord.addNewContact(phoneRecord); break;
			case 3: phoneRecord.findAndChange(); break;
			case 4: phoneRecord.eraseEntireBook(); break;
			case 5: client.addCredit(); break;
			case 6: cout << "Your credit: " << client.getCredit() << " tk"; break;
			case 7: client.viewHistory(); break;
            case 8: human.registerPerson(human); break;
            case 9: client.callbyName(client); break;
            case 10: client.sendText(client); break;
            case 11: human.cost(); break;
            case 12: human.averageCallLength(); break;
            case 13: human.totalCredit(); break;
            case 14: client.favorite(); break;
			case 0: break;
			default: phoneRecord.printException(); break;
		}
	}
	while (choice != 0);

	return 0;
}
