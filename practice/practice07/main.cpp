#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class employee {
protected:
    string name;
    int id;

public:
    employee(string name, int id) : name(name), id(id) {}
    virtual ~employee() {}
    virtual double finalSalary() const = 0;

    virtual void display() const {
        cout << "ID: " << id << ", Name: " << name;
    }
};

class salariedEmployee : public employee {
private:
    double monthlySalary;

public:
    salariedEmployee(string name, int id, double salary)
        : employee(name, id), monthlySalary(salary) {}

    double finalSalary() const override {
        return monthlySalary;
    }

    void display()  const override {
        employee::display();
        cout << ", Type: Salaried,Monthly Salary: $" << fixed << setprecision(2)
             << finalSalary()  << endl;
    }
};

// just started setting this one up
class hourlyEmployee : public employee {
public:
    hourlyEmployee(string name, int id)
        : employee(name, id) {}

    double finalSalary() const override {
        return 0.0;//just to see if it runs
    }

    void display() const override {
        employee::display();
        cout<< ",Type: Hourly " << endl;
    }
};

// just started setting this one up too
class commissionEmployee : public employee {
public:
    commissionEmployee(string name, int id)
    : employee(name, id) {}

    double finalSalary() const override {
        return 0.0; //again just to see if it runs
    }

    void display() const override {
        employee::display();
        cout << ", Type:mCommissionm" << endl;//why can't i get this to print
    }
};

int main() {
    vector<employee*> employees;

    employees.push_back(new salariedEmployee("Alice", 101, 5000));
    //employees.push_back(new hourlyEmployee
    //employees.push_back(new commissionEmployee


    for (employee* e : employees) {
        e->display();
    }

    for (employee* e : employees) {
        delete e;
    }

    return 0;
}
