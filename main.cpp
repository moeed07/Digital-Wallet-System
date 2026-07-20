#include <iostream>
#include "user.h"
using namespace std;

int main() {
    User* users[100];
    int userCount = 0;

    int choice;
    do {
        cout << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, phone, pin;
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your phone number: ";
            getline(cin, phone);
            cout << "Set a 4 digit PIN: ";
            getline(cin, pin);

            users[userCount] = new User(name, phone, pin);
            userCount++;
            cout << "Account created successfully!" << endl;
        }
        else if (choice == 2) {
            string phone, pin;
            cout << "Enter your phone number: ";
            getline(cin, phone);
            cout << "Enter your PIN: ";
            getline(cin, pin);

            int loggedInIndex = -1;
            for (int i = 0; i < userCount; i++) {
                if (users[i]->getPhoneNumber() == phone && users[i]->checkPin(pin)) {
                    loggedInIndex = i;
                    break;
                }
            }

            if (loggedInIndex == -1) {
                cout << "Wrong phone number or PIN." << endl;
            }
            else {
                cout << "Login successful. Welcome " << users[loggedInIndex]->getName() << "!" << endl;

                int accountChoice;
                do {
                    cout << endl;
                    cout << "1. Check Balance" << endl;
                    cout << "2. Deposit Money" << endl;
                    cout << "3. Logout" << endl;
                    cout << "Enter choice: ";
                    cin >> accountChoice;
                    cin.ignore();

                    if (accountChoice == 1) {
                        cout << "Your balance is: " << users[loggedInIndex]->getBalance() << endl;
                    }
                    else if (accountChoice == 2) {
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        cin.ignore();

                        if (amount > 0) {
                            users[loggedInIndex]->addBalance(amount);
                            cout << "Deposit successful. New balance: " << users[loggedInIndex]->getBalance() << endl;
                        }
                        else {
                            cout << "Enter a valid amount." << endl;
                        }
                    }
                } while (accountChoice != 3);
            }
        }
    } while (choice != 3);

    for (int i = 0; i < userCount; i++) {
        delete users[i];
    }

    return 0;
}