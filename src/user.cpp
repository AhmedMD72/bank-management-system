#include "../include/user.h"

void user :: setName(string name)
    {
        Name = name;
    }
    string user ::getName()
    {
        return Name;
    }
    void user ::setId(string id)
    {
        ID = id;
    }
    string user :: getId()
    {
        return ID;
    }
    void user ::setPhoneNum(string phonenum)
    {
        PhoneNumber = phonenum;
    }
    string user ::getPhoneNum()
    {
        return PhoneNumber;
    }
    user :: user (string name, string id, string phonenumber)
    {
        Name = name;
        ID = id;
        PhoneNumber = phonenumber;
    }
    user :: user(string name, string id)
    {
        Name = name;
        ID = id;
    }
    