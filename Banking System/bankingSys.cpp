#include<iostream>
#include<fstream>
#include<vector>

class Account {

    std :: string firstName;
    std :: string lastName;
    int balance;
    int accountNo;


    // To track account number.
    static int accountCount;

    // For storing account information.
    std :: vector<Account> accountList = {};

    public:

    // Constructors.
    Account();
    Account(std :: string firstName, std :: string lastName, int balance);
    Account(std :: string firstName, std :: string lastName, int accountNo, int balance);

    // Functions.
    void openAccount();
    void accountEnquiry(int accNumber);
    void deposit(int accNumber);
    void withdrawal(int accNumber);
    void closeAccount(int accNumber);
    void showAllAccount();
    int accountNoPromopt();
    int quit();

    // Ofstream overloading for storing account data as file.
    friend std :: ofstream & operator << (std :: ofstream &ofs, Account &ac);

    // Output stream operator overloading for displaying objects of Account class.
    friend std :: ostream & operator << (std :: ostream &print, Account &ac);
};

int Account :: accountCount = 1000;

// Default constructor.
Account :: Account() {

    std :: string firstName;
    std :: string lastName;
    int accountNo;
    int balance;

    int stroedAccountHighestNumber = 1000;

    std :: ifstream ifs("AccountInfo.txt");

    if(!ifs) {

        std :: cout << "Couldn't open account info file." << std :: endl;
    }

    while (ifs >> firstName >> lastName >> accountNo >> balance) {

        accountList.push_back(Account(firstName, lastName, accountNo, balance));

        if (accountNo > stroedAccountHighestNumber) {

            stroedAccountHighestNumber = accountNo;
        }
    }

    accountCount = stroedAccountHighestNumber;

    ifs.close();
}

// Parameterized constructor.
Account :: Account(std :: string firstName, std :: string lastName, int balance) {

    ++accountCount;

    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> balance = balance;
    this -> accountNo = accountCount;
    }

// Parameterized constructor for retreiving stored account info in the file.
Account :: Account(std :: string firstName, std :: string lastName, int accountNo, int balance) {

    
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> balance = balance;
    this -> accountNo = accountNo;
}

// Function for opening a new account.
void Account :: openAccount() {

    std :: string firstName;
    std :: string lastName;
    int initialDeposit;

    std :: cout << "Enter your first name : ";
    std :: cin >> firstName;
    std :: cout << "Enter your last name : ";
    std :: cin >> lastName;
    std :: cout << "Initial deposit amount : ";
    std :: cin >> initialDeposit;

    accountList.push_back(Account(firstName, lastName, initialDeposit));

    std :: cout << "Account creation successfull!" << std :: endl;
    std :: cout << "Account number : " << accountCount << std :: endl;
    std :: cout << std :: endl;
}

// Function for displaying information of an account.
void Account :: accountEnquiry(int accNumber) {

    for(int i = 0; i < accountList.size(); i++) {

        if(accountList.at(i).accountNo == accNumber) {

            std :: cout << accountList.at(i) << std :: endl;
            return;
        }
    }
    std :: cout << "No account found. Please try again." << std :: endl;
}

// Function for depositing to selected account.
void Account :: deposit(int accNumber) {
    
    for(int i = 0; i < accountList.size(); i++) {

        if(accountList.at(i).accountNo == accNumber) {

            int amount;

            std :: cout << "Enter deposit amount : ";
            std :: cin >> amount;
            std :: cout << std :: endl;

            accountList.at(i).balance += amount;

            std :: cout << "Deposition successfull!" << std :: endl;
            std :: cout << "New balance : " << accountList.at(i).balance << std :: endl;
            std :: cout << std :: endl;

            return;
        }
    }
    std :: cout << "No account found. Please try again." << std :: endl;
}

// Function for withdrawing from selected account.
void Account :: withdrawal(int accNumber) {

    for(int i = 0; i < accountList.size(); i++) {

        if(accountList.at(i).accountNo == accNumber) {

            int amount;

            std :: cout << "Enter amount to be withdrawn : ";
            std :: cin >> amount;
            std :: cout << std :: endl;

                return;
            if(amount > accountList.at(i).balance) {

                std :: cout << "Amount exceeds available account balance." << std :: endl;
            }

            accountList.at(i).balance -= amount;

            std :: cout << "Withdrawal successfull!" << std :: endl;
            std :: cout << "New balance : " << accountList.at(i).balance << std :: endl;
            std :: cout << std :: endl;

            return;
        }
    }
    std :: cout << "No account found. Please try again." << std :: endl;
}

