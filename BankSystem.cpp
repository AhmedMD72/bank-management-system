#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;
using std::string;
struct customerdata {
        string name;
        string id;
        string phonenumber;
        int balance;
        string transaction1;
        string transaction2;
        string transaction3;
};
class people {
private:
        string Name;
        string ID;
        string PhoneNumber;
public:
       void setName (string name) {
        Name = name;
       }
       string getName() {
        return Name;
       }
       void setId (string id) {
        ID = id;
       }
       string getId() {
        return ID;
       }
       void setPhoneNum (string phonenum) {
        PhoneNumber = phonenum;
       }
       string getPhoneNum() {
        return PhoneNumber;
       }              
       people (string name , string id , string phonenumber)        {
            Name = name;
            ID = id;
            PhoneNumber = phonenumber;
        }
        people (string name , string id)        {
            Name = name;
            ID = id;
        }
};
class customers;
class operationsusers {
private:
            
            //customers& customer;

public:
            string OperationName;
            void setOperationName(string operationname) {
                OperationName = operationname;
            }
            string getOperationName() {
                return OperationName;
            }
            customerdata opsdata;
            string opsname;
            void setOperationdata(string name , string id , string phone , int balance , string transaction1 , string transaction2,  string transaction3) {
                opsdata.name = name;
                opsdata.id = id;
                opsdata.phonenumber = phone;
                opsdata.balance = balance;
                opsdata.transaction1 = transaction1;
                opsdata.transaction2 = transaction2;
                opsdata.transaction3 = transaction3;
            }
            customerdata getOperationdata() {
                return opsdata;
            }
            operationsusers(string operationname)   {
                OperationName = operationname;
            }

            bool processWithdrawalTransfer(int& withdrawaltransferAmount) {
                do {
                    
                    cout << "Minimum "  << getOperationName() << " amount is $50." << endl;
                    cout << "###################################" <<  endl;
                    cout << "Please enter an amount in multiples of $50." << endl;
                    cout << "###################################" <<  endl;
                    cout << "Enter 0 to cancel." << endl;
                    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<  endl;
                    cout << getOperationName() << " Amount: ";
                    cin >> withdrawaltransferAmount;

                    if (withdrawaltransferAmount == 0) {
                        return false;
                    }
                    else if ( withdrawaltransferAmount < 50 ) {
                        cout << "Invalid amount. The minimum " << getOperationName() << " is $50." << endl;
                    }
                    else if ( withdrawaltransferAmount % 50 !=0) {
                        cout << "Invalid amount. Please enter a multiple of $50." << endl;
                    }
                    else if ( withdrawaltransferAmount > opsdata.balance){
                        cout << "Insufficient balance." << endl;
                    }
                
                } while (withdrawaltransferAmount < 50 || withdrawaltransferAmount % 50 != 0 || withdrawaltransferAmount >  opsdata.balance);
                    return true;
            }
             bool processDeposit(int& DepositAmount) {
                do {
                    
                    cout << "Minimum Deposit amount is $50." << endl;
                    cout << "###################################" <<  endl;
                    cout << "Please enter an amount in multiples of $50." << endl;
                    cout << "###################################" <<  endl;
                    cout << "Enter 0 to cancel." << endl;
                    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<  endl;
                    cout << "Deposit Amount: ";
                    cin >> DepositAmount;

                    if (DepositAmount == 0) {
                        return false;
                    }
                    else if ( DepositAmount < 50 ) {
                        cout << "Invalid amount. The minimum withdrawal is $50." << endl;
                    }
                    else if ( DepositAmount % 50 !=0) {
                        cout << "Invalid amount. Please enter a multiple of $50." << endl;
                    }
                
                } while (DepositAmount < 50 || DepositAmount % 50 != 0);
                    return true;
            }
            void updateCustomerData() {
                    customerdata data;
                    string balanceStr;
                    ifstream oldfile("bank_data_customers.txt");
                    ofstream tempfile ("temp.txt");
                    while(getline(oldfile , data.name , '|')) {
                        getline(oldfile , data.id , '|');
                        getline(oldfile , data.phonenumber , '|');
                        getline(oldfile , balanceStr , '|');
                        data.balance = stoi(balanceStr);
                        getline(oldfile , data.transaction1, '|');
                        getline(oldfile , data.transaction2, '|');
                        getline(oldfile , data.transaction3 );
                        //oldfile.ignore(numeric_limits<streamsize>::max(), '\n');
                        if ( data.id == opsdata.id) {
                            cout << data.name << '|' << data.id << '|' << data.phonenumber << '|' << opsdata.balance << '|' << opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;
                            tempfile << data.name << '|' << data.id << '|' << data.phonenumber << '|' << opsdata.balance << '|' << opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;
                        }
                        else {
                            cout << data.name << '|' << data.id << '|' << data.phonenumber << '|' << data.balance << '|' << data.transaction1 << '|' << data.transaction2 << '|' << data.transaction3 << endl;
                            tempfile << data.name << '|' << data.id << '|' << data.phonenumber << '|' << data.balance << '|' << data.transaction1 << '|' << data.transaction2 << '|' << data.transaction3 << endl;
                        }
                    }
                    oldfile.close();
                    tempfile.close();
                    
                    remove ("bank_data_customers.txt");
                    rename ("temp.txt","bank_data_customers.txt");
                    cout << opsdata.name << "|| Balance: " << opsdata.balance << " || " <<  opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;
            }

