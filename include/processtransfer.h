#pragma once
#include "customer.h"
#include <string>
#include <optional>
#include "userdata.h"
using std::string;
class processtransfer
{

public:
    bool transfercheckdata(userdata datacustomer, optional<customers> &customer2);

    customers transfercustomerdata();

};