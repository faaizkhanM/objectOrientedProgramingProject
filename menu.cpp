//#include "menu.h"
//#include <fstream>
//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <sstream> // For splitting the line
//using namespace std;
//
//void menu::mainmenu() {
//    int choice;
//    do {
//    	system("cls");
//    	UINT originalCodePage = GetConsoleOutputCP();
//    	SetConsoleOutputCP(CP_UTF8);
//        cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t         \U0001F393 CUI PORTAL\n";
//	    cout << "\t\t\t\t====================================\n";
//	    cout << "\n\t\t\t\t  1. Admin Login";
//	    cout << "\n\t\t\t\t  2. Teacher Login";
//	    cout << "\n\t\t\t\t  3. Exit\n";
//	    cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t  Choice: ";
//        cin >> choice;
//        SetConsoleOutputCP(originalCodePage);
//
//        switch (choice) {
//        case 1:
//        	system("cls");
//            if (authenticateAdmin()) {
//                adminMenu();
//            } else {
//                cout << "Invalid admin credentials!\n";
//            }
//            break;
//        case 2: {
//        	system("cls");
//            string teacherName;
//            if (authenticateTeacher(teacherName)) {
//                teacherMenu(teacherName);
//            } else {
//                cout << "Invalid teacher credentials!\n";
//            }
//            break;
//        }
//        case 3:
////        	system("cls");
//            cout << "\n\t\t\t\tExiting program. Goodbye!\n";
//            break;
//        default:
////        	system("cls");
//            cout << "\n\t\t\t\tInvalid choice!\n";
//        }
//    } while (choice != 3);
//}
//
//bool menu::authenticateAdmin() {
//    const string adminUsername = "admin";
//    const string adminPassword = "admin";
//
//    string username, password;
//    cout << "\n\t\t\t\tEnter Admin Username: ";
//    getline(cin >> ws, username);
//    cout << "\n\t\t\t\tEnter Admin Password: ";
//    getline(cin >> ws, password);
//
//    return username == adminUsername && password == adminPassword;
//}
//
//bool menu::authenticateTeacher(string& teacherName) {
//    ifstream teacherFile("teachers.txt");
//    if (!teacherFile.is_open()) {
//        cerr << "\n\t\t\t\tCould not open teachers file.\n";
//        return false;
//    }
//
//    string username, password, inputUser, inputPass;
//    cout << "\n\t\t\t\tEnter Teacher Username: ";
//    getline(cin >> ws, inputUser);
//    cout << "\n\t\t\t\tEnter Teacher Password: ";
//    getline(cin >> ws, inputPass);
//    string line;
//    while (getline(teacherFile, line)) {
//                stringstream ss(line);
//                string username, password, name;
//                // Extract data using '|' as a delimiter
//                getline(ss, username, '|');
//                getline(ss, password, '|');
//                getline(ss, name, '|');
//                if (username == inputUser && password == inputPass) {
//            teacherFile.close();
//            return true;
//        	}
//            }
//
//    teacherFile.close();
//    return false;
//}
//
//void menu::adminMenu() {
//    int choice;
//    do {
////    	system("cls");
//    	UINT originalCodePage = GetConsoleOutputCP();
//    	SetConsoleOutputCP(CP_UTF8);
//        cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t          \U0001F512 ADMIN MENU\n";
//	    cout << "\t\t\t\t====================================\n";
//	    cout << "\n\t\t\t\t  1. Create Teacher Account";
//	    cout << "\n\t\t\t\t  2. View Teacher Accounts";
//	    cout << "\n\t\t\t\t  3. Add Batch";
//	    cout << "\n\t\t\t\t  4. Update Batch Recod";
//	    cout << "\n\t\t\t\t  6. Exit to Main Menu\n";
//	    cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t  Choice: ";
//        cin >> choice;
//        SetConsoleOutputCP(originalCodePage);
//
//        switch (choice) {
//        case 1: {
//        	system("cls");
//            ofstream teacherFile("teachers.txt", ios::app);
//            if (!teacherFile.is_open()) {
//                cerr << "\n\t\t\t\tError opening teachers file.\n";
//                break;
//            }
//            string username, password, name;
//            cout << "\n\t\t\t\tEnter Teacher Username: ";
//            getline(cin >> ws, username);
//            cout << "\n\t\t\t\tEnter Teacher Password: ";
//            getline(cin >> ws, password);
//            cout << "\n\t\t\t\tEnter Teacher Name: ";
//            getline(cin >> ws, name);
//
//            teacherFile << username << "|" << password << "|" << name << "\n";
//            teacherFile.close();
//            cout << "\n\t\t\t\tTeacher account created successfully!\n";
//            break;
//        }
//        case 2: {
//            ifstream teacherFile("teachers.txt");
//            if (!teacherFile.is_open()) {
//                cerr << "\n\t\t\t\tError opening teachers file.\n";
//                break;
//            }
//
//            string line;
//            cout << "\n\t\t\t\tTeacher Accounts:\n";
//            while (getline(teacherFile, line)) {
//                stringstream ss(line);
//                string username, password, name;
//
//                // Extract data using '|' as a delimiter
//                getline(ss, username, '|');
//                getline(ss, password, '|');
//                getline(ss, name, '|');
//
//                // Display the data
//                cout << "Username: " << username << ", Name: " << name << "\n";
//            }
//            teacherFile.close();
//            break;}
//        	case 3:{
////        		system("cls");
//            	b.addNewBatch();
//            	//add batch
//				break;
//			}
//			case 4:{
////				system("cls");
//            	b.updateStudentRecord();
////            	Update Whole Records
//				break;
//			}
//			
//	        case 5:
//	//        	system("cls");
//	            cout << "\n\t\t\t\tReturning to Main Menu...\n";
//	            break;
//	        default:
//	//        	system("cls");
//	            cout << "\n\t\t\t\tInvalid choice!\n";
//	        }
//	    } while (choice != 5);
//}
//
//void menu::teacherMenu(const string& teacherName) {
//    const int maxStudents = 100;
//    const int maxLectures = 100;
//
//    Student students[maxStudents];
//    Lecture lectures[maxLectures];
//    int studentCount = 0;
//    int lectureCount = 0;
//
//    int choice;
//
//    do {
//    	UINT originalCodePage = GetConsoleOutputCP();
//    	SetConsoleOutputCP(CP_UTF8);
//        system("cls");
//        cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t         \u270F  TEACHER MENU\n";
//	    cout << "\t\t\t\t====================================\n";
//	    cout << "\n\t\t\t\t  1. Manage Students";
//	    cout << "\n\t\t\t\t  2. Manage Lectures";
//	    cout << "\n\t\t\t\t  3. Logout\n";
//	    cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t  Enter your choice: ";
//        cin >> choice;
//        SetConsoleOutputCP(originalCodePage);
//
//        switch (choice) {
//        case 1:
//        	system("cls");
//            StudentMenu();
//            break;
//        case 2:
//        	system("cls");
//            l.lect();
//            break;
//        case 3:
//        	system("cls");
//            cout << "\n\t\t\t\tLogging out...\n";
//            break;
//        default:
//        	system("cls");
//            cout << "\n\t\t\t\tInvalid choice!\n";
//        }
//    } while (choice != 3);
//}
//void menu::StudentMenu(){
//    int choice;
//    do {
////    	system("cls");
//    	UINT originalCodePage = GetConsoleOutputCP();
//    	SetConsoleOutputCP(CP_UTF8);
//	    cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t          \U0001F4A1 STUDENT MENU\n";
//	    cout << "\t\t\t\t====================================\n";
//	    cout << "\n\t\t\t\t  1. Add Student";
//	    cout << "\n\t\t\t\t  2. Add Graduate Student";
//	    cout << "\n\t\t\t\t  3. Display All Students";
//	    cout << "\n\t\t\t\t  4. Display All Graduate Students";
//	    cout << "\n\t\t\t\t  5. Add Lecture Data";
//	    cout << "\n\t\t\t\t  6. Delete Lecture";
//	    cout << "\n\t\t\t\t  7. Show Lecture Data\n";
//	    cout << "\n\t\t\t\t  8. Exit";
//	    cout << "\n\t\t\t\t====================================\n";
//	    cout << "\t\t\t\t  Choice: ";
//        cin >> choice;
//        SetConsoleOutputCP(originalCodePage);
//        cin.ignore(); // To handle the newline character after cin
//
//        switch (choice) {
//            case 1: {
//            	system("cls");
//                string regNo, name;
//                char gender;
//                cout << "\n\t\t\t\tEnter Registration No: ";
//                getline(cin, regNo);
//                cout << "\n\t\t\t\tEnter Name: ";
//                getline(cin, name);
//                cout << "\n\t\t\t\tEnter Gender (M/F): ";
//                cin >> gender;
//                cin.ignore();
//                students.emplace_back(regNo, name, gender);
//                cout << "\n\t\t\t\tStudent added successfully!\n";
//                break;
//            }
//            case 2: {
//            	
//            	system("cls");
//                string regNo, name, degreeProgram;
//                char gender;
//
//                cout << "\n\t\t\t\tEnter Registration No: ";
//                getline(cin, regNo);
//                cout << "\n\t\t\t\tEnter Name: ";
//                getline(cin, name);
//                cout << "\n\t\t\t\tEnter Gender (M/F): ";
//                cin >> gender;
//                cin.ignore();
//                cout << "\n\t\t\t\tEnter Degree Program: ";
//                getline(cin, degreeProgram);
//                gradStudents.emplace_back(regNo, name, gender, degreeProgram);
//                cout << "\n\t\t\t\tGraduate Student added successfully!\n";
//                break;
//            }
//            case 3: {
//            	system("cls");
//                if (students.empty()) {
//                    cout << "\n\t\t\t\tNo students to display!\n";
//                } else {
//                    cout << "\n\t\t\t\tStudent List:\n";
//                    Student::displayStudentArray(students);
//                }
//                break;
//            }
//            case 4: {
//            	system("cls");
//                if (gradStudents.empty()) {
//                    cout << "\n\t\t\t\tNo graduate students to display!\n";
//                } else {
//                    cout << "\n\t\t\t\tGraduate Student List:\n";
//                    for (const auto& gradStudent : gradStudents) {
//                        gradStudent.printInfo();
//                        cout << "\n";
//                    }
//                }
//                break;
//            }
//			case 5:{
//				system("cls");
//				l.addLectures();
//				//add lecture 
//				break;
//			}
//			case 6:{
//				system("cls");
//				l.deleteLecture();
//				//delete lecture 
//				break;
//			}
//            case 7:
//            	system("cls");
//                l.showLecdata();
//                sleep(3);
//                break;
//            case 8:
//            	system("cls");
//                cout << "\n\t\t\t\tExiting...\n";
//                break;
//            default:
//            	system("cls");
//                cout << "\n\t\t\t\tInvalid choice. Please try again.\n";
//        }
//    } while (choice != 8);
//	
//}



