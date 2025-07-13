
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Student;

// Friend Function Declaration
void displayStudentFriend(const Student& student);

// Student Class
class Student {
private:
    string regNo;  // Registration number of the student
    string name;   // Name of the student
    char gender;   // Gender of the student ('M', 'F', 'N')

    // Declare Friend Function
    friend void displayStudentFriend(const Student& student);

    // Declare Friend Class
    friend class StudentHelper;

public:
    // Constructors
    Student();
    Student(const string& regNo, const string& name, char gender);

    // Getters and Setters
    string getRegNo() const;
    void setRegNo(const string& regNo);

    string getName() const;
    void setName(const string& name);

    char getGender() const;
    void setGender(char gender);

    // Print student information
    void printInfo() const;
    void printInfo(string r = "000", string n = "Default Name ", char g = 'M') ;


    // Static method for array functionality
    static void displayStudentArray(const vector<Student>& students);
};

// Friend Class Implementation
class StudentHelper {
public:
    void displayPrivateDetails(const Student& student);
};

// GraduateStudent Class (Inheritance)
class GraduateStudent : public Student {
private:
    string degreeProgram;  // New attribute for graduate student

public:
    // Constructor
    GraduateStudent();
    GraduateStudent(const string& regNo, const string& name, char gender, const string& degreeProgram);

    // Getter and Setter
    string getDegreeProgram() const;
    void setDegreeProgram(const string& degreeProgram);

    // Override printInfo without virtual
    void printInfo() const;
};

#endif
