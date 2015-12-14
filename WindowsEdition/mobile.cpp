#include "mobile.h"
#include "userInput.h"
#define TEXTLIMIT 100


// Stops the call time
bool stop;

// Calculates bill
void mobile::bill(void)
{
	double tk;
	int sec;
	sec = callTime();
	cout << "you have talked " << sec << " sec" << endl;
	tk = (float)sec * CALLRATE;
	credit = credit - tk;
	cout << "Your bill is tk. " << tk << endl;
}

// Call loading situation
void mobile::load(void)
{
	cout << "*\n*\n*" << endl;
	cout << "*********" << endl;
	for (int i = 0; i<10; i++)
	{
		if (i == 4)
		{
			cout << "********* \t" << endl;
		}
		else if (i == 5 || i == 7 || i == 9)
		{
			cout << "* " << (char)219 << " " << (char)219 << " " << (char)219 << " *" << endl;
		}
		else
			cout << "*       *" << endl;
	}
	cout << "*********" << endl;
	Sleep(2000);
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

	system("color 06");

}

// Show call time from system
string mobile::date(void)
{
	time_t now = time(0);
	dt = ctime(&now);
	return dt;
}

// this function calculate user exact time
int mobile::callTime(void)
{
	int second = 0;
	cout << "To cancel call control-c" << endl;

	while (true)
	{
		// Sleep pauses execution
		// Sleep takes parameter as microseconds
		Sleep(1000);
		++second;
		++totalSecond;
		// lamda function C++11 
		// Lamda function has no function name
		// Anonymous function, which literally can invoke function in the parameter
		// which reduants extra function call
		// SIGINT equivalent CTRL-C as parameter
		// which waits until user press control-c to stop
		// This is like a stop watch which literally calculate exact time
		signal(SIGINT, [](int sig) { if (sig == SIGINT) { stop = true; } });

		if (stop == true)
		{
			stop = false;
			break;
		}
	}
	return second;
}

// Call to the person
void mobile::callPerson(mobile& person, int choice)
{
    if (choice == 1)
    {
        setNumber();
    }
    if (getName().empty() && choice == 9)
    {
        setNumber();
    }
    cout << "Calling to: " << getNumber() << endl;
	Sleep(2000);
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
    ++numberOfCalls;
}

void mobile::addCredit(void)
{
	Input addCredit;
	cout << "Please give the amount of Money: \n";
	addCredit.setAmount();
	int Recharge = addCredit.getAmount();

	if (Recharge > CREDIT_LIMIT | Recharge <= 0)
	{
		cout << "Invalid Amount\n";
	}
	else
	{
		credit += Recharge;
		cout << "Credit " << Recharge << " succesfully added" << endl;
	}
}

double mobile::getCredit(void)
{
	return credit;
}

void mobile::addCallHistory(mobile& client)
{
	callHistory.push_back(client);
    ofstream outputHistoryFile("history.txt", ios::app);

    if (!outputHistoryFile)
    {
        cerr << "File could not be opened" << endl;
        return;
    }

    outputHistoryFile << "Number called: " << getNumber() << endl
            << "Time of call: " << dt << endl;
}

void mobile::viewHistory(void)
{
    if (callHistory.empty())
    {
        cout << "No history to show\n";
    }
    else
    {
        for (auto it = callHistory.begin(); it != callHistory.end(); ++it)
        {
            cout << "Number called: " << it->getNumber() << endl
                << "Time of call: " << it->dt << endl;
        }
    }
}

void mobile::callbyName(mobile& Human)
{
    string nameParam;
    cout << "Please give the name which you want to call: ";
    cin >> nameParam;

    for (auto it = contact.begin(); it != contact.end(); ++it)
    {
        if (it->getName() == nameParam)
        {
            it->callPerson(Human, 9);
            return;
        }
    }
    if (it == contact.end())
    {
        cout << "number not found!!" << endl;
    }
}

void mobile::sendText(mobile& Human)
{
	Human.setName();
	cout << "Please enter your text to send\n" << endl;
	Human.setText();

	string text = Human.getText();

	ofstream mySMS;
	mySMS.open("sms.txt", ios::out | ios::binary | ios::app);
	string name = Human.getName();
	mySMS << name << " - " << text << endl;
	mySMS.close();

	if (text.length() > TEXTLIMIT)
	{
		int size = text.length() / TEXTLIMIT;
		int i = 0;

		vector<string> tokens; // Create vector to hold our words
		while (i <= size)
		{
			string buf = text.substr(i * TEXTLIMIT, TEXTLIMIT); // Have a buffer string
			tokens.push_back(buf);
			i++;
		}

		int k = 1;
		cout << endl;
		for (const auto j : tokens)
		{
			cout << "Thread: " << k << endl;
			cout << j << endl;
			k++;
		}

		cout << "\n\n\n MULTI-threaded TextMEssage sent !!!\n";
	}
	else
	{
		cout << text;
		cout << "\n\n\nTextMEssage sent !!!\n";
	}

	
}


void mobile::fileRW(mobile& receiver)
{
    ifstream file("contact.txt", ios::in | ios::out | ios::app);
    if (!file)
    {
        cerr << "File could not be opened\n";
        return;
    }

    while(file >> receiver.name >> receiver.number)
    {
         contact.push_back(receiver);
    }
}

void mobile::favorite(void)
{
    // range-based loop, modern c++11 feature
    for (auto& it:callHistory)
    {
         numberKey.push_back(it.getNumber());
    }

    if (numberKey.size() == 0)
    {
         cout << "You have No favourite numberKey" << endl;
         return;
    }
    // count occurrences of every string
    for (auto i = 0; i < numberKey.size(); i++)
    {
         auto it = myMap.find(numberKey[i]);

		 // Inserting elements as key-value pairs
         if (it == myMap.end())
         {
             myMap.insert(pair<string, int>(numberKey[i], 1));
         }
         else
         {
             myMap[numberKey[i]] += 1;
         }
    }

    // find the max by traversing the associative array pair class
    auto stationary = myMap.begin();
    for (auto moving = myMap.begin(); moving != myMap.end(); ++moving)
    {
        if (moving->second > stationary->second)
        {
            stationary = moving;
        }
    }
    cout << "Your Favourite number: " << stationary-> first << endl;
    myMap.clear();
    numberKey.clear();
}