            void withdraw() {
                int withdrawalAmount;
                int choice;
                cout << opsdata.name << "|| Balance: " << opsdata.balance << " || " <<  opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;

                while (true) {
                    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<  endl;
                    cout << "Do you need withdrawal or exit" << endl;
                    cout << "1.Withdrawal" << endl;
                    cout << "2.Exit" << endl;
                    cout << "Please chocie: " ;
                    cin >> choice;
                    if (choice == 1) {
                        break;
                    }
                    else if (choice == 2) {
                        return;
                    }
                    else {
                        cout << "Please enter 1 or 2" << endl;
                    }
                }

                    if ( !processWithdrawalTransfer(withdrawalAmount) ) {
                        return; 
                    }
                    else {
                        opsdata.balance -= withdrawalAmount; 
                        opsdata.transaction3 = opsdata.transaction2;
                        opsdata.transaction2 = opsdata.transaction1;
                        opsdata.transaction1 = "Withdrawal Money, Amount: $" + to_string(withdrawalAmount);
                        updateCustomerData();
                        cout << "Processing your withdrawal..." << endl;
                        this_thread::sleep_for(chrono::seconds(2));
                        cout << "Withdrawal successful." << endl; 
                    }
                    return;
            }
            void deposit() {
                int depositAmount;
                int choice;
                cout << opsdata.name << "|| Balance: " << opsdata.balance << " || " <<  opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;

                while (true) {
                    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<  endl;
                    cout << "Do you need deposit or exit" << endl;
                    cout << "1.Deposit" << endl;
                    cout << "2.Exit" << endl;
                    cout << "please chocie: " ;
                    cin >> choice;
                    if (choice == 1) {
                        break;
                    }
                    else if (choice == 2) {
                        return;
                    }
                    else {
                        cout << "Please enter 1 or 2" << endl;
                    }
                }

                    if ( !processDeposit(depositAmount) ) {
                        return; 
                    }
                    else {
                        opsdata.balance += depositAmount; 
                        opsdata.transaction3 = opsdata.transaction2;
                        opsdata.transaction2 = opsdata.transaction1;
                        opsdata.transaction1 = "Deposit Money, Amount: $" + to_string(depositAmount);
                        updateCustomerData();
                        cout << "Processing your Deposit Money..." << endl;
                        this_thread::sleep_for(chrono::seconds(2));
                        cout << "Deposit successful." << endl; 
                    }
                    return;
            }
            void updateCustomerChangeData(string id) {
                    customerdata data;
                    string balanceStr;
                    ifstream oldfile("bank_data_customers.txt");
                    ofstream tempfile ("temp.txt");
                    while(getline(oldfile , data.name , '|')) {
                        getline(oldfile , data.id , '|');
                        getline(oldfile , data.phonenumber , '|');
                        getline(oldfile , balanceStr , '|');
                        data.balance = stoi(balanceStr);
                        getline(oldfile , data.transaction1, '|');
                        getline(oldfile , data.transaction2, '|');
                        getline(oldfile , data.transaction3 );
                        //oldfile.ignore();
                        if ( data.id == opsdata.id) {
                            opsdata.id = id;
                            cout << " ID opsdata :" << opsdata.id << " ID : " << id << endl;
                            tempfile << opsdata.name << '|' << opsdata.id  << '|' << opsdata.phonenumber << '|' << data.balance << '|' << data.transaction1 << '|' << data.transaction2 << '|' << data.transaction3 << endl;
                        }
                        else {
                            tempfile << data.name << '|' << data.id << '|' << data.phonenumber << '|' << data.balance << '|' << data.transaction1 << '|' << data.transaction2 << '|' << data.transaction3 << endl;
                        }

                    }
                    oldfile.close();
                    tempfile.close();
                    
                    remove ("bank_data_customers.txt");
                    rename ("temp.txt","bank_data_customers.txt");
                    cout << opsdata.name << "|| Balance: " << opsdata.balance << " || " << opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;
            }            
            string changedata() {
                string name;
                string id;
                string phone;
                int choice;
                cout << "^^^^^^^^^^^^ New Data ^^^^^^^^^^^^"  << endl;
                while (true) {
                    cout << "please select the data type." << endl;
                    cout << "1.Name." << endl;
                    cout << "2.ID." << endl;
                    cout << "3.Phone Number." << endl;
                    cout << "4.Exit." << endl;
                    cout << "Enter choice: ";
                    if (!(cin >> choice)) {
                            cout << "Invalid input. Please enter a number.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                    }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');    
                switch(choice) {
                    case 1 : {
                                    cout << "New Name: ";
                                    getline(cin, name);
                                    opsdata.name = name;
                                    break;
                    }
                    case 2 : {
                                    cout << "New ID: ";
                                    getline(cin, id);
                                    break;
                    }
                    case 3 : {
                                    cout << "New Phone Number: ";
                                    getline(cin , phone);
                                    opsdata.phonenumber = phone;
                                    break;
                    }
                    case 4 : {
                                if (id.empty()) {
                                return opsdata.id;
                                }
                                else {
                                        cout << "ID chage data: " << id << endl;
                                        return id;
                                }
                    }
                    default: cout << "Invalid choice, Please try again\n" ;
                }

            }

            }
            customerdata securelogin() {
            int choice;
            string id;
            customerdata securedata;
            cout << "^^^^^^^^^^^^  Secure Login  ^^^^^^^^^^^^\n";
            while (true) {
                cout << "Please choice the  operation" << endl;
                cout << "1.Show data." << endl;
                cout << "2.Change data." << endl;
                cout << "3.Exit." << endl;
                cout << "Enter choice: ";
                if (!(cin >> choice)) {
                    cout << "Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if ( choice == 1) {
                    cout << "Name: " << opsdata.name <<  " ID: "<< opsdata.id << " Phone Number: "<< opsdata.phonenumber
                    << " Balance: " << "$"<< opsdata.balance   << endl;
                }
                else if ( choice == 2) {
                    cout << "^^^^^^^^^^^^ Current Data ^^^^^^^^^^^^"  << endl;
                    cout << "Name: " << opsdata.name <<  " ID: "<< opsdata.id << " Phone Number: "<< opsdata.phonenumber
                    << " Balance: " << "$"<< opsdata.balance   << endl;
                    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"  << endl;
                    id = changedata();
                    cout << "ID after chage data: " << id << endl;
                    updateCustomerChangeData(id);

                }
                else if ( choice == 3) {
                    securedata.name = opsdata.name;
                    securedata.id = opsdata.id;
                    securedata.phonenumber = opsdata.phonenumber;
                    securedata.balance = opsdata.balance;
                    securedata.transaction1 = opsdata.transaction1;
                    securedata.transaction2 = opsdata.transaction2;
                    securedata.transaction3 = opsdata.transaction3;
                    return securedata;
                }
                else {
                    cout << "Invaild choice, please try again" << endl;
                }
            }

            

            }
            bool transfercheckdata(customerdata& transferreddata) {
                customerdata data;
                string balancestr;
                ifstream file("bank_data_customers.txt");
                while (getline(file , data.name , '|')) {
                    getline(file , data.id , '|');
                    getline(file , data.phonenumber , '|');
                    getline(file , balancestr , '|');
                    data.balance =stoi(balancestr);
                    getline(file , data.transaction1, '|');
                    getline(file , data.transaction2, '|');
                    getline(file , data.transaction3 );
                    //file.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (data.name == transferreddata.name && data.id == transferreddata.id) {
                        transferreddata.phonenumber = data.phonenumber;
                        transferreddata.balance = data.balance;
                        transferreddata.transaction1 = data.transaction1;
                        transferreddata.transaction2 = data.transaction2;
                        transferreddata.transaction3 = data.transaction3;
                        cout << "Recipient found: " << data.name << ", ID: " << data.id << endl;

                        return true;
                    }
                    else {
                        continue;
                    }
                }
                file.close();
                return false;
            }
            customerdata transfercustomerdata() {
                customerdata transferreddata;
                string name;
                string id;
                string phone;
                cout << "^^^^^^^^^^^^ Transaction Customer Data ^^^^^^^^^^^^"  << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                while (true) {
                    cout << "Please enter the recipient's information." << endl;
                    cout << "Recipient Name: ";
                    getline(cin , transferreddata.name);
                    cout << "Recipient ID: ";
                    getline(cin , transferreddata.id);
                    if(transfercheckdata(transferreddata)) {

                        return transferreddata;
                    }
                    else {
                        cout << "Customer not found. Please check the name and ID and try again." << endl;
                    }
                }
                
            }
            void updatetransfer(customerdata transferreddata) {
                    customerdata data;
                    string balanceStr;
                    ifstream oldfile("bank_data_customers.txt");
                    ofstream tempfile ("temp.txt");
                    while(getline(oldfile , data.name , '|')) {
                        getline(oldfile , data.id , '|');
                        getline(oldfile , data.phonenumber , '|');
                        getline(oldfile , balanceStr , '|');
                        getline(oldfile , data.transaction1, '|');
                        getline(oldfile , data.transaction2, '|');
                        getline(oldfile , data.transaction3 );
                        data.balance = stoi(balanceStr);

                        //oldfile.ignore(numeric_limits<streamsize>::max(), '\n');
                        if ( data.id == opsdata.id) {
                            tempfile << opsdata.name << '|' << opsdata.id << '|' << opsdata.phonenumber << '|' << opsdata.balance << '|' << opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;
                        }
                        else if ( data.id == transferreddata.id) {
                                tempfile << transferreddata.name << '|' << transferreddata.id << '|' << transferreddata.phonenumber << '|' << transferreddata.balance << '|' << transferreddata.transaction1 << '|' << transferreddata.transaction2 << '|' << transferreddata.transaction3 << endl;
                        }
                        else {
                            tempfile << data.name << '|' << data.id << '|' << data.phonenumber << '|' << data.balance << '|' << data.transaction1 << '|' << data.transaction2 << '|' << data.transaction3 << endl;
                        }
                    }
                    oldfile.close();
                    tempfile.close();
                    remove ("bank_data_customers.txt");
                    rename ("temp.txt","bank_data_customers.txt");
                    cout << opsdata.name << "|| Balance: " << opsdata.balance << " || " << opsdata.transaction1 << '|' << opsdata.transaction2 << '|' << opsdata.transaction3 << endl;
            }
            void transfer(){
            customerdata transferreddata;
            int choice;
            string id;
            int transferamount; 
            cout << "^^^^^^^^^^^^  Transfer ^^^^^^^^^^^^\n";
            while (true) {
                cout << "Please choice the  operation" << endl;
                cout << "1.Transfer." << endl;
                cout << "2.Exit." << endl;
                cout << "Enter choice: ";
                
                if (!(cin >> choice)) {
                    cout << "Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if ( choice == 1) {
                    transferreddata = transfercustomerdata();
                    cout << "^^^^^^^^^^^^  Transfer Amount ^^^^^^^^^^^^\n";
                    if(!processWithdrawalTransfer(transferamount)) {
                            cout << "^^^^^^^^^^^^ Transfer failed ^^^^^^^^^^^^" << endl;
                            return;
                    }
                    else {
                        opsdata.balance -= transferamount;
                        transferreddata.balance += transferamount;
                        opsdata.transaction3 = opsdata.transaction2;
                        opsdata.transaction2 = opsdata.transaction1;
                        opsdata.transaction1 = "Transfer Money, Amount: $" + to_string(transferamount) + " to " + transferreddata.name;
                        transferreddata.transaction3 = transferreddata.transaction2;
                        transferreddata.transaction2 = transferreddata.transaction1;
                        transferreddata.transaction1 = "Received Money, Amount: $" + to_string(transferamount) + " from " + opsdata.name;
                        updatetransfer( transferreddata );
                        cout << "Processing Your Transfer..." << endl;
                        this_thread::sleep_for(chrono::seconds(2));
                        cout << "Transfer successful." << endl; 
                        return;
                    }
                }
                else if ( choice == 2) {
                    return;
                }
                else {
                    cout << "Invaild choice, please try again" << endl;
                }
            }

            }
            void transactionlogs () {
                cout << opsdata.name  << '\n' << "#######################"<<  '\n' 
                << " 1. " << opsdata.transaction1 << '\n' << "#######################"<<  '\n' 
                << " 2. " << opsdata.transaction2 << '\n' << "#######################"<<  '\n'
                << " 3. " << opsdata.transaction3 << '\n' << "#######################"<<  '\n' << endl;
            }

};

