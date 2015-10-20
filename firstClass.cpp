#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <signal.h>

#include "firstClass.h"

int totalSecond;
bool stop;

using namespace std;

string mobile::number(void)
{
	cout << "Enter your number: " << endl;
	cin >> Number;
	return Number;
}

void mobile::load(void)
{
	system("cls");
	system("color 0C");

	cout << "\n\n\n\n\n\n \t\t\t\t";
	cout << "Call loading... \n" << endl;
	cout << "\t\t\t\t";
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 0; j <= 19000000; j++);
		cout << (char)177;
	}
	cout << " " << endl;

	system("cls");
	system("color 07");
}

float mobile::bill(void)
{
	float tk;
	int sec;
    // sec = rand() % 500 + 5;
    sec = callTime();
	cout << "you have talked " << sec << " sec" << endl;
	tk = (float)(sec * 2) / 100;
	return tk;
}

string mobile::date(void)
{
	time_t now = time(0);
	string dt = ctime(&now);
	return dt;
}

int mobile::callTime(void)
{
	int second = 0;
	cout << " to cancel call control-c" << endl;

	while (true)
	{
		Sleep(1000);
		++second;
		++totalSecond;

		signal(SIGINT, [](int sig) { if (sig == SIGINT) { stop = true;}});

		if (stop == true)
		{
			stop = false;
			break;
		}
	}
	return second;
}

void mobile::callPerson(mobile& person)
{
	system("cls");
	cout << "Calling to: " << person.number() << endl;
	Sleep(2000);

	person.load();

	cout << "Your bill is tk. " << person.bill() << endl;
	cout << "Time of call: " << person.date() << endl;
}
