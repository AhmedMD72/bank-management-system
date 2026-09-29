#include "../include/authentication.h"
#include <limits>
customers authenticationservice :: loginCustomer()
    {
        userrepository customercheck;
        userdata data;
        optional<customers> customer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Full Name: ";
            getline(cin, data.name);
            cout << "Enter your ID: ";
            getline(cin, data.id);
            cout << "=======================================" << endl;
            cout << "=======================================" << endl;
            if (customercheck.customerscheckfile(data, customer))
            {
                // customer = customers (data.name,data.id);
                return customer.value();
            }
            else
            {
                cout << "Please Enter True data" << endl;
            }
        }
    }
    admins authenticationservice :: loginAdmin()
    {
        userrepository admincheck;
        userdata data;
        optional<admins> admin;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Full Name: ";
            getline(cin, data.name);
            cout << "Enter your ID: ";
            getline(cin, data.id);
            cout << "=======================================" << endl;
            cout << "=======================================" << endl;
            if (admincheck.adminscheckfile(data, admin))
            {
                // customer = customers (data.name,data.id);
                return admin.value();
            }
            else
            {
                cout << "Please Enter True data" << endl;
            }
        }
    }