class customers : public people {
private:
        int Balance;
        string Transaction1;
        string Transaction2;
        string Transaction3;
public:
        void setBalance(int balance)        {
        Balance = balance;
        }
        int getBalance () {
        return Balance;
        }

        void setTransactions(string transaction1 ,string transaction2 ,string transaction3)        {
        Transaction1 = transaction1;    
        Transaction2 = transaction2;   
        Transaction3 = transaction3;   
        }
        string getTransaction1() {
        return Transaction1;
        }

        string getTransaction2() {
            return Transaction2;
        }

        string getTransaction3() {
            return Transaction3;
        }
        customers(string name , string id, string phone_num, int balance , string transaction1 ,string transaction2 , string transaction3 ) : people(name , id , phone_num) {
            Balance = balance;
            Transaction1 = transaction1;
            Transaction2 = transaction2;
            Transaction3 = transaction3;


        }
        customers(string name , string id) : people(name , id ) {

        }
        void createaccount(){
            ofstream file("bank_data_customers.txt", ios::app);
            file << getName() <<"|"<< getId() << "|"<< getPhoneNum() << "|" << getBalance()  <<  "|" << getTransaction1() <<  "|" << getTransaction2() <<  "|" << getTransaction3() << endl;
            file .close();
        }
        void viewaccount() {
            cout << "#######################################" <<  endl;
            cout << "Weclcome " << getName() << " " <<  " " << endl;
            cout << "#######################################" <<  endl;
        }
        customerdata checkfilecustomer( ) {
                customerdata data; 
                string balancestr;
                ifstream file ("bank_data_customers.txt");
                while ( getline( file , data.name , '|' )) {
                    getline( file , data.id , '|' );
                    getline( file , data.phonenumber , '|' );
                    getline( file , balancestr , '|' );
                    data.balance = stoi(balancestr);
                    getline(file , data.transaction1, '|' );
                    getline(file , data.transaction2, '|' );
                    getline(file , data.transaction3 );
                    //file.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << getId() << "--->" << data.id << endl;
                    cout << "==========" <<  endl;
                    
                    if ( getId() == data.id) {
                        cout << getId() << "--->" << data.id << endl;
                        customers customer ( data.name, data.id ,  data.phonenumber , data.balance , data.transaction1 , data.transaction2 , data.transaction3);
                        cout << customer.getName() <<"|"<< customer.getId() << "|"<< customer.getPhoneNum() << "|" << "$"<< customer.getBalance()
                        <<  "|" << customer.getTransaction1()  <<  "|" << customer.getTransaction2() <<  "|" << customer.getTransaction3() << endl;
                        cout << "=======================================" <<  endl;
                        return data ;
                    }
                }
                return data;
            }