#include "menu.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

// Function to set console text color
void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to simulate loading animation
void simulateLoading(const string& message) {
    cout << message;
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << ".";
    }
    cout << endl;
}

void menu::mainmenu() {
    int choice;
    do {
        system("cls");
        UINT originalCodePage = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t         \U0001F393 CUI PORTAL\n";
        cout << "\t\t\t\t====================================\n";
        cout << "\n\t\t\t\t  1. Admin Login";
        cout << "\n\t\t\t\t  2. Teacher Login";
        cout << "\n\t\t\t\t  3. Exit\n";
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t  Choice: ";
        cin >> choice;
        SetConsoleOutputCP(originalCodePage);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setConsoleColor(12); // Red for error
            cout << "\n\t\t\t\tInvalid input. Please enter a number.\n";
            setConsoleColor(7); // Reset to default
            continue;
        }

        switch (choice) {
        case 1:
            system("cls");
            if (authenticateAdmin()) {
                adminMenu();
            } else {
                setConsoleColor(12); // Red for error
                cout << "Invalid admin credentials!\n";
                sleep(2);
                setConsoleColor(7); // Reset to default
            }
            break;
        case 2: {
            system("cls");
            string teacherName;
            if (authenticateTeacher(teacherName)) {
                teacherMenu(teacherName);
            } else {
                setConsoleColor(12); // Red for error
                cout << "Invalid teacher credentials!\n";
                sleep(2);
                setConsoleColor(7); // Reset to default
            }
            break;
        }
        case 3:
            system("cls");
            setConsoleColor(10); // Green for positive message
            cout << "\n\t\t\t\tExiting program. Goodbye!\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
            break;
        default:
            setConsoleColor(12); // Red for error
            cout << "\n\t\t\t\tInvalid choice! Please select a valid option.\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
        }
    } while (choice != 3);
}

