#include "../include/processbankservice.h"


    bool processbankservice :: withdrawaltransferProcess(customers &customer, int &amount, string operation)
    {
        do
        {

            cout << "Minimum " << operation << " amount is $50." << endl;
            cout << "###################################" << endl;
            cout << "Please enter an amount in multiples of $50." << endl;
            cout << "###################################" << endl;
            cout << "Enter 0 to cancel." << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << operation << " Amount: ";
            cin >> amount;
            if (amount == 0)
            {
                return false;
            }
            else if (amount < 50)
            {
                cout << "Invalid amount. The minimum " << operation << " is $50." << endl;
            }
            else if (amount % 50 != 0)
            {
                cout << "Invalid amount. Please enter a multiple of $50." << endl;
            }
            else if (amount > customer.getAccount().getBalance())
            {
                cout << "Insufficient balance." << endl;
            }

        } while (amount < 50 || amount % 50 != 0 || amount > customer.getAccount().getBalance());
        return true;
    }
    bool processbankservice ::  depositProcess(int &DepositAmount)
    {
        do
        {

            cout << "Minimum Deposit amount is $50." << endl;
            cout << "###################################" << endl;
            cout << "Please enter an amount in multiples of $50." << endl;
            cout << "###################################" << endl;
            cout << "Enter 0 to cancel." << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << "Deposit Amount: ";
            cin >> DepositAmount;

            if (DepositAmount == 0)
            {
                return false;
            }
            else if (DepositAmount < 50)
            {
                cout << "Invalid amount. The minimum withdrawal is $50." << endl;
            }
            else if (DepositAmount % 50 != 0)
            {
                cout << "Invalid amount. Please enter a multiple of $50." << endl;
            }

        } while (DepositAmount < 50 || DepositAmount % 50 != 0);
        return true;
    }