        void operationcustomers() {
            int choice;
            do {
                cout << "Please Choice the operation\n";
                cout << "=======================================" <<  endl;
                cout << "1. Withdraw Money\n";
                cout << "2. Deposit Money\n";
                cout << "3. Secure Login\n";
                cout << "4. Transfer Money\n";
                cout << "5. Transaction Logs\n";
                cout << "6. Exit\n";
                cout << "=======================================" <<  endl;
                cout << "=======================================" <<  endl;
                cout << "Enter Choice: ";
                if (!(cin >> choice)) {
                    cout << "Invalid input. Please enter a number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                switch (choice) {
                    case 1: {   
                                    customerdata data = checkfilecustomer();
                                    operationsusers ops ("Withdraw") ;
                                    ops.setOperationdata(data.name , data.id , data.phonenumber , data.balance , data.transaction1 ,data.transaction2 , data.transaction3 );
                                    ops.withdraw();
                                    break;
                    }
                    case 2: {
                                    customerdata data = checkfilecustomer();
                                    operationsusers ops ("Deposit") ;
                                    ops.setOperationdata(data.name , data.id , data.phonenumber , data.balance , data.transaction1 ,data.transaction2 , data.transaction3);
                                    ops.deposit();
                                    break;
                    }
                    case 3: {
                                    customerdata data = checkfilecustomer();
                                    operationsusers ops ("Secure Login") ;
                                    ops.setOperationdata(data.name , data.id , data.phonenumber , data.balance , data.transaction1 ,data.transaction2 , data.transaction3);
                                    data = ops.securelogin();
                                    setName(data.name);
                                    setId(data.id);
                                    setPhoneNum(data.phonenumber);
                                    setBalance(data.balance);
                                    setTransactions( data.transaction1 ,data.transaction2 , data.transaction3 );
                                    cout << "Name: " << data.name <<  " ID: "<< data.id << " Phone Number: "<< data.phonenumber
                                    << " Balance: " << "$"<< data.balance   << endl;
                                    break;
                                }
                    case 4: {
                                    customerdata data = checkfilecustomer();
                                    operationsusers ops ("Transfer") ;

                                    ops.setOperationdata(data.name , data.id , data.phonenumber , data.balance , data.transaction1 ,data.transaction2 , data.transaction3);
                                    ops.transfer();
                                    break;
                    }
                    case 5: {
                                    customerdata data = checkfilecustomer();
                                    operationsusers ops ("Transaction Logs") ;
                                    ops.setOperationdata(data.name , data.id , data.phonenumber , data.balance , data.transaction1 ,data.transaction2 , data.transaction3);
                                    ops.transactionlogs();
                                    break;
                                }
 
                    case 6:     cout << "############################################" <<  endl; 
                                    cout << "Program closed\n";
                                    cout << "############################################" <<  endl; 
                                    exit(0);
                    default :
                                cout << "############################################" <<  endl; 
                                cout << "Invalid choice\n" ;
                                cout << "############################################" <<  endl; 
                }
            } while( choice!= 6);
            
        }

};

