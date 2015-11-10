## This is a console PhoneBook programm
## This is built on C++, also featured some C++11 functionality
## Such as Lambda, Regular Expression, Boost Library, OOP
## Moreover STL, MAP, DYNAMIC Vector
## Used file for persistent data(In need of databases too)
## We measure our call duration using single handle Using SIGINT
## We sanitize user value in more robust way
## The Project is deveoped using Clang++ based on LLVM(low-level virtual machine) and Visual Studio 2015
## The Project has no memory-leak check with Valgring(a handy memory debugger)
## Finally, The code is pushed on github, you can check the code and report bugsj
## The Program has two edition >Linux >Windows will run on mac(POSIX) as well
## The program is open-sourced, any good suggestions will be highly appreciated

# NOTE:

To compile in Linux use Makefile, Make sure you are using clang++ 3.6.2 compiler
or g++ 4.9 and
other defendencies

>> Just run

    make


To clear the object files, run

    make clean

To compile in Windows, Make sure you compiler must support ISO C++11 Standard

>> Github URL is given below


    https://github.com/ehzShelter/ConsolePhoneBook

>> For Windows just used windows.h, for linux used unistd.h


>> We will introduce the header aka functions prototypes only

## Project in Progress(RC editions)

Lines       Words        Bytes       Modules

   28        51           495         Phone.h

   45        88           816         mobile.h

   33        62           613         person.h

   47        86           904         userInput.h

   85       243          1798         Phone.cpp

   62       227          1783         main.cpp

  214       571          4153         mobile.cpp

   98       234          2045         person.cpp

   88       171          1681         userInput.cpp

..............................................

  700      1733          14288 total

## Programm main function has 13(thirteen) different cases for
###    different purposes

 This is actually a part of a main program

>	case 1: client.callPerson(client,1); break;

>	case 2: phoneRecord.addNewContact(phoneRecord); break;

>	case 3: phoneRecord.findAndChange(); break;

>	case 4: phoneRecord.eraseEntireBook(); break;

>	case 5: client.addCredit(); break;

>	case 6: cout << "Your credit: " << client.getCredit() << " tk"; break;

>	case 7: client.viewHistory(); break;

>   case 8: human.registerPerson(human); break;

>   case 9: client.callbyName(client); break;

>   case 10: human.cost(); break;

>   case 11: human.averageCallLength(); break;

>   case 12: human.totalCredit(); break;

>   case 13: client.favorite(); break;

>	case 0: break;

>	default: phoneRecord.printException(); break;


## We have designed our programm in four classes
# One extra class we have used, which is used for INHERITENCE(Single Inheritence)
# The one base class named Input

## Base Class
>
>    class Input

>    {

>    protected:

>        static int totalSecond;

>        static int numberOfCalls;

>        string name;

>        string number;

>        string email;

>        string address;

>        string city;

>        string state;

>        string zipCode;

>        string phoneModel;

>

>    public:

>        bool validate(const string&, const string&);

>        string inputData(const string&,const string&);
>
>        void setName(void);

>        string getName(void);

>        void setNumber(void);

>        string getNumber(void);

>        void setEmail(void);

>        string getEmail(void);

>        void setCity(void);

>        string getCity(void);

>        void setState(void);

>        string getState(void);

>        void setZipCode(void);

>        string getZipCode(void);

>        void setPhoneModel(void);

>        string getPhoneModel(void);

>    };


## Running in Linux

![Running Programm](https://github.com/ehzShelter/ConsolePhoneBook/blob/master/running_program.png)

![History](https://github.com/ehzShelter/ConsolePhoneBook/blob/master/history.png)

![Memory Management](https://github.com/ehzShelter/ConsolePhoneBook/blob/master/no_memoryLeak.png)

## Class one
>    class mobile : public Input

>    {

>    private:

>        string dt;

>        double credit = 200.00;

>        vector< mobile >callHistory;

>        vector< mobile >contact;

>        vector< mobile >::iterator it;

>        map<string, int> m;

>        vector<string> a;

>
>    public:

>        void load(void);

>        void bill(void);

>        string date(void);

>        int callTime(void);

>        void callPerson(mobile&, int);

>        void addCredit(void);

>        double getCredit(void);

>        void addCallHistory(mobile&);

>        void viewHistory(void);

>        void fileRW(mobile&);

>        void callbyName(mobile&);

>        void favorite(void);

>    };


## Class Two
>    class Phone : public Input

>    {

>    private:

>        vector< Phone >object;

>        vector< Phone >::iterator it;

>
>    public:

>        void findAndChange(void);

>        void callbyName(void);

>        void eraseEntireBook(void);

>        void addNewContact(Phone&);

>        void printException(void);

>        void fileRW(string &);

>    };


## Class Three

>    class person : public Input

>    {

>        friend bool registerOnDemand(person &);

>    private:

>        vector< person >object;

>        vector< person >::iterator it;

>        string sim;

>        static int credit;

>
>    public:

>        void registerPerson(person &);

>        void setNewSim(void);

>        string getSim(void);

>        void exceptionhandle(void);

>        void cost(void);

>        void averageCallLength(void);

>        void totalCredit(void);

>    };

Documentation:

To match user input, we have used regex_match("String", "Matching pattern) which is under <regex> header
Most of the time, we have used object reference to wor kthe programm perfectly

## Windows Screenshoot
>Fancy

![Windows](https://github.com/ehzShelter/ConsolePhoneBook/blob/master/VisualStudio.png)


## Any query, email me, mechezawad@outlook.com, for bugs, create issues in Github

