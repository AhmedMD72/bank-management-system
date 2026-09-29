#include "../include/consoleui.h"

int consoleui::mainMenu()
    {
        cout << "Please Choice 1 or 2 " << endl;
        cout << "1.Admin" << endl;
        cout << "2.Customer" << endl;
        cout << "3.Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter Choice: ";
        return getIntegerInput();
    }
    int consoleui:: customerMenu()
    {
        cout << "Please Choice the operation\n";
        cout << "=======================================" << endl;
        cout << "1. Withdraw Money\n";
        cout << "2. Deposit Money\n";
        cout << "3. Secure Login\n";
        cout << "4. Transfer Money\n";
        cout << "5. Transaction Logs\n";
        cout << "6. Exit\n";
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << "Enter Choice: ";
        return getIntegerInput();
    }
    int consoleui:: adminMenu()
    {
        cout << "Please Choice the operation " << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Display All Customers" << endl;
        cout << "3. Search Account by ID" << endl;
        cout << "4. Delet Account" << endl;
        cout << "5. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << "Enter Choice: ";
        return getIntegerInput();
    }
    int consoleui:: depositMenu()
    {
        cout << "^^^^^^^^^^^^  Deposit ^^^^^^^^^^^^\n";
        cout << "Do you need deposit or exit" << endl;
        cout << "1.Deposit" << endl;
        cout << "2.Exit" << endl;
        cout << "please chocie: ";
        return getIntegerInput();
    }
    int consoleui:: withdrawMenu()
    {
        cout << "^^^^^^^^^^^^  Withdrawal  ^^^^^^^^^^^^\n";
        cout << "Do you need withdrawal or exit" << endl;
        cout << "1.Withdrawal" << endl;
        cout << "2.Exit" << endl;
        cout << "Please chocie: ";
        return getIntegerInput();
    }
    int consoleui:: SecureLoginMenu()
    {
        cout << "^^^^^^^^^^^^  Secure Login  ^^^^^^^^^^^^\n";
        cout << "Please choice the  operation" << endl;
        cout << "1.Show data." << endl;
        cout << "2.Change data." << endl;
        cout << "3.Exit." << endl;
        cout << "Enter choice: ";
        return getIntegerInput();
    }
    int consoleui:: transferMenu()
    {
        cout << "^^^^^^^^^^^^  Transfer ^^^^^^^^^^^^\n";
        cout << "Please choice the  operation" << endl;
        cout << "1.Transfer." << endl;
        cout << "2.Exit." << endl;
        cout << "Enter choice: ";
        return getIntegerInput();
    }