class operations  {
private:
         string OperationName;   
public:
        void setOperationName(string operationname)        {
        OperationName = operationname;
        }  
        string getOperationName () {
        return OperationName;
        }
        operations(string operationname) {
            OperationName = operationname;
        }
        void createaccountfun () {
                customerdata data;
                cin.ignore();
                cout << "Full Name: " ;
                getline(cin , data.name);
                cout << "Enter your ID: " ;
                cin >> data.id;
                cout << "Enter your PhoneNumber: " ;
                cin >> data.phonenumber;
                data.balance = 0;
                cout << "=======================================" <<  endl;
                cout << "=======================================" <<  endl;
                customers c (data.name , data.id , data.phonenumber, data.balance, data.transaction1 ,data.transaction2 , data.transaction3);
                c.createaccount();
                c.viewaccount();
        }
        void dispalyallcustomers(){
            customerdata data;
            string balanceStr;

            ifstream file("bank_data_customers.txt");
            while ( getline(file , data.name ,'|') ){
                getline(file, data.id,'|');
                getline(file, data.phonenumber,'|');
                getline(file, balanceStr,'|');
                data.balance =stoi(balanceStr);
                getline(file, data.transaction1,'|');
                getline(file, data.transaction2,'|');
                getline(file, data.transaction3);
                //file.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Name: " << data.name<< " ID: "<< data.id << " Phone Number: " << data.phonenumber
                << " Balance: $" << data.balance << endl;
                cout << "=======================================" <<  endl;
            }
            cout << "=======================================" <<  endl;
        }
        void searchaccount(){

            customerdata data;
            string balanceStr;
            string idSearch;
            do {
            cout << "Enter ID Account: ";
            cin >> idSearch;

            ifstream file("bank_data_customers.txt");
            while ( getline(file , data.name ,'|') ){
                getline(file, data.id,'|');
                getline(file, data.phonenumber,'|');
                getline(file, balanceStr,'|');
                data.balance =stoi(balanceStr);
                getline(file, data.transaction1,'|');
                getline(file, data.transaction2,'|');
                getline(file, data.transaction3);
                //file.ignore(numeric_limits<streamsize>::max(), '\n');
                if (idSearch == data.id) {
                    cout << "Name: " << data.name << " ID: "<< data.id << " Phone Number: " << data.phonenumber
                    << " Balance: $" << data.balance << endl;
                    cout << "=======================================" <<  endl;
                    return;
                }
            }
            
                cout << "=======================================" <<  endl;
                cout << "Not Found ID Account , Please enter vaild ID " <<  endl;
                cout << "=======================================" <<  endl;
                cout <<  " Etner 0 for exit: \n";
                if (idSearch == "0") {
                    return;
                }
                
            }while(idSearch != data.id);
        
        }

