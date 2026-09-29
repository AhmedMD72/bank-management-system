#pragma once
#include <string>
using std::string;
#include "user.h"
#include "account.h"

class customers : public user
{

    accounts account;

public:
    customers(string name, string id, string phone_num, int balance, vector<string> transactions) ;

    customers(string name, string id) ;

    accounts &getAccount();

    void viewaccount();
};
