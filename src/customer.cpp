#include "../include/customer.h"
#include <iostream>

using namespace std;

customers::customers(
    string name,
    string id,
    string phone_num,
    int balance,
    vector<string> transactions
)
    : user(name, id, phone_num)
{
    account.setBalance(balance);
    account.setTransactions(transactions);
}

customers::customers(string name, string id)
    : user(name, id)
{
}

accounts& customers::getAccount()
{
    return account;
}

void customers::viewaccount()
{
    cout << "#######################################" << endl;

    cout << "Welcome "
         << getName() << " "
         << getId() << " "
         << account.getBalance()
         << endl;

    cout << "#######################################" << endl;
}