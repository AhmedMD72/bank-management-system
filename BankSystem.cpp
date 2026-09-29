#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <thread>
#include <chrono>
#include <optional>
#include <nlohmann/json.hpp>
using json = nlohmann::ordered_json;
using namespace std;
using std::string;
struct customerdata
{
    string name;
    string id;
    string phonenumber;
    int balance;
    vector<string> transaction;
};
struct userdata
{
    string name;
    string id;
};

class user
{
private:
    string Name;
    string ID;
    string PhoneNumber;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setId(string id)
    {
        ID = id;
    }
    string getId()
    {
        return ID;
    }
    void setPhoneNum(string phonenum)
    {
        PhoneNumber = phonenum;
    }
    string getPhoneNum()
    {
        return PhoneNumber;
    }
    user(string name, string id, string phonenumber)
    {
        Name = name;
        ID = id;
        PhoneNumber = phonenumber;
    }
    user(string name, string id)
    {
        Name = name;
        ID = id;
    }
};

class accounts
{
private:
    int Balance;
    vector<string> transactions;

public:
    void setBalance(int balance)
    {
        Balance = balance;
    }
    int getBalance()
    {
        return Balance;
    }

    void setTransactions(vector<string> &newtransactions)
    {
        transactions = newtransactions;
    }

    void withdrawal(int amount)
    {
        Balance -= amount;
    }
    void deposit(int amount)
    {
        Balance += amount;
    }
    void addTransactions(string &transaction)
    {
        transactions.push_back(transaction);
    }
    vector<string> getTransactions()
    {
        return transactions;
    }
};
class customers : public user
{

    accounts account;

public:
    customers(string name, string id, string phone_num, int balance, vector<string> transactions) : user(name, id, phone_num)
    {
        account.setBalance(balance);
        account.setTransactions(transactions);
    }
    customers(string name, string id) : user(name, id)
    {
    }

    accounts &getAccount()
    {
        return account;
    }

