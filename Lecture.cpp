// Lecture.cpp
#include "Lecture.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

// Getter and Setter Implementations for Lecture Class
string Lecture::getCourseTitle() const {
    return courseTitle;
}
//Reference Function
void Lecture::setCourseTitle(const string& courseTitle) {
    this->courseTitle = courseTitle;
}

string Lecture::getCourseCode() const {
    return courseCode;
}

void Lecture::setCourseCode(const string& courseCode) {
    this->courseCode = courseCode;
}

string Lecture::getLectureTopic() const {
    return lectureTopic;
}

void Lecture::setLectureTopic(const string& lectureTopic) {
    this->lectureTopic = lectureTopic;
}

string Lecture::getLectureType() const {
    return lectureType;
}

void Lecture::setLectureType(const string& lectureType) {
    this->lectureType = lectureType;
}
 Lecture::~Lecture(){
// 	cout<<"\n\t\t\t\tThis is a destructor for class Lecture\n";
 }
string Lecture::getRoom() const {
    return room;
}

void Lecture::setRoom(const string& room) {
    this->room = room;
}

string Lecture::getDate() const {
    return date;
}

void Lecture::setDate(const string& date) {
    this->date = date;
}
//Default Functions
Lecture::Lecture()
    : courseTitle(""), courseCode(""), lectureTopic(""), lectureType(""), room(""), date("") {}

Lecture::Lecture(const string& courseTitle, const string& courseCode, const string& lectureTopic,
                 const string& lectureType, const string& room, const string& date)
    : courseTitle(courseTitle), courseCode(courseCode), lectureTopic(lectureTopic), lectureType(lectureType),
      room(room), date(date) {}


//Purpose: The copy constructor is used to create a new object as a copy of an existing Lecture object.
Lecture::Lecture(const Lecture& other)
    : courseTitle(other.courseTitle), courseCode(other.courseCode), lectureTopic(other.lectureTopic),
      lectureType(other.lectureType), room(other.room), date(other.date) {}


//Purpose: Allows you to assign the contents of one Lecture object to another that already exists.
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

void Lecture::lect() {
    int choose;
lect_menu:
    cout << "Select from below:\n\n 1. Add Lectures \n 2. See Lectures\n 3. Delete Lecture\nEnter: ";
    cin >> choose;
    switch (choose) {
        case 1:
            addLectures();
            break;
        case 2:
            showLecdata();
            break;
        case 3:
            deleteLecture();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            goto lect_menu;
    }
}

void Lecture::addLectures() {
    int nlec;
    cout << "Enter Class and Section: ";
    string cl_sec;
    getline(cin >> ws, cl_sec);
    formatClassSection(cl_sec);
    string filename = "Class " + cl_sec + " Lectures.txt";
    cout << "Enter Number of Lectures: ";
    cin >> nlec;
    Lecture* l = new Lecture[nlec];

    writeLectureToFile(filename, l, nlec);
    delete[] l;
}

void Lecture::showLecdata() {
    bool f_exist = true;
    string cl_sec;
remove:
    if (!f_exist)
        cout << "Please Re-Enter\n";

    cout << "Enter Class and Section: ";
    getline(cin >> ws, cl_sec);
    formatClassSection(cl_sec);
    string filename = "Class " + cl_sec + " Lectures.txt";

    if (!fileExists(filename)) {
        cout << "Section not found.\n";
        f_exist = false;
        goto remove;
    }

    ifstream lectures_d(filename.c_str(), ios::in);
    string showline;
    Lecture show;
    int lineCounter = 0;

    while (getline(lectures_d, showline)) {
        lineCounter++;
        if (lineCounter < 3) continue;

        stringstream ss(showline);
        getline(ss, show.courseTitle, '|');
        getline(ss, show.courseCode, '|');
        getline(ss, show.lectureTopic, '|');
        getline(ss, show.lectureType, '|');
        getline(ss, show.room, '|');
        getline(ss, show.date, '|');

        cout << "\nLecture #: " << lineCounter - 2 << "\n\nTopic: " << show.lectureTopic
             << "\nClass Type: " << show.lectureType << "\nRoom: " << show.room << "\nDate: " << show.date << endl;
    }
}

