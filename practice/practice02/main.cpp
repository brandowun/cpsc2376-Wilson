///Single C++ file(main.cpp), bank account, balance persistently stored in file
///Program features///
/// 1. balance file name - account_balance.txt
/// 2. On startup, if account_balance.txt doesn't exist, create it, and set balance to $100.00
/// 3. If file exist, read current file
/// 4.You should be able to
///     Check balance
///     Deposit money (must be positive amount)
///     Withdraw (cannot exceed the current balance or be negative)
///     Update .txt after every transaction
///
/// Ensure files handled securely and gracefully.
///     if it can't be opened, display error message and exit
///     validate all user inputs
///     Deposits must be positive values
///     With drawls must not exceed the current balance and must be positive values.
///     Show a menu, user can use
///
///     Turning in
///      Place the program in your Git repository under the practice/practice02 folder.
///      file should be named main.cpp
///
///
///     Tips
///     Use functions to organize your code(checkBalance,deposit,withdraw,readBalanceFromFile, writeBalanceToFile
///     when handling money (use std::fixed and stt::setprecision from <iomainip> to display balance with 2 decimal places.
///     Verify all edge cases are handled, invalid inputs, missing file, simultaneous read/write operations).
///
///
///1.what functions will i need
///2.create file
///3.make a menu
///     1.check the balance
///     2.deposit (maybe make a cash option and credit card option)
///     3. withdraw
///     4. exit
///4. Check if there is a file and if not make one
///5.(learn cerr) for issues with file
///6. work on functions
///    1.read the balance
///     2.write the balance
///     3.check balance
///     4.deposit
///     5.withdrawl
///     6. Make an interest rate (if time is possible)
///     7. Make a debt part that you could borrow money from and pay via the menu
///     8. Add interest to the debt which increase how much you owe (based on timeframe)(every 30 days maybe)
///7. Check edge casings

#include <iostream>
#include <fstream>
#include <iomainip>

using namespace std;

//functions I know I need
double readBalanceFromFile();
void writeBalanceToFile(double balance);
void checkBalance(double balance);
void deposit(double balance);
void withdraw(double balance);

// File creation
const string fileName = "account_balance.txt";
const double initialBalance = 100.00;

int main (){
    
    //introduction
    cout << "Welcome to your Bank Account" << endl;

    int choice;
//display menu
    do {
        cout << "\nMenu" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
//choices
        switch (choice){
            case 1:
                checkBalance(balance);
            break;
            case 2:
                deposit(balance);
            break;
            case 3:
                withdraw(balance);
            break;
            case 4:
                cout << "Logging out of your Bank Account" << endl;
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);

    return 0;

}

void writeBalanceFromFile(double balance) {


}




























