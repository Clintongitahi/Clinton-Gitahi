#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Employee {
protected:
    std::string firstName;
    char initial;
    std::string lastName;

public:
    Employee(std::string f, char i, std::string l) 
        : firstName(f), initial(i), lastName(l) {}

    virtual ~Employee() {}

    virtual double calculateEarnings() const = 0;

    void display() const {
        std::cout << firstName << " " << initial << ". " << lastName;
    }
};

class SalaryEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalaryEmployee(std::string f, char i, std::string l, double sal)
        : Employee(f, i, l), monthlySalary(sal) {}

    double calculateEarnings() const override {
        return monthlySalary;
    }
};

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(std::string f, char i, std::string l, double rate, double hours)
        : Employee(f, i, l), hourlyRate(rate), hoursWorked(hours) {}

    double calculateEarnings() const override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    std::vector<Employee*> staff;

    staff.push_back(new SalaryEmployee("Alice", 'M', "Johnson", 4500.00));
    staff.push_back(new HourlyEmployee("Bob", 'D', "Smith", 25.50, 160.0));
    staff.push_back(new SalaryEmployee("Charlie", 'K', "Brown", 5200.00));
    staff.push_back(new HourlyEmployee("Diana", 'P', "Prince", 30.00, 150.0));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "============================================" << std::endl;
    std::cout << "             MONTHLY PAYROLL                " << std::endl;
    std::cout << "============================================" << std::endl;

    for (const auto& emp : staff) {
        emp->display();
        std::cout << "\nEarnings: $" << emp->calculateEarnings() << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
    }

    for (auto emp : staff) {
        delete emp;
    }
    staff.clear();

    return 0;
}