#pragma once
#include <string>
using namespace std;

class User {
private:
    string name;
    string phoneNumber;
    string pin;
    double balance;

public:
    User(string n, string phone, string p);
    string getName();
    string getPhoneNumber();
    bool checkPin(string enteredPin);
    double getBalance();
    void addBalance(double amount);
};