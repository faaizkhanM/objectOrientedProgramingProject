#include "attendence.h"

void ClassSection::inputClassSection() {
    cout << "Enter Class and Section: ";
    getline(cin >> ws, classSection);
    for (char &c : classSection) {
        c = toupper(c);
    }
}

string ClassSection::getStudentFilename() const {
    return "Class " + classSection + " Students.txt";
}

string ClassSection::getLectureFilename() const {
    return "Class " + classSection + " Lectures.txt";
}

bool Lectureclass::findLecture(ifstream &lecturesFile, int lectureNum) {
    string line;
    int lineCount = 0;
    while (getline(lecturesFile, line)) {
        lineCount++;
        if (lineCount - 2 == lectureNum) {
            parseLecture(line);
            return true;
        }
    }
    return false;
}

void Lectureclass::parseLecture(const string &line) {
    int sepCount = 0;
    for (char c : line) {
        if (c == '|') {
            sepCount++;//seperator count
        } else if (sepCount == 0) {
            lectureTopic += c;
        }
    }
}

void markAttendance::processAttendance(const string &studentFile, const string &attendanceFile, const string &lectureTopic) {
    ifstream studentBatch(studentFile);
    ofstream attendance(attendanceFile, ios::out | ios::app);

    if (!studentBatch.is_open()) {
        cerr << "Student file not found!" << endl;
        return;
    }

    attendance << "Lecture: " << lectureTopic << "\n";
    cout << "Lecture: " << lectureTopic << endl;

    string student;
    int studentCount = 0;
    char status;

    cout << "P = Present | A = Absent\n";
    while (getline(studentBatch, student)) {
        studentCount++;
        if (studentCount < 3) {
            cout << student << endl;
            attendance << student << endl;
        } else {
            cout << student << "\tStatus: ";
            cin >> status;
            status = toupper(status);
            attendance << student << "|Status: " << status << "\n";
        }
    }

    cout << "Attendance Has Been Marked Successfully!" << endl;
    studentBatch.close();
    attendance.close();
}

//aggragation
attendence::attendence(ClassSection *section, Lectureclass *lecture, markAttendance *ma)
    : section(section), lecture(lecture), ma(ma) {}

//aggragation 
//void attendence::attend() {
//    bool validFiles = false;
//    do {
//        section->inputClassSection();
//
//        ifstream studentFile(section->getStudentFilename());
//        ifstream lecturesFile(section->getLectureFilename());
//
//        if (studentFile.is_open() && lecturesFile.is_open()) {
//            validFiles = true;
//
//            int lectureNum;
//            cout << "Enter Lecture Num#: ";
//            cin >> lectureNum;
//
//            if (!lecture->findLecture(lecturesFile, lectureNum)) {
//                cout << "Invalid Lecture Number. ReEnter." << endl;
//                continue;
//            }
//
//            string attendanceFile = section->classSection + " Lecture " + to_string(lectureNum) + " Attendance.txt";
//            ma->processAttendance(section->getStudentFilename(), attendanceFile, lecture->lectureTopic);
//        } else {
//            cout << "Section or Lecture Not Found. Please Re-Enter." << endl;
//        }
//    } while (!validFiles);
//}

void attendence::attend() {
    bool validFiles = false;
    do {
        section->inputClassSection();

        ifstream studentFile(section->getStudentFilename());
        ifstream lecturesFile(section->getLectureFilename());

        if (studentFile.is_open() && lecturesFile.is_open()) {
            validFiles = true;

            int lectureNum;
            cout << "Enter Lecture Num#: ";
            cin >> lectureNum;

            // Validate lecture number input
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter a valid lecture number." << endl;
                continue;
            }

            if (!lecture->findLecture(lecturesFile, lectureNum)) {
                cout << "Invalid Lecture Number. ReEnter." << endl;
                continue;
            }

            string attendanceFile = section->classSection + " Lecture " + to_string(lectureNum) + " Attendance.txt";
            ma->processAttendance(section->getStudentFilename(), attendanceFile, lecture->lectureTopic);
        } else {
            cout << "Section or Lecture Not Found. Please Re-Enter." << endl;
        }

        // Close files if they were opened
        if (studentFile.is_open()) studentFile.close();
        if (lecturesFile.is_open()) lecturesFile.close();

    } while (!validFiles);
}