bool menu::authenticateAdmin() {
    const string adminUsername = "admin";
    const string adminPassword = "admin";

    string username, password;
    cout << "\n\t\t\t\tEnter Admin Username: ";
    getline(cin >> ws, username);
    cout << "\n\t\t\t\tEnter Admin Password: ";
    getline(cin >> ws, password);

    return username == adminUsername && password == adminPassword;
}

bool menu::authenticateTeacher(string& teacherName) {
    ifstream teacherFile("teachers.txt");
    if (!teacherFile.is_open()) {
        setConsoleColor(12); // Red for error
        cerr << "\n\t\t\t\tCould not open teachers file.\n";
        sleep(2);
        setConsoleColor(7); // Reset to default
        return false;
    }

    string username, password, inputUser, inputPass;
    cout << "\n\t\t\t\tEnter Teacher Username: ";
    getline(cin >> ws, inputUser);
    cout << "\n\t\t\t\tEnter Teacher Password: ";
    getline(cin >> ws, inputPass);
    string line;
    while (getline(teacherFile, line)) {
        stringstream ss(line);
        string username, password, name;
        getline(ss, username, '|');
        getline(ss, password, '|');
        getline(ss, name, '|');
        if (username == inputUser && password == inputPass) {
            teacherName = name;
            teacherFile.close();
            return true;
        }
    }

    teacherFile.close();
    return false;
}

