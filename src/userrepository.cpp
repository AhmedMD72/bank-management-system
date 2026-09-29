#include "../include/userrepository.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
bool userrepository :: customerscheckfile(userdata datauser, optional<customers> &customer)
    {
        ifstream file("data/bank_data_customers.json");

        if (!file.is_open())
        {
            cout << "ERROR: Customer file not opened\n";
            return false;
        }
        userdata  data;
        json customersData;
        file >> customersData;
        for (const auto &c : customersData)
        {
            data.name = c["name"];
            data.id = c["id"];
            if (datauser.name == data.name && datauser.id == data.id)
            {
                customer.emplace(c["name"], c["id"], c["phonenumber"], c["balance"], c["transactions"]);
                return true;
            }
        }
        return false;
    }
    bool userrepository :: adminscheckfile(userdata data, optional<admins> &admin)
    {
        string phone;
        string role;
        json adminsData;
        ifstream file("data/bank_data_admins.json");
        if (!file.is_open())
        {
            return false;
        }
        file >> adminsData;
        for (const auto &a : adminsData)
        {
            string name = a["name"];
            string id = a["id"];
            string phone = a["phonenumber"];
            string role = a["role"];
            if (data.name == name && data.id == id)
            {
                admin.emplace(data.name, data.id, phone, role);
                cout << data.name << " || " << name << " ### " << data.id << " || " << id << " ### " << role << endl;
                return true;
            }
        }
        return false;
    }

    void userrepository :: updatefilecreateaccount(customers customer)
    {
        json customersData;

        // 1. Read existing file
        ifstream inputFile("data/bank_data_customers.json");

        if (inputFile.is_open())
        {
            inputFile >> customersData;
            inputFile.close();
        }
        json newCustomer;
        newCustomer["name"] = customer.getName();
        newCustomer["id"] = customer.getId();
        newCustomer["phonenumber"] = customer.getPhoneNum();
        newCustomer["balance"] = customer.getAccount().getBalance();
        newCustomer["transactions"] = customer.getAccount().getTransactions();
        customersData.push_back(newCustomer);
        ofstream outputFile("data/bank_data_customers.json");
        outputFile << customersData.dump(4);
        outputFile.close();
    }
    void userrepository :: deleteAccountFile(optional<customers> customer)
    {
        json customerData;
        ifstream file("data/bank_data_customers.json");
        if (!file.is_open())
        {
            return;
        }
        file >> customerData;
        file.close();
        for (auto it = customerData.begin(); it != customerData.end(); ++it)
        {
            if ((*it)["id"] == customer->getId())
            {
                customerData.erase(it);
                break;
            }
        }
        ofstream outputfile("data/bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();
    }
    void userrepository :: updateCustomerData(customers &customer)
    {
        json customerData;
        ifstream oldfile("data/bank_data_customers.json");
        if (!oldfile.is_open())
        {
            return;
        }
        oldfile >> customerData;
        oldfile.close();
        for (auto &c : customerData)
        {
            if (c["id"] == customer.getId())
            {
                c["balance"] = customer.getAccount().getBalance();
                c["transactions"] = customer.getAccount().getTransactions();
                break;
            }
        }
        ofstream outputfile("data/bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();
        cout << customer.getName() << "|| Balance: " << customer.getAccount().getBalance() << endl;
    }

    void userrepository :: updateCustomerChangeData(string id, customers &customer)
    {
        json customerData;
        ifstream oldfile("data/bank_data_customers.json");
        if (!oldfile.is_open())
        {
            return;
        }
        oldfile >> customerData;
        oldfile.close();

        for (auto &c : customerData)
        {
            if (c["id"] == customer.getId())
            {
                customer.setId(id);
                c["name"] = customer.getName();
                c["id"] = customer.getId();
                c["phonenumber"] = customer.getPhoneNum();
                break;
            }
        }
        ofstream outputfile("data/bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();

        cout << customer.getName() << "|| Balance: " << customer.getAccount().getBalance() << " || " << endl;
    }
    string userrepository :: changedata(customers &customer)
    {
        string name;
        string id;
        string phone;
        int choice;
        cout << "^^^^^^^^^^^^ New Data ^^^^^^^^^^^^" << endl;
        while (true)
        {
            cout << "please select the data type." << endl;
            cout << "1.Name." << endl;
            cout << "2.ID." << endl;
            cout << "3.Phone Number." << endl;
            cout << "4.Exit." << endl;
            cout << "Enter choice: ";
            if (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (choice)
            {
            case 1:
            {
                cout << "New Name: ";
                getline(cin, name);
                customer.setName(name);
                break;
            }
            case 2:
            {
                cout << "New ID: ";
                getline(cin, id);
                // customer.setId(id);
                break;
            }
            case 3:
            {
                cout << "New Phone Number: ";
                getline(cin, phone);
                customer.setPhoneNum(phone);
                break;
            }
            case 4:
            {
                if (id.empty())
                {
                    return customer.getId();
                }
                else
                {
                    cout << "ID change data: " << id << endl;
                    return id;
                }
            }
            default:
                cout << "Invalid choice, Please try again\n";
            }
        }
    }
    void userrepository :: updatetransfer(customers &customer, customers &customer2)
    {
        json customerData;
        ifstream oldfile("data/bank_data_customers.json");
        if (!oldfile.is_open())
        {
            return;
        }
        oldfile >> customerData;
        oldfile.close();

        for (auto &c : customerData)
        {
            if (c["id"] == customer.getId())
            {
                c["balance"] = customer.getAccount().getBalance();
                c["transactions"] = customer.getAccount().getTransactions();
            }
            else if (c["id"] == customer2.getId())
            {
                c["balance"] = customer2.getAccount().getBalance();
                c["transactions"] = customer2.getAccount().getTransactions();
            }
        }
        ofstream outputfile("data/bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();
    }