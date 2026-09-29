#include "customer.h"
#include "consoleui.h"
#include "technicaloperations.h"
#include "authentication.h"
#include "bankservice.h"
class operationuser
{
public:
    consoleui user;
    technicaloperations techoperation;
    authenticationservice authent;
    bankservice service;
    int customer();
    
    int admin();
    
};    