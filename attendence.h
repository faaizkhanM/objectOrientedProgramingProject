#ifndef ATTENDENCE_H
#define ATTENDENCE_H

#include <string>
#include <fstream>
#include <iostream>
#include <limits>   // For std::numeric_limits
#include <ios>

using namespace std;

class ClassSection {
public:
    string classSection;

    void inputClassSection();
    string getStudentFilename() const;
    string getLectureFilename() const;
    ~ClassSection() {
        cout << "Destroying ClassSection object" << endl;
    }
};

class Lectureclass {
public:
    int lectureNumber;
    string lectureTopic;

    bool findLecture(ifstream &lecturesFile, int lectureNum);
    ~Lectureclass(){
    	cout<<"\n\t\t\t\tDestroying LectureClass";
	}

private:
    void parseLecture(const string &line);
};

class markAttendance {
public:
	markAttendance() {
    // Constructor implementation
    // Initialize any necessary members here
    cout << "Creating markAttendance object" << endl;
}
//    markAttendance();// Default constructor
    void processAttendance(const string &studentFile, const string &attendanceFile, const string &lectureTopic);
    ~markAttendance() {
        cout << "Destroying markAttendance object" << endl;
    }
};

class attendence {
private:
//	Aggregation 
    ClassSection *section;
    Lectureclass *lecture;
    markAttendance *ma;

public:
    attendence(ClassSection *section, Lectureclass *lecture, markAttendance *ma);
    void attend();
    ~attendence() {
    // Destructor implementation
    // Assuming ownership of pointers, delete them if necessary
    delete section;
    delete lecture;
    delete ma;
    cout << "\n\t\t\t\tDestroying Attendence object\n\t\t\t\tLectureclass used as an aggregate but isnt destroyed" << endl;
}
};

#endif // ATTENDENCE_H
