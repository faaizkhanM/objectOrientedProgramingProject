#ifndef MENU_H
#define MENU_H

#include "Student.h"
#include "Lecture.h"
#include "attendence.h"
#include "batch.h"
#include "loading.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

class menu{
	private:
		//Composition 
//		Vectors
		vector<Student> students;
    	vector<GraduateStudent> gradStudents;
		Student s;
		Lecture l;
		loadinganimation la;	
		batchmodule b;
	public:
		attendence a;
		
		menu() : a(new ClassSection(), new Lectureclass(), new markAttendance()) {
        // Initialize other members if necessary
    }
	void mainmenu();
	bool authenticateAdmin();
	// Function to authenticate teacher
	bool authenticateTeacher(string& teacherName);
	// Admin menu
	void adminMenu();
	// Teacher menu
	void teacherMenu(const string& teacherName);
	void StudentMenu();
	 
	void concepts(){
		cout<<"\n\t\t\t\t----Function overloading----------\n";
		sleep(2);
		s.printInfo();
		sleep(2);
		cout<<"\n\t\t\t\t----Composition------------\n";
		
		
	}
	
	~menu() {
    	// Destructor implementation
    	UINT originalCodePage = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
    	cout << "\n\t\t\t\tLOVE YOU SIR \U00002764\n\n\t\t\t\tItnay pyar ke tou Full Bantay hain \U0001F60D" << endl;
		}

};


#endif