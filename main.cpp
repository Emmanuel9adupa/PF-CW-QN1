#include <iostream>
#include <string>

using namespace std;

int main() {
    string userID = "";
    string password = "";
    double balance = 0.0;
    string inputID, inputPassword;
    char choice;

    cout << "Hi! Welcome to the ATM Machine!" << endl;

    while (true) {// menu
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> choice;

        if (choice == 'c') {
            cout << "Please enter your user id: ";
            cin >> userID;
            cout << "Please enter your password: ";
            cin >> password;
            balance = 0.0;
            cout << "Thank You! Your account has been created!" << endl;
        }
        else if (choice == 'l') {
            cout << "Please enter your user id: ";
            cin >> inputID;
            cout << "Please enter your password: ";
            cin >> inputPassword;

            if (inputID == userID && inputPassword == password) {
                cout << "Access Granted!" << endl;
                while (true) {
                    cout << "d -> Deposit Money" << endl;
                    cout << "w -> Withdraw Money" << endl;
                    cout << "r -> Request Balance" << endl;
                    cout << "q -> Quit" << endl;
                    cout << "> ";
                    cin >> choice;

                    if (choice == 'd') {
                        double depositAmount;
                        cout << "Amount of deposit: $";
                        cin >> depositAmount;
                        balance += depositAmount;
                        cout << "Deposit successful! Your new balance is $" << balance << "." << endl;
                    }
                    else if (choice == 'w') {
                        double withdrawalAmount;
                        cout << "Amount of withdrawal: $";
                        cin >> withdrawalAmount;
                        if (withdrawalAmount <= balance) {
                            balance -= withdrawalAmount;
                            cout << "Withdrawal successful! Your new balance is $" << balance << "." << endl;
                        }
                        else {
                            cout << "Insufficient funds!" << endl;
                        }
                    }
                    else if (choice == 'r') {
                        cout << "Your balance is $" << balance << "." << endl;
                    }
                    else if (choice == 'q') {
                        cout << "Logging out..." << endl;
                        break;
                    }
                    else {
                        cout << "Invalid option. Please try again." << endl;
                    }
                }
            }
            else {
                cout << "*** LOGIN FAILED! ***" << endl;
            }
        }
        else if (choice == 'q') {
            cout << "Thank you for using the ATM machine. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
