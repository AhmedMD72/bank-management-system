#include "../include/operationuser.h"

    int operationuser::customer()
    {
        customers currentcustomer = authent.loginCustomer();
        while (true)
        {
            int customertype = user.customerMenu();
            if (customertype == 1)
            {
                service.withdraw(currentcustomer);
            }
            else if (customertype == 2)
            {
                service.deposit(currentcustomer);
            }
            else if (customertype == 3)
            {
                service.securelogin(currentcustomer);
            }
            else if (customertype == 4)
            {
                service.transfer(currentcustomer);
            }
            else if (customertype == 5)
            {
                service.transactionlogs(currentcustomer);
            }
            else if (customertype == 6)
            {
                cout << "Program closed.\n";
                return 0;
            }
            else
            {
                cout << "Invalid choice\n";
            }
        }
    }
    int operationuser::admin()
        {
            admins admin(authent.loginAdmin());
            while (true)
            {
                int admintype = user.adminMenu();
                if (admintype == 1)
                {
                    techoperation.createaccount();
                }
                else if (admintype == 2)
                {
                    techoperation.dispalyallcustomers();
                }
                else if (admintype == 3)
                {
                    techoperation.searchaccount();
                }
                else if (admintype == 4)
                {
                    techoperation.deletaccount();
                }
                else if (admintype == 5)
                {

                    cout << "Program closed.\n";
                    return 0;
                }
                else
                {
                    cout << "Invalid choice\n";
                }
            }
    }