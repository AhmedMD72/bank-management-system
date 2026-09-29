#include "../include/bankservice.h"
#include <thread>
#include <chrono>
    void bankservice::withdraw(customers &customer)
    {
        
        int amount;
        while (true)
        {
            int choice = ui.withdrawMenu();
            if (choice == 1)
            {
                if (!process.withdrawaltransferProcess(customer, amount, "withdrawal"))
                {
                    return;
                }
                else
                {
                    customer.getAccount().withdrawal(amount);
                    string transaction = "Withdrawal Money, Amount: $" + to_string(amount);
                    customer.getAccount().addTransactions(transaction);
                    user.updateCustomerData(customer);
                    cout << "Processing your withdrawal..." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Withdrawal successful." << endl;
                    return;
                }
            }
            else if (choice == 2)
            {
                return;
            }
            else
            {
                cout << "Please enter 1 or 2" << endl;
            }
        }
    }
    void bankservice::deposit(customers &customer)
    {
        
        int depositAmount;
        while (true)
        {
            int choice = ui.depositMenu();
            if (choice == 1)
            {
                if (!process.depositProcess(depositAmount))
                {
                    return;
                }
                else
                {
                    customer.getAccount().deposit(depositAmount);
                    string transaction = "Deposit Money, Amount: $" + to_string(depositAmount);
                    customer.getAccount().addTransactions(transaction);
                    user.updateCustomerData(customer);
                    cout << "Processing your Deposit Money..." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Deposit successful." << endl;
                    return;
                }
            }
            else if (choice == 2)
            {
                return;
            }
            else
            {
                cout << "Please enter 1 or 2" << endl;
            }
        }
    }
    void bankservice::securelogin(customers &customer)
    {
        
        string id;
        cout << "^^^^^^^^^^^^  Secure Login  ^^^^^^^^^^^^\n";
        while (true)
        {
            int choice = ui.SecureLoginMenu();

            if (choice == 1)
            {
                cout << "Name: " << customer.getName() << " ID: " << customer.getId() << " Phone Number: " << customer.getPhoneNum()
                     << " Balance: " << "$" << customer.getAccount().getBalance() << endl;
            }
            else if (choice == 2)
            {
                cout << "^^^^^^^^^^^^ Current Data ^^^^^^^^^^^^" << endl;
                cout << "Name: " << customer.getName() << " ID: " << customer.getId() << " Phone Number: " << customer.getPhoneNum()
                     << " Balance: " << "$" << customer.getAccount().getBalance() << endl;
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                id = user.changedata(customer);
                cout << "ID after chage data: " << id << endl;
                user.updateCustomerChangeData(id, customer);
            }
            else if (choice == 3)
            {
                return;
            }
            else
            {
                cout << "Invaild choice, please try again" << endl;
            }
        }
    }

    void bankservice::transfer(customers &customer)
    {
        consoleui ui;
        string id;
        int amount;
        cout << "^^^^^^^^^^^^  Transfer ^^^^^^^^^^^^\n";
        while (true)
        {
            int choice = ui.transferMenu();
            if (choice == 1)
            {
                customers recipient = transferprocess.transfercustomerdata();
                cout << "^^^^^^^^^^^^  Transfer Amount ^^^^^^^^^^^^\n";
                if (!process.withdrawaltransferProcess(customer, amount, "transfer"))
                {
                    cout << "^^^^^^^^^^^^ Transfer failed ^^^^^^^^^^^^" << endl;
                    return;
                }
                else
                {
                    customer.getAccount().withdrawal(amount);
                    recipient.getAccount().deposit(amount);
                    string transactionSender = "Transfer Money, Amount: $" + to_string(amount) + " to " + recipient.getName();
                    customer.getAccount().addTransactions(transactionSender);
                    string transactionRecipient = "Received Money, Amount: $" + to_string(amount) + " from " + customer.getName();
                    recipient.getAccount().addTransactions(transactionRecipient);
                    user.updatetransfer(customer, recipient);
                    cout << "Processing Your Transfer..." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Transfer successful." << endl;
                    return;
                }
            }
            else if (choice == 2)
            {
                return;
            }
            else
            {
                cout << "Invaild choice, please try again" << endl;
            }
        }
    }
    void bankservice::transactionlogs(customers &customer)
    {
        cout << customer.getName() << '\n';
        cout << "========================" << '\n';
        // cout <<  customer.getAccount().getTransactions()[0] <<endl;
        for (string &transaction : customer.getAccount().getTransactions())
        {
            cout << "#######################" << '\n';
            cout << transaction << endl;
        }
    }