        void deletaccount(){
            customerdata data;
            string balanceStr;
            string delet;
            bool y = true;
            string nameDelet;
            string idDelet;

            do {
            cin.ignore();    
            cout << "Enter Name Account: ";
            getline(cin, nameDelet);
            cout << "Enter ID Account: ";
            cin >> idDelet;

            ifstream oldfile("bank_data_customers.txt");
            ofstream newfile("temp.txt");
            while ( getline(oldfile , data.name ,'|') ){
                getline(oldfile, data.id,'|');
                getline(oldfile, data.phonenumber,'|');
                getline(oldfile, balanceStr,'|');
                data.balance = stoi(balanceStr);
                getline(oldfile, data.transaction1,'|');
                getline(oldfile, data.transaction2,'|');
                getline(oldfile, data.transaction3);
                //oldfile.ignore(numeric_limits<streamsize>::max(), '\n');
                if (idDelet !=  data.id) {
                    newfile << data.name << '|' << data.id << '|' << data.phonenumber << '|' << data.balance << data.transaction1 << '|' << data.transaction2 << '|' << data.transaction3 << '|' << endl;
                }
                else if ( idDelet ==  data.id && nameDelet ==  data.name) {
                    y = false;
                    cout << "Data of Customer " << nameDelet <<  endl;
                    cout << "Name: " <<  data.name<< " \nID: "<<  data.id << " \nPhone Number: " <<  data.phonenumber
                    << "\nBalance: $" <<  data.balance << endl;
                    cout << "=======================================" <<  endl;
                    while (true) {
                    cout << "Are you sure from delet account? (type Yes if you sure or No) : " ;
                    cin >> delet;
                    if ( delet == "Yes" || delet == "yes") {
                        cout << "The Account has been deleted successfully" <<  endl;
                        cout << "#######################################" <<  endl;
                        break;
                    }
                    else if (delet == "No" || delet == "no") {
                        cout << "Name: " <<  data.name << "\nID: "<<  data.id << "\nPhone Number: " <<  data.phonenumber 
                        << "\nBalance: $" <<  data.balance << endl;
                        newfile << data.name << '|' << data.id << '|' << data.phonenumber << '|' << data.balance << data.transaction1 << '|' << data.transaction2 << '|' << data.transaction3 << '|' << endl;
                        break;
                    }
                    else {
                        cout << "Please write Yes or No" << endl;
                        cout << "=======================================" <<  endl;
                    }
                    }

               }
            //    else {
            //      cout << "username or id is wrong\n";
            //    }
            }
            oldfile.close();
            newfile.close();

            remove ("bank_data_customers.txt");
            rename ("temp.txt","bank_data_customers.txt");

            if (y == true)  {
                cout << "=======================================" <<  endl;
                cout << "Not Found Naem and ID Account , Please enter vaild Data " <<  endl;
                cout << "=======================================" <<  endl;
            }

            }while(y == true);
        }
};
class admins : public people {
private:
    string JobTitle;  
public:  
    void setJobTitle (string jobtitle) {
        JobTitle = jobtitle;
    }   
    string getJobTitle() {
        return JobTitle;
    } 
    admins (string name , string id , string phonenumber , string jobtitle) : people(name, id, phonenumber)
    {
      JobTitle = jobtitle;  
    }
    admins (string name , string id) : people(name , id ) {

    }
    void identification() {
        cout << "Welcome " << getName() << " Now, You are in the Admins Page\nYou can select opeartion do you need" << endl;
        // cout << "Role: " << JobTitle << endl;
        // cout << "ID: " << getId() << endl;
        // cout << "Phone Number: " << getPhoneNum() << endl;
        cout << "=======================================" <<  endl;
       
    }
    void OperationsDepartment(){
    int n; 
    do {
     cout << "Please Choice the operation " <<  endl;
     cout << "1. Create New Account" <<  endl;
     cout << "2. Display All Customers" <<  endl;
     cout << "3. Search Account by ID" <<  endl;
     cout << "4. Delet Account" <<  endl;
     cout << "5. Exit" <<  endl;
     cout << "=======================================" <<  endl;
     cout << "=======================================" <<  endl;
     
     cout << "Enter Choice: " ;
     cin >> n;
     switch(n) {
        case 1 :{
                        operations ops = operations ("createacountt");
                        ops.createaccountfun();
                        break;
        }  
        case 2 :  { 
                        operations ops = operations ("dispalyaccounts");
                        ops.dispalyallcustomers();
                        break;
        }
        
        case 3 :  {
                        operations ops ("searchaccount");
                        ops.searchaccount();
                        break;
        }
        case 4 : {
                        operations ops  ("deletaccount");
                        ops.deletaccount();
                        break;
        }
        case 5 : { 
                        cout << "############################################" <<  endl; 
                        cout << "Program closed\n";
                        cout << "############################################" <<  endl; 
                        exit(0);
        }
        default :
                cout << "############################################" <<  endl; 
                cout << "Invalid choice\n" ;
                cout << "############################################" <<  endl; 
    }


        } while ( n != 5);


    }



};

