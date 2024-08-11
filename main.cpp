#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool app_running = true; // I don't know if these are needed here, going off both my python and Rust scripts
bool logged_in = false; // see line above
string logged_in_account;
struct Account { // this array is required, needs to be accessable by all the functions
    string email;
    string password;
    float balance;
};

vector<Account> accounts;

// Creates an account and checks if an account is already associated with the logon name
void create_account(std::vector<Account>& accounts) {
    string email;
    string password;
    string password_verify;

    cout << "Thank you for choosing to create an account with us. First we need to ask a few questions." << endl;
    cout << "Please enter your email address: " << endl;
    cin >> email;

    for (const auto& account : accounts) { // I want to check and see if the email entered already exists in the database
        if (account.email == email) {
            cout << "An account with this email already exists. Returning to sign in." << endl;
            return;
        }
    } // line 29 in the rust code

    cout << "Please enter a password: " << endl;
    cin >> password;
    cout << "Please enter the password again: " << endl;
    cin >> password_verify;

    if (password == password_verify) {
        Account new_account = {email, password, 0};
        accounts.push_back(new_account);
        cout << "Account created successfully!" << endl;
    } else {
        cout << "Passwords do not match. Please try again later." << endl;
    }
}

void logon_account(std::vector<Account>& accounts, bool& logged_in, std::string& logged_in_account) {
    string email;
    string password;

    cout << "Enter your account email: " << endl;
    cin >> email;

    cout << "Enter your password: ";
    cin >> password;

    for (const auto& account : accounts) {
        if ((account.email == email) && (account.password == password)) {
            cout << "Welcome back " << email << endl;
            logged_in_account = email;
            logged_in = true;
            return; // returns after finding a matching account
        }
    }

    cout << "INVALID LOGON CREDENTIALS. TRY AGAIN LATER" << endl;
}

void deposit_money(std::vector<Account>& accounts,const std::string& logged_in_account) {
    float deposit_amount;

    cout << "Enter deposit amount" << endl;
    cin >> deposit_amount;

    if (cin.fail()) {
        cout << "Invalid input. Please enter a valid number." << endl;
        return;
    }

    if (deposit_amount < 0) {
        cout << "Deposit amount cannot be less than $0.00" << endl;
        return;
    }

    for (auto& account : accounts) {
        if(account.email == logged_in_account) {
            account.balance += deposit_amount;
            cout << "Deposited $" << deposit_amount << " successfully. New balance is: $" << account.balance << endl;
            return;
        }
    }
}

void withdraw_money(std::vector<Account>& accounts, std::string& logged_in_account) {
    float withdraw_amount;
    cout << "How much would you like to deposit today?" << endl;

    cin >> withdraw_amount;

    if (cin.fail()) {
        cout << "Invalid input. Please enter a valid number." << endl;
        return;
    }

    if (withdraw_amount <= 0) {
        cout << "Withdraw amount cannot be less than or equal to $0" << endl;
    }

    for (auto& account : accounts) {
        if (account.email == logged_in_account) {
            if (account.balance - withdraw_amount >= 0) {
                account.balance -= withdraw_amount;
                cout << "Withdrew $" << withdraw_amount << " successfully. New balance is: $" << account.balance << endl;
                return;
            } else {
                cout << "You do not have the funds necessary for that withdraw." << endl;
                return;
            }
        }
    }

}



int main() {

    while (app_running == true) {
        cout << "Welcome to Bank of Money" << endl;
        cout << "How can we help you today?" << endl;
        cout << "1) Login" << endl;
        cout << "2) Create an account" << endl;
        cout << "3) Exit application" << endl;
        printf("Testg++");

        string user_input;
        cin >> user_input;

        if (user_input == "1") {
            logon_account(accounts, logged_in,logged_in_account);
        } else if (user_input == "2") {
            create_account(accounts);
        } else if (user_input == "3") {
            app_running = false;
        } else {
            cout << "Please select a valid option. " << endl;
        }

        while (logged_in == true) {
            cout << "How can we help you today?" << endl;
            cout << "1) Deposit money" << endl;
            cout << "2) Withdraw money" << endl;
            cout << "3) Display Balance" << endl;
            cout << "4) Transfer money" << endl;
            cout << "5) Log out" << endl;

            string user_input2;
            cin >> user_input2;

            if (user_input2 == "1") {
                // TODO: deposit money funtion here
            } else if (user_input2 == "2") {
                // TODO: withdraw money function will go here
            } else if (user_input2 == "3") {
                // TODO: Display balance function will go here
            } else if (user_input2 == "4") {
                // TODO: Transfer money function will go here
            } else if (user_input2 == "5") {
                logged_in = false;
            } else {
                cout << "Please select a valid option. " << endl;
            }
        }
    }

    return 0;
}
