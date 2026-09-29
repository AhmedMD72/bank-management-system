#include "../include/account.h"

void accounts::setBalance(int balance)
    {
        Balance = balance;
    }
    int accounts::getBalance()
    {
        return Balance;
    }

    void accounts::setTransactions(vector<string> &newtransactions)
    {
        transactions = newtransactions;
    }

    void accounts::withdrawal(int amount)
    {
        Balance -= amount;
    }
    void accounts::deposit(int amount)
    {
        Balance += amount;
    }
    void accounts::addTransactions(string &transaction)
    {
        transactions.push_back(transaction);
    }
    vector<string> accounts::getTransactions()
    {
        return transactions;
    }