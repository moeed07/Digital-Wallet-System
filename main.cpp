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

            bool found = false;
            for (int i = 0; i < userCount; i++) {
                if (users[i]->getPhoneNumber() == phone && users[i]->checkPin(pin)) {
                    cout << "Login successful. Welcome " << users[i]->getName() << "!" << endl;
                    cout << "Your balance is: " << users[i]->getBalance() << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Wrong phone number or PIN." << endl;
            }
        }
    } while (choice != 3);

    for (int i = 0; i < userCount; i++) {
        delete users[i];
    }

    return 0;
}