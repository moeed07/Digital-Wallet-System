# Digital Wallet System

A console-based digital wallet system built in C++, inspired by JazzCash and Easypaisa. It allows users to create accounts, log in securely, deposit and withdraw money, send money to other users, and view their transaction history. The project demonstrates core object-oriented programming concepts including encapsulation, inheritance, polymorphism, and file handling.

## Features

- Create an account with name, phone number, and PIN
- Secure login using phone number and PIN
- Check account balance
- Deposit and withdraw money
- Send money to another registered user
- View complete transaction history
- Data saved to files so accounts and balances persist between runs
- Admin account with the ability to view and manage all users
- Different account types (Personal vs Business) with different transaction limits
- PIN attempt limit with account lockout for security

## Tech Stack

- C++ (no external libraries)
- Object Oriented Programming: classes, inheritance, polymorphism, encapsulation
- File handling for data persistence

## Project Structure
DigitalWallet/
├── user.h / user.cpp        - User class (account details, PIN, balance)
├── wallet.h / wallet.cpp     - Wallet class (deposit, withdraw, balance management)
├── transaction.h / transaction.cpp  - Transaction class (transaction history)
├── admin.h / admin.cpp       - Admin class (inherits User, manages accounts)
├── main.cpp                  - Menu system and program entry point