#pragma once
#include <iostream>
#include <string>
using std::string;
using namespace std;
#include <limits>
class consoleui
{
private:
    int getIntegerInput()
    {
        int value;
        while (true)
        {
            if (cin >> value)
            {
                return value;
            }
            cout << "Invalid input. Please enter a number:\n";
            cout << "Enter Choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    int mainMenu();
    
    int customerMenu();

    int adminMenu();

    int depositMenu();

    int withdrawMenu();

    int SecureLoginMenu();

    int transferMenu();
};