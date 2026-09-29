#pragma once
#include <string>
using std::string;
#include "user.h"
class admins : public user
{
private:
    string JobTitle;

public:
    void setJobTitle(string jobtitle);

    string getJobTitle();

    admins(string name, string id, string phonenumber, string jobtitle) ;

    admins(string name, string id) ;

    void identification();
};