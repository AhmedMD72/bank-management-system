#pragma once
#include "customer.h"
#include "admin.h"
#include <string>
#include "userdata.h"
#include <optional>
using std::string;


class userrepository
{

public:
    bool customerscheckfile(userdata datauser, optional<customers> &customer);

    bool adminscheckfile(userdata data, optional<admins> &admin);
    
    void updatefilecreateaccount(customers customer);
   
    void deleteAccountFile(optional<customers> customer);
   
    void updateCustomerData(customers &customer);
    

    void updateCustomerChangeData(string id, customers &customer);
    
    string changedata(customers &customer);
   
    void updatetransfer(customers &customer, customers &customer2);
    
};