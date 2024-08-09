#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool app_running = true; // I don't know if these are needed here, going off both my python and Rust scripts
bool logged_in = false; // see line above
struct Account { // this array is required, needs to be accessable by all the functions
    string email;
    string password;
    int balance;
};

vector<Account> accounts;

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

}




int main() {

    //create_account(accounts);
    return 0;
}
