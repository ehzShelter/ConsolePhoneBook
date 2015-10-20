#include <iostream>
#include <string>
#include <Windows.h>

#include "firstClass.h"

using namespace std;

int main(void)
{
	mobile client;

	char choice;
	cout << "Please press desired key to continue ... \n\n ";

	do
	{
		cout << "\nMENU\n\n"
			<< " 1 : for phone call\n"		
			<< " q : quit\n\n";

		cout << "Command: ";
		cin >> choice;

		switch (choice)
		{
			case '1': client.callPerson(client) ; break;	
			case 'q': break;

			default:
			{				
				system("cls");
				cout << "you didn't press expected key :(" << endl;
				cout << "\a ";
			}
		}
	} 
	while (choice != 'q');

	return 0;
}