void menu::adminMenu() {
    int choice;
    do {
        system("cls");
        UINT originalCodePage = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t          \U0001F512 ADMIN MENU\n";
        cout << "\t\t\t\t====================================\n";
        cout << "\n\t\t\t\t  1. Create Teacher Account";
        cout << "\n\t\t\t\t  2. View Teacher Accounts";
        cout << "\n\t\t\t\t  3. Add Batch";
        cout << "\n\t\t\t\t  4. Update Whole Batch";
        cout << "\n\t\t\t\t  5. Update Specific Records in Batch";
        cout << "\n\t\t\t\t  6. Exit to Main Menu\n";
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t  Choice: ";
        cin >> choice;
        SetConsoleOutputCP(originalCodePage);

        switch (choice) {
        case 1: {
            system("cls");
            ofstream teacherFile("teachers.txt", ios::app);
            if (!teacherFile.is_open()) {
                setConsoleColor(12); // Red for error
                cerr << "\n\t\t\t\tError opening teachers file.\n";
                sleep(2);
                setConsoleColor(7); // Reset to default
                break;
            }
            string username, password, name;
            cout << "\n\t\t\t\tEnter Teacher Username: ";
            getline(cin >> ws, username);
            cout << "\n\t\t\t\tEnter Teacher Password: ";
            getline(cin >> ws, password);
            cout << "\n\t\t\t\tEnter Teacher Name: ";
            getline(cin >> ws, name);

            teacherFile << username << "|" << password << "|" << name << "\n";
            teacherFile.close();
            setConsoleColor(10); // Green for positive message
            cout << "\n\t\t\t\tTeacher account created successfully!\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
            break;
        }
        case 2: {
            system("cls");
            ifstream teacherFile("teachers.txt");
            if (!teacherFile.is_open()) {
                setConsoleColor(12); // Red for error
                cerr << "\n\t\t\t\tError opening teachers file.\n";
                sleep(2);
                setConsoleColor(7); // Reset to default
                break;
            }

            string line;
            cout << "\n\t\t\t\tTeacher Accounts:\n";
            while (getline(teacherFile, line)) {
                stringstream ss(line);
                string username, password, name;
                getline(ss, username, '|');
                getline(ss, password, '|');
                getline(ss, name, '|');
                cout << "Username: " << username << ", Name: " << name << "\n";
            }
            teacherFile.close();
            system("pause"); // Wait for user input before returning to menu
            break;
        }
        case 3:
            system("cls");
            b.addNewBatch();
            break;
        case 4:
            system("cls");
            b.updateWholeRecord();
            break;
        case 5:
//            system("cls");
            b.updateSpecificRecord();
            break;
        case 6:
            system("cls");
            setConsoleColor(10); // Green for positive message
            cout << "\n\t\t\t\tReturning to Main Menu...\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
            break;
        default:
            setConsoleColor(12); // Red for error
            cout << "\n\t\t\t\tInvalid choice!\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
        }
    } while (choice != 6);
}

