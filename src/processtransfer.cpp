
#include "../include/processtransfer.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
    bool processtransfer :: transfercheckdata(userdata datacustomer, optional<customers> &customer2)
    {
        json customerData;
        ifstream file("data/bank_data_customers.json");
        if (!file.is_open())
        {
            return false;
        }
        file >> customerData;
        file.close();
        for (auto &c : customerData)
        {

            if (c["name"] == datacustomer.name && c["id"] == datacustomer.id)
            {
                customer2.emplace(c["name"], c["id"], c["phonenumber"], c["balance"], c["transactions"]);
                cout << "Recipient found: " << c["name"] << ", ID: " << c["id"] << endl;
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }
    customers processtransfer :: transfercustomerdata()
    {

        optional<customers> customer2;
        userdata data;
        cout << "^^^^^^^^^^^^ Transaction Customer Data ^^^^^^^^^^^^" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Please enter the recipient's information." << endl;
            cout << "Recipient Name: ";
            getline(cin, data.name);
            // customer2.setName(name);
            cout << "Recipient ID: ";
            getline(cin, data.id);
            if (transfercheckdata(data, customer2))
            {

                return customer2.value();
            }
            else
            {
                cout << "Customer not found. Please check the name and ID and try again." << endl;
            }
        }
    }
