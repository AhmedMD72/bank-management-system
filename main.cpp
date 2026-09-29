#include <iostream>
#include "include/consoleui.h"
#include "include/operationuser.h"
using namespace std;

int main()
{
    consoleui user;
    operationuser operation;
    cout << "=======================================" << endl;
    cout << "=======================================" << endl;
    cout << "BANK MANAGEMENT SYSTEM" << endl;
    cout << "=======================================" << endl;
    while (true)
    {

        int usertype = user.mainMenu();
        if (usertype == 1)
        {
            int choice = operation.admin();
            if (choice == 0)
            {
                return 0;
            }
            else
            {
                continue;
            }
        }
        else if (usertype == 2)
        {
            int choice = operation.customer();
            if (choice == 0)
            {
                return 0;
            }
        }
        else if (usertype == 3)
        {
            cout << "Program closed.\n";
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}