#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

using namespace std;


//functions I know I need
double readBalanceFromFile();
void writeBalanceToFile(double balance);
void checkBalance(double balance);
void deposit(double &balance);
void withdraw(double &balance);


//File creation
const string fileName = "account_balance.txt";
const double initialBalance = 100.00;


//Make a pin
bool pin() {
    string userPin = "123";
    string pinInput;
    cout << "Welcome to the bank" << endl;
    while (pinInput != userPin){
        cout << "The pin is 123" << endl;

        cout << "Enter Pin: ";
        cin >> pinInput;

        if (pinInput == userPin) {
            return true;
        } else {
            cout << "Incorrect PIN.\n";
        }
    }
}
double readBalanceFromFile(){
    ifstream file(fileName);
    double balance = initialBalance;

    //Chatgpt assisted on this, never created a file before and also never seen cern before
    if (file) {
      file >> balance;
    }
    else {
        ofstream newFile(fileName);
        if (!newFile) {
        cerr << "Error: Unable to create balance file." << endl;
        exit(1);
        }
        newFile << fixed << setprecision(2) << initialBalance;
    }
    return balance;
}
// end of assistance

int main (){
    if (!pin()) {
        return 0;}

    double balance = readBalanceFromFile();
    cout << fixed << setprecision(2);

    int choice;
// display menu
    do {
        cout << "\n";
        // cout << " " << name << "'s Bank Account" << endl;
        cout << "Welcome to Your bank Account" << endl;
        cout << "\nCurrent balance"<< endl;
        cout << "$" << balance << "\n" << endl;
        cout << "      |Menu|" << endl;
        cout << "------------------" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
//choices
        switch (choice)
        {
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
        } while (choice !=4);

    return 0;

}


//implement functions
void writeBalanceToFile(double balance) {
    ofstream file(fileName);
    if (!file) {
        cerr << "Error: Can't update file balance." << endl;
    }
    file << fixed << setprecision(2) << balance;
}


// Checking the balance
void checkBalance(double balance) {
    cout << "\n\nCurrent balance:$" << fixed << setprecision(2) << balance << endl;
    cout << "--------------------------";
}


//Deposit into the account
void deposit(double &balance) {
    double userDeposit;
    bool ask = true;
    string choice;

    while (ask) {
        cout << "\nDeposit amount: $";
        cin >> userDeposit;

        // Invalid input checking
        if (cin.fail() || userDeposit <=0) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } else {
            balance += userDeposit;
            writeBalanceToFile(balance);
            cout << "your new balance: $" << fixed << setprecision(2) << balance << endl;

            //deposit again
            cout << "\nDeposit more?\n" << "Enter yes or no: ";
            cin >> choice;

            // 2nd deposit error checking
            if (choice != "yes" && choice != "Yes" &&  choice != "YES") {
                ask = (choice == "yes");
                cout << "\n\n\n\nRETURNED TO MENU!!!";
            }
        }
    }
}


//Withdraw from balance
void withdraw(double &balance) {
    double withDrawAmount;
    bool ask = true;
    string choice;

    while (ask) {
        cout << "\nHow much to withdrawl: $";
        cin >> withDrawAmount;

        // Invalid input checking
        if (cin.fail()) {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        //Balance error check
        if (withDrawAmount > balance || withDrawAmount < 0){
            cout << "Insufficient Funds" << endl;
            cout << "Current balance:$ " << balance << endl;

        } else {
            //writing deposit
            balance -= withDrawAmount;
            writeBalanceToFile(balance);
            cout << "\nWithdrew: $" << fixed << setprecision(2) << withDrawAmount << endl;
            cout << "Your new balance: $" << balance << endl;

            //Another deposit
            cout << "\nWithdraw more?" << endl;
            cout << "Enter Yes or no:";
            cin >> choice;

            if (choice != "yes" && choice != "Yes" &&  choice != "YES") {
                ask = (choice == "yes");
                cout << "\n\n\n\nRETURNED TO MENU!!!" << endl;
            }
        }

    }
}