#include <iostream>
using namespace std;

class BoardGame {
public:

    string title;
    int totalCopies;
    int availableCopies;

    BoardGame(string title, int copies);
    bool avaliable() const;
    void checkOut();
    void returnGame();
};

class Customer {
public:
    string name;
    int customersID;//incase 2 customers have same name;

    Customer(string name, int id);
};

class CheckedOut {
public:
    BoardGame* BoardGame;
    Customer* customer;
    string dueDate;

    LendingRecord(BoardGame* BoardGame, Customer* customer, string dueDate);
};



