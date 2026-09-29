#pragma once 
#include "processbankservice.h"
#include "processtransfer.h"
#include "userrepository.h"
#include "consoleui.h"
class bankservice
{
public:
    consoleui ui;
    userrepository user;
    processbankservice process;
    processtransfer transferprocess;
    void withdraw(customers &customer);

    void deposit(customers &customer);

    void securelogin(customers &customer);


    void transfer(customers &customer);

    void transactionlogs(customers &customer);

};