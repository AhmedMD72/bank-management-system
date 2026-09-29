#include "../include/technicaloperations.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
struct customerdata
{
    string name;
    string id;
    string phonenumber;
    int balance;
    vector<string> transaction;
};
void technicaloperations::createaccount()
    {
        
        customerdata data;
        cin.ignore();
        cout << "Full Name: ";
        getline(cin, data.name);
        cout << "Enter your ID: ";
        cin >> data.id;
        cout << "Enter your PhoneNumber: ";
        cin >> data.phonenumber;
        data.balance = 0;
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        customers customer(data.name, data.id, data.phonenumber, data.balance, data.transaction);
        user.updatefilecreateaccount(customer);
        customer.viewaccount();
    }
    void technicaloperations::dispalyallcustomers()
    {
        json customerData;
        ifstream file("data/bank_data_customers.json");
        if (!file.is_open())
        {
            return;
        }
        file >> customerData;
        file.close();
        for (auto &c : customerData)
        {
            cout << "Name: " << c["name"] << " ID: " << c["id"] << " Phone Number: " << c["phonenumber"]
                 << " Balance: $" << c["balance"] << endl;
            cout << "=======================================" << endl;
        }
        cout << "=======================================" << endl;
    }
    void technicaloperations::searchaccount()
    {

        customerdata data;
        string balanceStr;
        string idSearch;
        do
        {
            cout << "Enter ID Account: ";
            cin >> idSearch;

            json customerData;
            ifstream file("data/bank_data_customers.json");
            if (!file.is_open())
            {
                return;
            }
            file >> customerData;
            file.close();
            for (auto &c : customerData)
            {
                if (c["id"] == idSearch)
                {
                    cout << "Name: " << c["name"] << " ID: " << c["id"] << " Phone Number: " << c["phonenumber"]
                         << " Balance: $" << c["balance"] << endl;
                    cout << "=======================================" << endl;
                    return;
                }
            }
            // file.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "=======================================" << endl;
            cout << "Not Found ID Account , Please enter vaild ID " << endl;
            cout << "=======================================" << endl;
            cout << " Etner 0 for exit: \n";
            if (idSearch == "0")
            {
                return;
            }

        } while (idSearch != data.id);
    }

    void technicaloperations::deletaccount()
    {
        userrepository user;
        userdata data;
        optional<customers> customer;
        string delet;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Enter Name Account: ";
            getline(cin, data.name);
            cout << "Enter ID Account: ";
            getline(cin, data.id);
            if (user.customerscheckfile(data, customer))
            {
                cout << "^^^^^ Customer Data ^^^^^\n";
                cout << "Name : " << customer->getName() << " ID : " << customer->getId() << " Phone Number : " << customer->getPhoneNum() << "Balance : " << customer->getAccount().getBalance() << endl;
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
                cout << "Are you sure from delet account? (type Yes if you sure or No) : ";
                cin >> delet;
                while (true)
                {
                    if (delet == "Yes" || delet == "yes")
                    {
                        user.deleteAccountFile(customer);
                        cout << "The Account has been deleted successfully" << endl;
                        cout << "#######################################" << endl;
                        return;
                    }
                    else if (delet == "No" || delet == "no")
                    {
                        cout << "The Account has not been deleted " << endl;
                        cout << "#######################################" << endl;
                        return;
                    }
                    else
                    {
                        cout << "Please write Yes or No" << endl;
                        cout << "=======================================" << endl;
                    }
                }
            }

            else
            {
                cout << "=======================================" << endl;
                cout << "Not Found Naem and ID Account , Please enter vaild Data " << endl;
                cout << "=======================================" << endl;
            }
        }
    }