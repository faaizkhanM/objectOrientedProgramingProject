#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Lecture.h"
#include "menu.h"
#include "batch.h"
#include "attendence.h"

int main() {
	menu m;
	m.mainmenu();
	sleep(3);
	m.concepts();
    return 0;
}




















/*oop concepts usage

//	cout<<"\n\n\t\t\t\tConcepts Implemented here\n";
1. Classes/Objects 

Classes are defined in multiple files such as Student.h, Lecture.h, menu.h, etc. 
For example, the Student class is defined in Student.h. 
class Student { 
private: 
    string regNo; 
    string name; 
    char gender; 
    // ... 
}; 
  
Objects are instances of these classes, such as menu m; in main.cpp. 
Menu m; 
  

2. Getter/Setter Methods for Encapsulation 

Encapsulation is achieved using private member variables with public getter and setter methods. 
For example, in Student.h, methods like getRegNo() and setRegNo() are used to access and modify private data members. 

string Student::getRegNo() const { return regNo; } 
void Student::setRegNo(const string& regNo) { this->regNo = regNo; } 
  

3. Methods 

Methods are functions defined within a class. For example, printInfo() in Student.cpp is a method that prints student information. 

void Student::printInfo() const { 
    cout << "Registration No: " << regNo << "\n"; 
    cout << "Name: " << name << "\n"; 
    cout << "Gender: " << gender << "\n"; 
} 
  

4. Constructors/Destructors for Initialization and Cleanup 

Constructors are used to initialize objects. For example, Student::Student(const string& regNo, const string& name, char gender) in Student.cpp. 

Student::Student(const string& regNo, const string& name, char gender) 
    : regNo(regNo), name(name), gender(gender) {} 
  

Destructors are used for cleanup, lecture.cpp ~Lecture(). 

5. Function Overriding 

Function Overriding is demonstrated by GraduateStudent::printInfo() which overrides Student::printInfo(). 

void GraduateStudent::printInfo() const { 
    Student::printInfo(); 
    cout << "Degree Program: " << degreeProgram << "\n"; 
} 
  

6. Inheritance 

Inheritance is used in GraduateStudent which inherits from Student in Student.h. 

class GraduateStudent : public Student { 
private: 
    string degreeProgram; 
    // ... 
}; 
  

7. Friend Function 

A friend function displayStudentFriend is declared in Student.h to access private members of Student. 

friend void displayStudentFriend(const Student& student); 
  

8. Friend Class 

A friend class StudentHelper is also declared in Student.h to access private members of Student. 
friend class StudentHelper; 
  

9. Composition 

Composition is used in menu.h where Student, Lecture, and other objects are part of the menu class. 

class menu { 
private: 
    vector<Student> students; 
    vector<GraduateStudent> gradStudents; 
    // ... 
}; 
  

10. Aggregation 

Aggregation is seen in attendence.h where ClassSection, Lectureclass, and markAttendance are used as pointers in the attendence class. 

class attendence { 
private: 
    ClassSection *section; 
    Lectureclass *lecture; 
    markAttendance *ma; 
    // ... 
}; 
  

11. Vectors for Dynamic Data Handling 

Vectors are used in menu.h to handle dynamic lists of students: vector<Student> students;. 

vector<Student> students; 
  

12. Static Functions for Shared Information 

Static functions are used in Student.cpp with Student::displayStudentArray() to display student information. 

static void displayStudentArray(const vector<Student>& students); 
  

13. File Handling for Data Persistence 

File handling is extensively used in files like menu.cpp and batch.cpp for reading and writing data to files using ifstream and ofstream. 

ifstream teacherFile("teachers.txt"); 
ofstream teacherFile("teachers.txt", ios::app); 
  

14. Default Functions   setLectureDetails in lecture.cpp,(Default Constructor, Copy Constructor, Assignment Operator) 

Default constructor is used in Lecture::Lecture() in Lecture.cpp. 

Lecture::Lecture() 
    : courseTitle(""), courseCode(""), lectureTopic(""), lectureType(""), room(""), date("") {} 
  

Copy constructor is defined in Lecture::Lecture(const Lecture& other) in Lecture.cpp. 

Lecture::Lecture(const Lecture& other) 
    : courseTitle(other.courseTitle), courseCode(other.courseCode), lectureTopic(other.lectureTopic), 
      lectureType(other.lectureType), room(other.room), date(other.date) {} 
  

Assignment operator is defined in Lecture& Lecture::operator=(const Lecture& other) in Lecture.cpp. 

Lecture& Lecture::operator=(const Lecture& other) { 
    if (this != &other) { 
        courseTitle = other.courseTitle; 
        courseCode = other.courseCode; 
        lectureTopic = other.lectureTopic; 
        lectureType = other.lectureType; 
        room = other.room; 
        date = other.date; 
    } 
    return *this; 
} 
  

15. Reference Functions for Efficient Parameter Passing 

Reference parameters are used in functions like void Lecture::setCourseTitle(const std::string& courseTitle) in Lecture.cpp. 

void Lecture::setCourseTitle(const std::string& courseTitle) { 
    this->courseTitle = courseTitle; 
} 
  

16. Array Functions for Object or Data Arrays 

Array functions are used in batch.cpp where arrays of std are used to handle student data. 

std s[snum]; 
  

17. Function Overloading for Varied Parameters 

Function overloading  

setLectureDetails() in Lecture.cpp is overloaded to accept different parameter types. 

18. Multi-file Structure for Modularity 

The project is organized into multiple files like Student.cpp, Lecture.cpp, menu.cpp, etc., for modularity. */

 