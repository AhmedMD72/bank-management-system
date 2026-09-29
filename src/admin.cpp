#include "../include/admin.h"

void admins :: setJobTitle(string jobtitle)
    {
        JobTitle = jobtitle;
    }
    string admins :: getJobTitle()
    {
        return JobTitle;
    }
    admins :: admins(string name, string id, string phonenumber, string jobtitle) : user(name, id, phonenumber)
    {
        JobTitle = jobtitle;
    }
    admins :: admins(string name, string id) : user(name, id)
    {
    }
    void admins :: identification()
    {
        // cout << "Welcome " << getName() << " Now, You are in the Admins Page\nYou can select opeartion do you need" << endl;
        // // cout << "Role: " << JobTitle << endl;
        // // cout << "ID: " << getId() << endl;
        // // cout << "Phone Number: " << getPhoneNum() << endl;
        // cout << "=======================================" << endl;
    }