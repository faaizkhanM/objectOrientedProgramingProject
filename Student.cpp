#include "Student.h"

using namespace std;
// Default constructor
Student::Student() : regNo(""), name(""), gender('N') {}

// Parameterized constructor
Student::Student(const string& regNo, const string& name, char gender)
    : regNo(regNo), name(name), gender(gender) {}

// Getters and Setters
string Student::getRegNo() const { return regNo; }
void Student::setRegNo(const string& regNo) { this->regNo = regNo; }

string Student::getName() const { return name; }
void Student::setName(const string& name) { this->name = name; }

char Student::getGender() const { return gender; }
void Student::setGender(char gender) { this->gender = gender; }

// Print student info //Constant method hai ye
void Student::printInfo() const {
    cout << "\n\t\t\t\tRegistration No: " << regNo << "\n";
    cout << "\n\t\t\t\tName: " << name << "\n";
    cout << "\n\t\t\t\tGender: " << gender << "\n";
}
//default function,overloading
void Student::printInfo(string r, string n, char g) {
    regNo = r;
    name = n;
    gender = g;
    cout << "\n\t\t\t\tRegistration No: " << regNo << "\n";
    cout << "\n\t\t\t\tName: " << name << "\n";
    cout << "\n\t\t\t\tGender: " << gender << "\n";
}


// Static method/function for array functionality
void Student::displayStudentArray(const vector<Student>& students) {
    for (const auto& student : students) {//used to iterate over each element in the students vector
        student.printInfo();
        cout << "\n";
    }
}

// Friend Function
void displayStudentFriend(const Student& student) {
    cout << "[Friend Function] Registration No: " << student.regNo << "\n";
    cout << "[Friend Function] Name: " << student.name << "\n";
    cout << "[Friend Function] Gender: " << student.gender << "\n";
}

//Friend class 
void StudentHelper:: displayPrivateDetails(const Student& student) {
        cout << "[Friend Class] Registration No: " << student.regNo << "\n";
        cout << "[Friend Class] Name: " << student.name << "\n";
        cout << "[Friend Class] Gender: " << student.gender << "\n";
    }

// GraduateStudent methods inheritance from base student class
GraduateStudent::GraduateStudent()
    : Student(), degreeProgram("") {}

GraduateStudent::GraduateStudent(const string& regNo, const string& name, char gender, const string& degreeProgram)
    : Student(regNo, name, gender), degreeProgram(degreeProgram) {}

string GraduateStudent::getDegreeProgram() const { return degreeProgram; }
void GraduateStudent::setDegreeProgram(const string& degreeProgram) { this->degreeProgram = degreeProgram; }


//function overiding as it overrides Student::printInfo()
void GraduateStudent::printInfo() const {
    Student::printInfo();
    cout << "Degree Program: " << degreeProgram << "\n";
}
