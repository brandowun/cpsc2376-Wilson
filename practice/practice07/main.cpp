#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>


using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string name, int id) : name(name), id(id) {}
    virtual ~Employee() {}
    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name;
    }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(string name, int id, double salary)
        : Employee(name, id), monthlySalary(salary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo()  const override {
        Employee::displayInfo();
        cout << ", Type: Salaried,Monthly Salary: $" << fixed << setprecision(2)
             << calculateSalary()  << endl;
    }
};
//hourly employee class
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(string name, int id, double rate, int hours)
        : Employee(name, id), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Hourly, Hours Worked: " << hoursWorked << ", Hourly Rate: $" << fixed << setprecision(2) << hourlyRate << ", Salary: $" << calculateSalary() << endl;
    }
};

//commission emlpoyee class
class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(string name, int id, double base, double sales, double rate)
        : Employee(name, id), baseSalary(base), salesAmount(sales), commissionRate(rate) {}

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Commission, Base Salary: $" << fixed << setprecision(2)
             << baseSalary << ", Sales: $" << salesAmount
             << ", Commission Rate: " << commissionRate * 100 << "%, Salary: $"
             << calculateSalary() << endl;
    }
};

int main() {
    vector<Employee*> employees;
    ifstream file("employees.txt");

//chatgpt, helped for file errors.
    if (!file) {
        cerr << "Error: Could not open employees.txt\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        istringstream records(line);
        string type, name;
        int id;

        records >> type >> id >> name;

        if (type == "Salaried") {
            double salary;

            if (records >> salary) {
                employees.push_back(new SalariedEmployee(name, id, salary));
            }

        } else if (type == "Hourly") {
            double rate;
            int hours;
            if (records >> rate >> hours) {
                employees.push_back(new HourlyEmployee(name, id, rate, hours));
            }

        } else if (type == "Commission") {
            double base, sales, rate;
            if (records >> base >> sales >> rate) {
                employees.push_back(new CommissionEmployee(name, id, base, sales, rate));
            }
//chatgpt, helped with the error message,
        } else {
            cerr << "Warning: Unknown type '" << type << "'\n";
        }
    }

    for (Employee* e : employees) {
        e->displayInfo();
    }

    for (Employee* e : employees) {
        delete e;
    }

    return 0;
}

//example txt
// Salaried 101 Alice 5000
// Hourly 102 Bob 20 160
// Commission 103 Charlie 2000 15000 0.05