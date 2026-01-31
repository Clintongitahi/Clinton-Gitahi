#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int age;
    int serviceYear;
    double salary;

public:
    Employee(std::string n, int a, int s, double sal) {
        name = n;
        age = a;
        serviceYear = s;
        salary = sal;
        std::cout << "Constructor: Employee object created for " << name << std::endl;
    }

    ~Employee() {
        std::cout << "Destructor: Employee object for " << name << " is being destroyed." << std::endl;
    }

    std::string getName() const { return name; }
    int getAge() const { return age; }
    int getServiceYear() const { return serviceYear; }
    double getSalary() const { return salary; }
};

int main() {
    Employee emp1("Alice Smith", 30, 5, 75000.50);

    std::cout << "\n--- Employee Details ---" << std::endl;
    std::cout << "Name: " << emp1.getName() << std::endl;
    std::cout << "Age: " << emp1.getAge() << std::endl;
    std::cout << "Years of Service: " << emp1.getServiceYear() << std::endl;
    std::cout << "Salary: $" << emp1.getSalary() << "\n" << std::endl;

    return 0;
}