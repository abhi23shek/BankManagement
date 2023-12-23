# Bank Management System

## Introduction
This is a simple Bank Management System implemented in C++ that allows users to perform various banking operations such as creating a new account, depositing and withdrawing money, checking the balance, modifying account details, and more. The system is console-based and provides a text-based interface for users.

## Features
New Account Creation: Users can create new accounts by providing necessary details such as account number, account holder name, account type (Savings or Current), and initial deposit.
Deposit and Withdrawal: Users can deposit or withdraw money from their accounts. Additionally, the system supports using a gift card for withdrawals.
Balance Enquiry: Users can check the balance of their accounts.
Account Modification: Account holders can modify their account details, including the account holder's name, account type, and the deposited amount.
Account Closure: Users can close their accounts, removing them from the system.
All Account Holder List: Provides a list of all account holders along with their account details.
Password Protection: The system is password-protected to ensure security.
How to Use
Run the program and enter the correct password when prompted.
Choose from the main menu options to perform different banking operations.
Follow the on-screen instructions for each operation.
Compilation and Execution
This program can be compiled and executed using a C++ compiler.
An example command for compilation using g++:
Copy code
g++ bank_management_system.cpp -o bank_management_system
To run the compiled program:
bash
Copy code
./bank_management_system
Note
The initial password for accessing the system is "abhishek."
The system stores account information in a file named "account.dat."
Author
Author: Abhishek Kumar
Class: 12th D
School: Delhi Public School, Dwarka
Disclaimer
This system is a simple console-based implementation for educational purposes and may not be suitable for production use. It is advisable to enhance security features and error handling for a real-world banking system.