struct userdata {
    string name_user;
    string id_user;
};
userdata getUserData() {
    userdata data;
    cout << "Full Name: " ;
    cin.ignore();
    getline (cin , data.name_user);
    cout << "Enter your ID: " ;
    cin >> data.id_user;
    cout << "=======================================" <<  endl;
    cout << "=======================================" <<  endl;
    //cout << data.name_user << " ## " << data.id_user << endl;

    return data;

}
bool  checkfile(userdata Data ,string User) {
    //string number;
    string name;
    string id;
    // string phonenumber;
    // string role;
    ifstream file("bank_data_" + User + ".txt");
    while ( getline(file , name , '|') ) {
        //file.ignore();
        
        getline(file , id , '|');

        file.ignore(numeric_limits<streamsize>::max(), '\n');
        //cout << "2 "<< name << " " << id << endl;
        // getline(file , phonenumber , '|');
        // getline(file , role);
                        // cout << "ID: " << id << endl;
                        // cout << "Name: " << name << endl;
        //cout << Data.name_user << " || " << name << " ### "<< Data.id_user << " || " << id <<  endl;                
        if ( Data.name_user == name && Data.id_user == id) {
                cout << Data.name_user << " || " << name << " ### "<< Data.id_user << " || " << id <<  endl;
                return true;
        }
    }
    return false;
}
void DataEntery(string user) {
    userdata data;
    bool b = false;


    
    do {
    data = getUserData();   
    b = checkfile(data , user);



        if ( !b ) {
                cout << "=======================================" <<  endl;
                cout << "Your data are not " + user + " data Please Enter true data:\n" ;
                cout << "=======================================" <<  endl;
        }

    }while( !b );

        if (user == "admins") {
                admins admin1 = admins (data.name_user , data.id_user);
                admin1.identification();
                admin1.OperationsDepartment();
        }
        else {
                customers customer  (data.name_user , data.id_user);
                customer.viewaccount();
                customer.operationcustomers();
        }

}

int main() {
    cout << "=======================================" <<  endl;
    cout << "=======================================" <<  endl;
    cout << "BANK MANAGEMENT SYSTEM" <<  endl;
    cout << "=======================================" <<  endl;
    int choice;

do {
    cout << "Please Choice 1 or 2 " <<  endl;
    cout << "1. Admin" <<  endl;
    cout << "2. Customer" <<  endl;
    cout << "=======================================" <<  endl;


    cout << "Enter Choice: " ;
    if(!(cin >> choice)) {
        cout << "Invalid input. Please enter a number." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }
    if (choice == 1) {
            DataEntery("admins");
    }
    else  if (choice == 2){
            DataEntery("customers");
    }
    else {
            cout << "Invalid choice, Please try again\n" ;
    }

} while ( true);



    return 0;

}