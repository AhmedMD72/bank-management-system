#pragma once 
#include "customer.h"

class processbankservice
{
public:
    bool withdrawaltransferProcess(customers &customer, int &amount, string operation);
    
    bool depositProcess(int &DepositAmount);
    
};