// Function for closing an account.
void Account :: closeAccount(int accNumber) {

    for(int i = 0; i < accountList.size(); i++) {

        if(accountList.at(i).accountNo == accNumber) {

            accountList.erase(accountList.begin() + i);
            std :: cout << "Account closing successful." << std :: endl;
            std :: cout << std :: endl;
            return;
        }
    }
    std :: cout << "No account found. Please try again." << std :: endl;
}

// Function for displaying list of all accounts.
void Account :: showAllAccount() {

    if(accountList.size() == 0) {

        std :: cout << "No accounts opened yet." << std :: endl;
        std :: cout << std :: endl;
    }
    else {

        std :: vector<Account> :: iterator itr;

        for(int i = 0; i < accountList.size(); i++) {

            std :: cout << accountList.at(i) << std :: endl;
        }
    }
}

// Function for promopt of taking account number.
int Account :: accountNoPromopt() {

    int accountNumber;

    std :: cout << "Enter account number : ";
    std :: cin >> accountNumber;

    std :: cout << std :: endl;

    return accountNumber;
}

// Function for quitting the program.
int Account :: quit() {

    std :: ofstream ofs("AccountInfo.txt", std :: ios :: trunc);

    for (int i = 0; i < accountList.size(); i++) {

        ofs << accountList.at(i);
    }

    ofs.close();

    std :: cout << "Have a great day!" << std :: endl;
    return 0;
}

// Output stream operator overloading for displaying objects of Account class.
std :: ostream & operator << (std :: ostream &print, Account &ac) {

    print << "Account holder first name : " << ac.firstName << std :: endl;
    print << "Account holder last name : " << ac.lastName << std :: endl;
    print << "Account number : " << ac.accountNo << std :: endl;
    print << "Balance : " << ac.balance << std :: endl;
    return print;
}

// Ofstream overloading for storing account data as file.
std :: ofstream & operator << (std :: ofstream &ofs, Account &ac) {
    
    ofs << ac.firstName << std :: endl;
    ofs << ac.lastName << std :: endl;
    ofs << ac.accountNo << std :: endl;
    ofs << ac.balance << std :: endl;
    return ofs;
}

// Main program.
int main() {
    
    int selection = 0;

    Account ac;

    while(selection != 7) {
    std :: cout << "***Banking System***" << std :: endl;
    std :: cout << std :: endl;
    std :: cout << "\tSelect an option" << std :: endl;
    std :: cout << "\t1. Open an Account" << std :: endl;
    std :: cout << "\t2. Account Enquiry" << std :: endl;
    std :: cout << "\t3. Deposit" << std :: endl;
    std :: cout << "\t4. Withdrawal" << std :: endl;
    std :: cout << "\t5. Close an Account" << std :: endl;
    std :: cout << "\t6. Show all Account" << std :: endl;
    std :: cout << "\t7. Quit" << std :: endl;
    std :: cout << std :: endl;
    std :: cout << "Enter your choice : ";
    std :: cin >> selection;
    std :: cout << std :: endl;
    
    switch (selection) {

        int accountNumber;

        case 1 :
        ac.openAccount();
        break;

        case 2 :
        accountNumber = ac.accountNoPromopt();
        ac.accountEnquiry(accountNumber);
        break;

        case 3 :
        accountNumber = ac.accountNoPromopt();
        ac.deposit(accountNumber);
        break;

        case 4 :
        accountNumber = ac.accountNoPromopt();
        ac.withdrawal(accountNumber);
        break;

        case 5 :
        accountNumber = ac.accountNoPromopt();
        ac.closeAccount(accountNumber);
        break;

        case 6 : 
        ac.showAllAccount();
        break;

        case 7 :
        ac.quit();
        break;

        default :
        std :: cout << "Invalid selection. Please try again." << std :: endl;
        break;
        }
    }
    return 0;
}