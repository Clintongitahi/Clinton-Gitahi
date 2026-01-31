#include <iostream>
#include <vector>
#include <string>

class Course {
private:
    std::string courseCode;
    std::string courseName;
public:
    Course(std::string code, std::string name) : courseCode(code), courseName(name) {}
    
    std::string getDetails() const {
        return courseCode + ": " + courseName;
    }
};

class Student {
private:
    std::string studentID;
    std::string name;
public:
    Student(std::string id, std::string n) : studentID(id), name(n) {}
    
    std::string getName() const { return name; }
};

class Department {
private:
    std::string deptName;
    std::vector<Course*> offeredCourses; 

public:
    Department(std::string name) : deptName(name) {}

    void addCourse(Course* c) {
        offeredCourses.push_back(c);
    }

    void listCourses() const {
        std::cout << "\nCourses offered by " << deptName << ":" << std::endl;
        for (auto c : offeredCourses) {
            std::cout << "- " << c->getDetails() << std::endl;
        }
    }
};

class RegistrationManager {
public:
    void registerStudent(const Student& s, const Course& c) {
        std::cout << "[REGISTRATION] Student " << s.getName() 
                  << " successfully enrolled in " << c.getDetails() << std::endl;
    }
};

int main() {
    Department csDept("Computer Science");
    Course c1("CS101", "Intro to Programming");
    Course c2("CS201", "Data Structures");
    
    Student s1("S123", "John Doe");
    RegistrationManager regSystem;

    csDept.addCourse(&c1);
    csDept.addCourse(&c2);

    csDept.listCourses();

    std::cout << "\nProcessing Registration..." << std::endl;
    regSystem.registerStudent(s1, c1);

    return 0;
}