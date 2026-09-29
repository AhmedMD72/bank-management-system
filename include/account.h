#pragma once
#include <vector>
#include <string>
using std::string;





using namespace std;
using std::string;


class accounts
{
private:
    int Balance;
    vector<string> transactions;

public:
    void setBalance(int balance);

    int getBalance();

    void setTransactions(vector<string> &newtransactions);

    void withdrawal(int amount);

    void deposit(int amount);

    void addTransactions(string &transaction);

    vector<string> getTransactions();
};