void menu::teacherMenu(const string& teacherName) {
    int choice;
    do {
        system("cls");
        UINT originalCodePage = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t         \u270F  TEACHER MENU\n";
        cout << "\t\t\t\t====================================\n";
        cout << "\n\t\t\t\t  1. Manage Students";
        cout << "\n\t\t\t\t  2. Manage Lectures";
        cout << "\n\t\t\t\t  3. Logout\n";
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t  Enter your choice: ";
        cin >> choice;
        SetConsoleOutputCP(originalCodePage);

        switch (choice) {
        case 1:
            system("cls");
            StudentMenu();
            break;
        case 2:
            system("cls");
            l.lect();
            break;
        case 3:
            system("cls");
            setConsoleColor(10); // Green for positive message
            cout << "\n\t\t\t\tLogging out...\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
            break;
        default:
            setConsoleColor(12); // Red for error
            cout << "\n\t\t\t\tInvalid choice!\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
        }
    } while (choice != 3);
}

void menu::StudentMenu() {
    int choice;
    do {
        system("cls");
        UINT originalCodePage = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t          \U0001F4A1 STUDENT MENU\n";
        cout << "\t\t\t\t====================================\n";
        cout << "\n\t\t\t\t  1. Add Student";
        cout << "\n\t\t\t\t  2. Add Graduate Student";
        cout << "\n\t\t\t\t  3. Display All Students";
        cout << "\n\t\t\t\t  4. Display All Graduate Students";
        cout << "\n\t\t\t\t  5. Add Lecture Data";
        cout << "\n\t\t\t\t  6. Delete Lecture";
        cout << "\n\t\t\t\t  7. Show Lecture Data";
        cout << "\n\t\t\t\t  8. Mark Attendence";
        cout << "\n\t\t\t\t  9. Exit";
        cout << "\n\t\t\t\t====================================\n";
        cout << "\t\t\t\t  Choice: ";
        cin >> choice;
        SetConsoleOutputCP(originalCodePage);
        cin.ignore();

        switch (choice) {
        case 1: {
            system("cls");
            string regNo, name;
            char gender;
            cout << "\n\t\t\t\tEnter Registration No: ";
            getline(cin, regNo);
            cout << "\n\t\t\t\tEnter Name: ";
            getline(cin, name);
            cout << "\n\t\t\t\tEnter Gender (M/F): ";
            cin >> gender;
            cin.ignore();
            students.emplace_back(regNo, name, gender);
            setConsoleColor(10); // Green for positive message
            cout << "\n\t\t\t\tStudent added successfully!\n";
            setConsoleColor(7); // Reset to default
            break;
        }
        case 2: {
            system("cls");
            string regNo, name, degreeProgram;
            char gender;
            cout << "\n\t\t\t\tEnter Registration No: ";
            getline(cin, regNo);
            cout << "\n\t\t\t\tEnter Name: ";
            getline(cin, name);
            cout << "\n\t\t\t\tEnter Gender (M/F): ";
            cin >> gender;
            cin.ignore();
            cout << "\n\t\t\t\tEnter Degree Program: ";
            getline(cin, degreeProgram);
            gradStudents.emplace_back(regNo, name, gender, degreeProgram);
            setConsoleColor(10); // Green for positive message
            cout << "\n\t\t\t\tGraduate Student added successfully!\n";
            setConsoleColor(7); // Reset to default
            break;
        }
        case 3: {
            system("cls");
            if (students.empty()) {
                setConsoleColor(12); // Red for error
                cout << "\n\t\t\t\tNo students to display!\n";
                setConsoleColor(7); // Reset to default
            } else {
                cout << "\n\t\t\t\tStudent List:\n";
                Student::displayStudentArray(students);
            }
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            if (gradStudents.empty()) {
                setConsoleColor(12); // Red for error
                cout << "\n\t\t\t\tNo graduate students to display!\n";
                setConsoleColor(7); // Reset to default
            } else {
                cout << "\n\t\t\t\tGraduate Student List:\n";
                for (const auto& gradStudent : gradStudents) {
                    gradStudent.printInfo();
                    cout << "\n";
                }
            }
            system("pause");
            break;
        }
        case 5:
            system("cls");
            l.addLectures();
            sleep(2);
            break;
        case 6:
            system("cls");
            l.deleteLecture();
            system("pause");
            break;
        case 7:
            system("cls");
            l.showLecdata();
            system("pause");
            break;
        case 8:
            system("cls");
            a.attend();
            sleep(2);
            break;
        case 9:
            system("cls");
            setConsoleColor(10); // Green for positive message
            cout << "\n\t\t\t\tExiting...\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
            break;
        default:
            setConsoleColor(12); // Red for error
            cout << "\n\t\t\t\tInvalid choice. Please try again.\n";
            sleep(2);
            setConsoleColor(7); // Reset to default
        }
    } while (choice != 9);
}
