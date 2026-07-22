#include "user.h"
#include <iostream>
using namespace std;

User::User(string n, string phone, string p) {
    name = n;
    phoneNumber = phone;
    pin = p;
    balance = 0;
}

string User::getName() {
    return name;
}

string User::getPhoneNumber() {
    return phoneNumber;
}

bool User::checkPin(string enteredPin) {
    return pin == enteredPin;
}

double User::getBalance() {
    return balance;
}

void User::addBalance(double amount) {
    balance = balance + amount;
}

bool User::subtractBalance(double amount) {
    if (amount > balance) {
        return false;
    }
    balance = balance - amount;
    return true;
}