void Lecture::deleteLecture() {
    string cl_sec;
    bool f_exist = true;

    remove:
    if (!f_exist)
        cout << "Please Re-Enter\n";

    cout << "Enter Class and Section: ";
    getline(cin >> ws, cl_sec);
    formatClassSection(cl_sec);
    string filenameLec = "Class " + cl_sec + " Lectures.txt";

    if (!fileExists(filenameLec)) {
        cout << "Class Section not found.\n";
        f_exist = false;
        goto remove;
    }

    deleteLectureFromFile(filenameLec);
}

bool Lecture::fileExists(const string& filename) {
    ifstream file(filename.c_str());
    return file.is_open();
}

void Lecture::formatClassSection(string& cl_sec) {
    for (char& c : cl_sec) {
        if (isalpha(c))
            c = toupper(c);
    }
}

void Lecture::writeLectureToFile(const string& filename, Lecture* l, int nlec) {
    ofstream lectures_d(filename.c_str(), ios::out | ios::app);
    lectures_d << "Class/Section/" << filename.substr(6, filename.length() - 13) << "\n";
    lectures_d << "Course_Title|Course_Code|Lecture_Type|Room|Date\n";
    for (int i = 0; i < nlec; i++) {
        cout << "Enter Lecture " << i + 1 << " Detail\n";
        cout << "Course Title: ";
        getline(cin >> ws, l[i].courseTitle);
        cout << "Course Code: ";
        getline(cin >> ws, l[i].courseCode);
        cout << "Lecture Topic: ";
        getline(cin >> ws, l[i].lectureTopic);
        cout << "Type of Lecture: ";
        getline(cin >> ws, l[i].lectureType);
        cout << "Room: ";
        getline(cin >> ws, l[i].room);
        cout << "Date: ";
        getline(cin >> ws, l[i].date);

        lectures_d << l[i].courseTitle << "|" << l[i].courseCode << "|" << l[i].lectureTopic << "|"
                   << l[i].lectureType << "|" << l[i].room << "|" << l[i].date << "\n";
    }
    lectures_d.close();
}
//Default Functions
void setLectureDetails(string courseTitle = "Unknown Course", 
                       string courseCode = "000", 
                       string lectureTopic = "General", 
                       string lectureType = "Lecture", 
                       string room = "TBD", 
                       string date = "01-01-2024");
// Set lecture details using separate parameters
//Function Overloading 
void Lecture::setLectureDetails(const string& courseTitle, const string& courseCode, const string& lectureTopic,
                                const string& lectureType, const string& room, const string& date) {
    this->courseTitle = courseTitle;
    this->courseCode = courseCode;
    this->lectureTopic = lectureTopic;
    this->lectureType = lectureType;
    this->room = room;
    this->date = date;
}

// Set lecture details using a single string with a delimiter
void Lecture::setLectureDetails(const string& details, char delimiter) {
    stringstream ss(details);
    getline(ss, courseTitle, delimiter);
    getline(ss, courseCode, delimiter);
    getline(ss, lectureTopic, delimiter);
    getline(ss, lectureType, delimiter);
    getline(ss, room, delimiter);
    getline(ss, date, delimiter);
}

void Lecture::deleteLectureFromFile(const string& filenameLec) {
    ifstream lectures_d(filenameLec.c_str());
    ofstream tempfile("temp.txt");

    tempfile << "Class/Section/" << filenameLec.substr(6, filenameLec.length() - 15) << "\n";
    tempfile << "Course_Title|Course_Code|Lecture_Type|Room|Date\n";

    int lnum;
    Lecture del;
    cout << "Enter Lecture Num#: ";
    cin >> lnum;

    string showline;
    int l_count = 0;
    while (getline(lectures_d, showline)) {
        l_count++;
        if (l_count - 2 == lnum) {
            stringstream ss(showline);
            getline(ss, del.courseTitle, '|');
            getline(ss, del.courseCode, '|');
            getline(ss, del.lectureTopic, '|');
            getline(ss, del.lectureType, '|');
            getline(ss, del.room, '|');
            getline(ss, del.date, '|');

            cout << "\nLecture #: " << l_count - 2 << "\nTopic: " << del.lectureTopic
                 << "\nClass Type: " << del.lectureType << "\nRoom: " << del.room << "\nDate: " << del.date << endl;
        } else {
            tempfile << showline << "\n";
        }
    }

    lectures_d.close();
    tempfile.close();

    remove(filenameLec.c_str());
    rename("temp.txt", filenameLec.c_str());

    cout << "Lecture deleted successfully." << endl;
}