    void viewaccount()
    {
        cout << "#######################################" << endl;
        cout << "Weclcome " << getName() << " " << getId() << " " << account.getBalance() << endl;
        cout << "#######################################" << endl;
    }
};
class admins : public user
{
private:
    string JobTitle;

public:
    void setJobTitle(string jobtitle)
    {
        JobTitle = jobtitle;
    }
    string getJobTitle()
    {
        return JobTitle;
    }
    admins(string name, string id, string phonenumber, string jobtitle) : user(name, id, phonenumber)
    {
        JobTitle = jobtitle;
    }
    admins(string name, string id) : user(name, id)
    {
    }
    void identification()
    {
        cout << "Welcome " << getName() << " Now, You are in the Admins Page\nYou can select opeartion do you need" << endl;
        // cout << "Role: " << JobTitle << endl;
        // cout << "ID: " << getId() << endl;
        // cout << "Phone Number: " << getPhoneNum() << endl;
        cout << "=======================================" << endl;
    }
};
class consoleui
{
private:
    int getIntegerInput()
    {
        int value;
        while (true)
        {
            if (cin >> value)
            {
                return value;
            }
            cout << "Invalid input. Please enter a number:\n";
            cout << "Enter Choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    int mainMenu()
    {
        cout << "Please Choice 1 or 2 " << endl;
        cout << "1.Admin" << endl;
        cout << "2.Customer" << endl;
        cout << "3.Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter Choice: ";
        return getIntegerInput();
    }
    int customerMenu()
    {
        cout << "Please Choice the operation\n";
        cout << "=======================================" << endl;
        cout << "1. Withdraw Money\n";
        cout << "2. Deposit Money\n";
        cout << "3. Secure Login\n";
        cout << "4. Transfer Money\n";
        cout << "5. Transaction Logs\n";
        cout << "6. Exit\n";
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << "Enter Choice: ";
        return getIntegerInput();
    }
    int adminMenu()
    {
        cout << "Please Choice the operation " << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Display All Customers" << endl;
        cout << "3. Search Account by ID" << endl;
        cout << "4. Delet Account" << endl;
        cout << "5. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << "Enter Choice: ";
        return getIntegerInput();
    }
    int depositMenu()
    {
        cout << "^^^^^^^^^^^^  Deposit ^^^^^^^^^^^^\n";
        cout << "Do you need deposit or exit" << endl;
        cout << "1.Deposit" << endl;
        cout << "2.Exit" << endl;
        cout << "please chocie: ";
        return getIntegerInput();
    }
    int withdrawMenu()
    {
        cout << "^^^^^^^^^^^^  Withdrawal  ^^^^^^^^^^^^\n";
        cout << "Do you need withdrawal or exit" << endl;
        cout << "1.Withdrawal" << endl;
        cout << "2.Exit" << endl;
        cout << "Please chocie: ";
        return getIntegerInput();
    }
    int SecureLoginMenu()
    {
        cout << "^^^^^^^^^^^^  Secure Login  ^^^^^^^^^^^^\n";
        cout << "Please choice the  operation" << endl;
        cout << "1.Show data." << endl;
        cout << "2.Change data." << endl;
        cout << "3.Exit." << endl;
        cout << "Enter choice: ";
        return getIntegerInput();
    }
    int transferMenu()
    {
        cout << "^^^^^^^^^^^^  Transfer ^^^^^^^^^^^^\n";
        cout << "Please choice the  operation" << endl;
        cout << "1.Transfer." << endl;
        cout << "2.Exit." << endl;
        cout << "Enter choice: ";
        return getIntegerInput();
    }
};
class userrepository
{

public:
    bool customerscheckfile(userdata datauser, optional<customers> &customer)
    {
        ifstream file("bank_data_customers.json");

        if (!file.is_open())
        {
            return false;
        }
        customerdata data;
        json customersData;
        file >> customersData;
        for (const auto &c : customersData)
        {
            data.name = c["name"];
            data.id = c["id"];
            if (datauser.name == data.name && datauser.id == data.id)
            {
                customer.emplace(c["name"], c["id"], c["phonenumber"], c["balance"], c["transactions"]);
                return true;
            }
        }
        return false;
    }
    bool adminscheckfile(userdata data, optional<admins> &admin)
    {
        string phone;
        string role;
        json adminsData;
        ifstream file("bank_data_admins.json");
        if (!file.is_open())
        {
            return false;
        }
        file >> adminsData;
        for (const auto &a : adminsData)
        {
            string name = a["name"];
            string id = a["id"];
            string phone = a["phonenumber"];
            string role = a["role"];
            if (data.name == name && data.id == id)
            {
                admin.emplace(data.name, data.id, phone, role);
                cout << data.name << " || " << name << " ### " << data.id << " || " << id << " ### " << role << endl;
                return true;
            }
        }
        return false;
    }

    void updatefilecreateaccount(customers customer)
    {
        json customersData;

        // 1. Read existing file
        ifstream inputFile("bank_data_customers.json");

        if (inputFile.is_open())
        {
            inputFile >> customersData;
            inputFile.close();
        }
        json newCustomer;
        newCustomer["name"] = customer.getName();
        newCustomer["id"] = customer.getId();
        newCustomer["phonenumber"] = customer.getPhoneNum();
        newCustomer["balance"] = customer.getAccount().getBalance();
        newCustomer["transactions"] = customer.getAccount().getTransactions();
        customersData.push_back(newCustomer);
        ofstream outputFile("bank_data_customers.json");
        outputFile << customersData.dump(4);
        outputFile.close();
    }
    void deleteAccountFile(optional<customers> customer)
    {
        json customerData;
        ifstream file("bank_data_customers.json");
        if (!file.is_open())
        {
            return;
        }
        file >> customerData;
        file.close();
        for (auto it = customerData.begin(); it != customerData.end(); ++it)
        {
            if ((*it)["id"] == customer->getId())
            {
                customerData.erase(it);
                break;
            }
        }
        ofstream outputfile("bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();
    }
    void updateCustomerData(customers &customer)
    {
        json customerData;
        ifstream oldfile("bank_data_customers.json");
        if (!oldfile.is_open())
        {
            return;
        }
        oldfile >> customerData;
        oldfile.close();
        for (auto &c : customerData)
        {
            if (c["id"] == customer.getId())
            {
                c["balance"] = customer.getAccount().getBalance();
                c["transactions"] = customer.getAccount().getTransactions();
                break;
            }
        }
        ofstream outputfile("bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();
        cout << customer.getName() << "|| Balance: " << customer.getAccount().getBalance() << endl;
    }

    void updateCustomerChangeData(string id, customers &customer)
    {
        json customerData;
        ifstream oldfile("bank_data_customers.json");
        if (!oldfile.is_open())
        {
            return;
        }
        oldfile >> customerData;
        oldfile.close();

        for (auto &c : customerData)
        {
            if (c["id"] == customer.getId())
            {
                customer.setId(id);
                c["name"] = customer.getName();
                c["id"] = customer.getId();
                c["phonenumber"] = customer.getPhoneNum();
                break;
            }
        }
        ofstream outputfile("bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();

        cout << customer.getName() << "|| Balance: " << customer.getAccount().getBalance() << " || " << endl;
    }
    string changedata(customers &customer)
    {
        string name;
        string id;
        string phone;
        int choice;
        cout << "^^^^^^^^^^^^ New Data ^^^^^^^^^^^^" << endl;
        while (true)
        {
            cout << "please select the data type." << endl;
            cout << "1.Name." << endl;
            cout << "2.ID." << endl;
            cout << "3.Phone Number." << endl;
            cout << "4.Exit." << endl;
            cout << "Enter choice: ";
            if (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (choice)
            {
            case 1:
            {
                cout << "New Name: ";
                getline(cin, name);
                customer.setName(name);
                break;
            }
            case 2:
            {
                cout << "New ID: ";
                getline(cin, id);
                // customer.setId(id);
                break;
            }
            case 3:
            {
                cout << "New Phone Number: ";
                getline(cin, phone);
                customer.setPhoneNum(phone);
                break;
            }
            case 4:
            {
                if (id.empty())
                {
                    return customer.getId();
                }
                else
                {
                    cout << "ID change data: " << id << endl;
                    return id;
                }
            }
            default:
                cout << "Invalid choice, Please try again\n";
            }
        }
    }
    void updatetransfer(customers &customer, customers &customer2)
    {
        json customerData;
        ifstream oldfile("bank_data_customers.json");
        if (!oldfile.is_open())
        {
            return;
        }
        oldfile >> customerData;
        oldfile.close();

        for (auto &c : customerData)
        {
            if (c["id"] == customer.getId())
            {
                c["balance"] = customer.getAccount().getBalance();
                c["transactions"] = customer.getAccount().getTransactions();
            }
            else if (c["id"] == customer2.getId())
            {
                c["balance"] = customer2.getAccount().getBalance();
                c["transactions"] = customer2.getAccount().getTransactions();
            }
        }
        ofstream outputfile("bank_data_customers.json");
        if (!outputfile.is_open())
        {
            return;
        }
        outputfile << customerData.dump(4);
        outputfile.close();
    }
};
/*
========================
        SERVICES
========================
*/

class processbankservice
{
public:
    bool withdrawaltransferProcess(customers &customer, int &amount, string operation)
    {
        do
        {

            cout << "Minimum " << operation << " amount is $50." << endl;
            cout << "###################################" << endl;
            cout << "Please enter an amount in multiples of $50." << endl;
            cout << "###################################" << endl;
            cout << "Enter 0 to cancel." << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << operation << " Amount: ";
            cin >> amount;
            if (amount == 0)
            {
                return false;
            }
            else if (amount < 50)
            {
                cout << "Invalid amount. The minimum " << operation << " is $50." << endl;
            }
            else if (amount % 50 != 0)
            {
                cout << "Invalid amount. Please enter a multiple of $50." << endl;
            }
            else if (amount > customer.getAccount().getBalance())
            {
                cout << "Insufficient balance." << endl;
            }

        } while (amount < 50 || amount % 50 != 0 || amount > customer.getAccount().getBalance());
        return true;
    }
    bool depositProcess(int &DepositAmount)
    {
        do
        {

            cout << "Minimum Deposit amount is $50." << endl;
            cout << "###################################" << endl;
            cout << "Please enter an amount in multiples of $50." << endl;
            cout << "###################################" << endl;
            cout << "Enter 0 to cancel." << endl;
            cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << "Deposit Amount: ";
            cin >> DepositAmount;

            if (DepositAmount == 0)
            {
                return false;
            }
            else if (DepositAmount < 50)
            {
                cout << "Invalid amount. The minimum withdrawal is $50." << endl;
            }
            else if (DepositAmount % 50 != 0)
            {
                cout << "Invalid amount. Please enter a multiple of $50." << endl;
            }

        } while (DepositAmount < 50 || DepositAmount % 50 != 0);
        return true;
    }
};
class processtransfer
{

public:
    bool transfercheckdata(userdata datacustomer, optional<customers> &customer2)
    {
        json customerData;
        ifstream file("bank_data_customers.json");
        if (!file.is_open())
        {
            return false;
        }
        file >> customerData;
        file.close();
        for (auto &c : customerData)
        {

            if (c["name"] == datacustomer.name && c["id"] == datacustomer.id)
            {
                customer2.emplace(c["name"], c["id"], c["phonenumber"], c["balance"], c["transactions"]);
                cout << "Recipient found: " << c["name"] << ", ID: " << c["id"] << endl;
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }
    customers transfercustomerdata()
    {

        optional<customers> customer2;
        userdata data;
        cout << "^^^^^^^^^^^^ Transaction Customer Data ^^^^^^^^^^^^" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Please enter the recipient's information." << endl;
            cout << "Recipient Name: ";
            getline(cin, data.name);
            // customer2.setName(name);
            cout << "Recipient ID: ";
            getline(cin, data.id);
            if (transfercheckdata(data, customer2))
            {

                return customer2.value();
            }
            else
            {
                cout << "Customer not found. Please check the name and ID and try again." << endl;
            }
        }
    }
};
class bankservice
{
public:
    userrepository user;
    processbankservice process;
    processtransfer transferprocess;
    void withdraw(customers &customer)
    {
        consoleui ui;
        int amount;
        while (true)
        {
            int choice = ui.withdrawMenu();
            if (choice == 1)
            {
                if (!process.withdrawaltransferProcess(customer, amount, "withdrawal"))
                {
                    return;
                }
                else
                {
                    customer.getAccount().withdrawal(amount);
                    string transaction = "Withdrawal Money, Amount: $" + to_string(amount);
                    customer.getAccount().addTransactions(transaction);
                    user.updateCustomerData(customer);
                    cout << "Processing your withdrawal..." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Withdrawal successful." << endl;
                    return;
                }
            }
            else if (choice == 2)
            {
                return;
            }
            else
            {
                cout << "Please enter 1 or 2" << endl;
            }
        }
    }
    void deposit(customers &customer)
    {
        consoleui ui;
        int depositAmount;
        while (true)
        {
            int choice = ui.depositMenu();
            if (choice == 1)
            {
                if (!process.depositProcess(depositAmount))
                {
                    return;
                }
                else
                {
                    customer.getAccount().deposit(depositAmount);
                    string transaction = "Deposit Money, Amount: $" + to_string(depositAmount);
                    customer.getAccount().addTransactions(transaction);
                    user.updateCustomerData(customer);
                    cout << "Processing your Deposit Money..." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Deposit successful." << endl;
                    return;
                }
            }
            else if (choice == 2)
            {
                return;
            }
            else
            {
                cout << "Please enter 1 or 2" << endl;
            }
        }
    }
    void securelogin(customers &customer)
    {
        consoleui ui;
        string id;
        customerdata securedata;
        cout << "^^^^^^^^^^^^  Secure Login  ^^^^^^^^^^^^\n";
        while (true)
        {
            int choice = ui.SecureLoginMenu();

            if (choice == 1)
            {
                cout << "Name: " << customer.getName() << " ID: " << customer.getId() << " Phone Number: " << customer.getPhoneNum()
                     << " Balance: " << "$" << customer.getAccount().getBalance() << endl;
            }
            else if (choice == 2)
            {
                cout << "^^^^^^^^^^^^ Current Data ^^^^^^^^^^^^" << endl;
                cout << "Name: " << customer.getName() << " ID: " << customer.getId() << " Phone Number: " << customer.getPhoneNum()
                     << " Balance: " << "$" << customer.getAccount().getBalance() << endl;
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                id = user.changedata(customer);
                cout << "ID after chage data: " << id << endl;
                user.updateCustomerChangeData(id, customer);
            }
            else if (choice == 3)
            {
                return;
            }
            else
            {
                cout << "Invaild choice, please try again" << endl;
            }
        }
    }

    void transfer(customers &customer)
    {
        consoleui ui;
        string id;
        int amount;
        cout << "^^^^^^^^^^^^  Transfer ^^^^^^^^^^^^\n";
        while (true)
        {
            int choice = ui.transferMenu();
            if (choice == 1)
            {
                customers recipient = transferprocess.transfercustomerdata();
                cout << "^^^^^^^^^^^^  Transfer Amount ^^^^^^^^^^^^\n";
                if (!process.withdrawaltransferProcess(customer, amount, "transfer"))
                {
                    cout << "^^^^^^^^^^^^ Transfer failed ^^^^^^^^^^^^" << endl;
                    return;
                }
                else
                {
                    customer.getAccount().withdrawal(amount);
                    recipient.getAccount().deposit(amount);
                    string transactionSender = "Transfer Money, Amount: $" + to_string(amount) + " to " + recipient.getName();
                    customer.getAccount().addTransactions(transactionSender);
                    string transactionRecipient = "Received Money, Amount: $" + to_string(amount) + " from " + customer.getName();
                    recipient.getAccount().addTransactions(transactionRecipient);
                    user.updatetransfer(customer, recipient);
                    cout << "Processing Your Transfer..." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Transfer successful." << endl;
                    return;
                }
            }
            else if (choice == 2)
            {
                return;
            }
            else
            {
                cout << "Invaild choice, please try again" << endl;
            }
        }
    }
    void transactionlogs(customers &customer)
    {
        cout << customer.getName() << '\n';
        cout << "========================" << '\n';
        // cout <<  customer.getAccount().getTransactions()[0] <<endl;
        for (string &transaction : customer.getAccount().getTransactions())
        {
            cout << "#######################" << '\n';
            cout << transaction << endl;
        }
    }
};
class technicaloperations
{
private:
    string OperationName;

public:
    void createaccount()
    {
        userrepository user;
        customerdata data;
        cin.ignore();
        cout << "Full Name: ";
        getline(cin, data.name);
        cout << "Enter your ID: ";
        cin >> data.id;
        cout << "Enter your PhoneNumber: ";
        cin >> data.phonenumber;
        data.balance = 0;
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        customers customer(data.name, data.id, data.phonenumber, data.balance, data.transaction);
        user.updatefilecreateaccount(customer);
        customer.viewaccount();
    }
    void dispalyallcustomers()
    {
        json customerData;
        ifstream file("bank_data_customers.json");
        if (!file.is_open())
        {
            return;
        }
        file >> customerData;
        file.close();
        for (auto &c : customerData)
        {
            cout << "Name: " << c["name"] << " ID: " << c["id"] << " Phone Number: " << c["phonenumber"]
                 << " Balance: $" << c["balance"] << endl;
            cout << "=======================================" << endl;
        }
        cout << "=======================================" << endl;
    }
    void searchaccount()
    {

        customerdata data;
        string balanceStr;
        string idSearch;
        do
        {
            cout << "Enter ID Account: ";
            cin >> idSearch;

            json customerData;
            ifstream file("bank_data_customers.json");
            if (!file.is_open())
            {
                return;
            }
            file >> customerData;
            file.close();
            for (auto &c : customerData)
            {
                if (c["id"] == idSearch)
                {
                    cout << "Name: " << c["name"] << " ID: " << c["id"] << " Phone Number: " << c["phonenumber"]
                         << " Balance: $" << c["balance"] << endl;
                    cout << "=======================================" << endl;
                    return;
                }
            }
            // file.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "=======================================" << endl;
            cout << "Not Found ID Account , Please enter vaild ID " << endl;
            cout << "=======================================" << endl;
            cout << " Etner 0 for exit: \n";
            if (idSearch == "0")
            {
                return;
            }

        } while (idSearch != data.id);
    }

    void deletaccount()
    {
        userrepository user;
        userdata data;
        optional<customers> customer;
        string delet;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Enter Name Account: ";
            getline(cin, data.name);
            cout << "Enter ID Account: ";
            getline(cin, data.id);
            if (user.customerscheckfile(data, customer))
            {
                cout << "^^^^^ Customer Data ^^^^^\n";
                cout << "Name : " << customer->getName() << " ID : " << customer->getId() << " Phone Number : " << customer->getPhoneNum() << "Balance : " << customer->getAccount().getBalance() << endl;
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
                cout << "Are you sure from delet account? (type Yes if you sure or No) : ";
                cin >> delet;
                while (true)
                {
                    if (delet == "Yes" || delet == "yes")
                    {
                        user.deleteAccountFile(customer);
                        cout << "The Account has been deleted successfully" << endl;
                        cout << "#######################################" << endl;
                        return;
                    }
                    else if (delet == "No" || delet == "no")
                    {
                        cout << "The Account has not been deleted " << endl;
                        cout << "#######################################" << endl;
                        return;
                    }
                    else
                    {
                        cout << "Please write Yes or No" << endl;
                        cout << "=======================================" << endl;
                    }
                }
            }

            else
            {
                cout << "=======================================" << endl;
                cout << "Not Found Naem and ID Account , Please enter vaild Data " << endl;
                cout << "=======================================" << endl;
            }
        }
    }
};

class authenticationservice
{
public:
    customers loginCustomer()
    {
        userrepository customercheck;
        userdata data;
        optional<customers> customer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Full Name: ";
            getline(cin, data.name);
            cout << "Enter your ID: ";
            getline(cin, data.id);
            cout << "=======================================" << endl;
            cout << "=======================================" << endl;
            if (customercheck.customerscheckfile(data, customer))
            {
                // customer = customers (data.name,data.id);
                return customer.value();
            }
            else
            {
                cout << "Please Enter True data" << endl;
            }
        }
    }
    admins loginAdmin()
    {
        userrepository customercheck;
        userdata data;
        optional<admins> admin;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true)
        {
            cout << "Full Name: ";
            getline(cin, data.name);
            cout << "Enter your ID: ";
            getline(cin, data.id);
            cout << "=======================================" << endl;
            cout << "=======================================" << endl;
            if (customercheck.adminscheckfile(data, admin))
            {
                // customer = customers (data.name,data.id);
                return admin.value();
            }
            else
            {
                cout << "Please Enter True data" << endl;
            }
        }
    }
};
class operationuser
{
public:
    consoleui user;
    technicaloperations techoperation;
    authenticationservice authent;
    bankservice service;
    int customer()
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
    int admin()
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
};
int main()
{
    consoleui user;
    operationuser operation;
    cout << "=======================================" << endl;
    cout << "=======================================" << endl;
    cout << "BANK MANAGEMENT SYSTEM" << endl;
    cout << "=======================================" << endl;
    while (true)
    {

        int usertype = user.mainMenu();
        if (usertype == 1)
        {
            int choice = operation.admin();
            if (choice == 0)
            {
                return 0;
            }
            else
            {
                continue;
            }
        }
        else if (usertype == 2)
        {
            int choice = operation.customer();
            if (choice == 0)
            {
                return 0;
            }
        }
        else if (usertype == 3)
        {
            cout << "Program closed.\n";
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}