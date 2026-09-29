#pragma once
#include <iostream>
#include <string>
using std::string;
class user
{
private:
    string Name;
    string ID;
    string PhoneNumber;

public:
    void setName(string name);
    string getName();
    void setId(string id);
    string getId();
    void setPhoneNum(string phonenum);
    string getPhoneNum();
    user(string name, string id, string phonenumber);
    user(string name, string id);
};