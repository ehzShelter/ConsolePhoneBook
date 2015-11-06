#include "mobile.h"
#include "userInput.h"

int totalSecond;
bool stop;

void mobile::bill(void)
{
	float tk;
	int sec;
	sec = callTime();
	cout << "you have talked " << sec << " sec" << endl;
	tk = (float)(sec * 10) / 100;
	credit = credit - tk;
	cout << "Your bill is tk. " << tk << endl;
}

void mobile::load(void)
{
	fflush(stdout);

	cout << "\n\n\n\n\n\n \t\t\t\t";
	cout << "Call loading... \n" << endl;
	cout << "\t\t\t\t";
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 0; j <= 19000000; j++){};
        cout << "\033[1;31m..\033[0m";
	}
	cout << " " << endl;

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
	cout << "To cancel call control-c" << endl;

	while (true)
	{
		sleep(1);
		++second;
		++totalSecond;

		signal(SIGINT, [](int sig) { if (sig == SIGINT) { stop = true; } });

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
	setNumber();
	cout << "Calling to: " << getNumber() << endl;
	sleep(2);
	double amount = getCredit();

	if (amount<= 0.0)
	{
		cout << "You don't have sufficient money\n";
		cout << "You have to recharge\n";
		return;
	}
	else
	{
		load();
		bill();
		cout << "Time of call: " << date() << endl;
	}
	addCallHistory(person);
}

void mobile::addCredit(void)
{
    double addCredit;
	cout << "Please give the amount of Money: \n";
	cin >> addCredit;
	if (addCredit > CREDIT_LIMIT)
	{
		cout << "You cannot more than 500tk\n";
	}
	else
	{
        credit += addCredit;
		cout << "Credit " << addCredit << " succesfully added" << endl;
	}
}

double mobile::getCredit(void)
{
	return credit;
}

void mobile::addCallHistory(mobile& client)
{
	callHistory.push_back(client);
}

void mobile::viewHistory(void)
{
    if (callHistory.empty())
    {
        cout << "No history to show\n";
    }
    else
    {
        for (it = callHistory.begin(); it != callHistory.end(); ++it)
        {
            cout << "Number called: " << it->getNumber()
                << " Credit: " << it->getCredit()
                << " time of call: " << it->date() << endl;
        }
    }
}
