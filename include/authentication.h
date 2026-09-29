#include "customer.h"
#include "admin.h"
#include "userrepository.h"
class authenticationservice
{

public:
    customers loginCustomer();
    admins loginAdmin();
    
};