#include "batch.h"
#include "filemanager.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

//added in filemanager.h to handle fileinput output operation externally using global variables 
fstream batch;
fstream lectures_d;
fstream attend;
string filename;


// Main function for student details
void batchmodule::std_details() {
    int choice;

    cout << "Select from below:\n 1.Add New Batch\n 2.Add New Student \n 3.Update Student Record \n 4.Show Students \n5.Back\n Enter: ";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1:
        batchmodule::addNewBatch();
        break;

    case 2:
        batchmodule::addNewStudent();
        
        break;

    case 3:
        batchmodule::updateStudentRecord();
       
        break;

    case 4:
        batchmodule::showStudents();
        
        break;

    case 5:
        return;
    
    default:
        cout << "Invalid choice. Try again.\n";
        
    }
}

void batchmodule::addNewBatch() {
    int nbatch, snum;
    string cl_sec;

    cout << "Number of Sections to add: ";
    cin >> nbatch;

    for (int j = 0; j < nbatch; j++) {
        cout << "Enter Class and Section of your " << j + 1 << " Class: ";
        cin >> cl_sec;

        for (int i = 0; i < cl_sec.length(); i++) {
            if (isalpha(cl_sec[i]))
                cl_sec[i] = toupper(cl_sec[i]);
        }

        filename = "Class " + cl_sec + " Students.txt";
        batch.open(filename.c_str(), ios::out | ios::app);

        cout << "Enter Number Of Students Enrolled in your course: ";
        cin >> snum;

//        student s[snum];
//		Array Functions
		std s[snum];
        batch << "Class/Section/" << cl_sec << "\nRegistration_Number|Student_Name|Gender\n";

        for (int i = 0; i < snum; i++) {
            cout << "\nStudent " << i + 1 << " Name: ";
            getline(cin >> ws, s[i].sname);
            cout << "Registration Number: ";
            getline(cin >> ws, s[i].regno);
            cout << "Gender: ";
            cin >> s[i].sgender;
            batch << s[i].regno << "|" << s[i].sname << "|" << s[i].sgender << "\n";
        }

        batch.close();
    }
}

void batchmodule::addNewStudent() {
    std c;//obj of structure std 
    cout << "To Add New Student.\n";
    batchfound();
    batch.open(filename.c_str(), ios::out | ios::app);

    cout << "Name: ";
    getline(cin >> ws, c.sname);
    cout << "Registration Number: ";
    getline(cin >> ws, c.regno);
    cout << "Gender: ";
    cin >> c.sgender;
    batch << c.regno << "|" << c.sname << "|" << c.sgender << "\n";

    batch.close();
}

void batchmodule::updateStudentRecord() {
    int updateChoice;
    cout << "\n\t\t\t\t 1.To Update Whole Record\n\t\t\t\t 2.To Update Specific Record\n\n\t\t\t\t Choice: ";
    cin >> updateChoice;

    switch (updateChoice) {
    case 1:
        batchmodule::updateWholeRecord();
        break;

    case 2:
        batchmodule::updateSpecificRecord();
        break;

    default:
        cout << "Invalid choice.\n";
    }
}

void batchmodule::updateWholeRecord() {
    int cho, snum;
    string cl_sec;

    cout << "\n\t\t\t\tEnter Student Class and Section to Update the Record\n";
    batchfound();
    cout << "\n\t\t\t\tPlease note that it will delete all your previous records.\n";
    cout << "\n\t\t\t\tPress 1 to Continue or 2 to Abort: ";
    cin >> cho;

    if (cho == 1) {
        cout << "\n\t\t\t\tEnter Number Of Students Enrolled in your course: ";
        cin >> snum;

        std s[snum];
        batch.open(filename.c_str(), ios::out | ios::trunc);
        batch << "Class/Section/" << cl_sec << "\nRegistration_Number|Student_Name\n";

        for (int i = 0; i < snum; i++) {
            cout << "Student " << i + 1 << " Name: ";
            getline(cin >> ws, s[i].sname);
            cout << "Registration Number: ";
            getline(cin >> ws, s[i].regno);
            cout << "Gender: ";
            cin >> s[i].sgender;
            batch << s[i].regno << "|" << s[i].sname << "|" << s[i].sgender << "\n";
        }

        batch.close();
    }
}

void batchmodule::updateSpecificRecord() {
    string inreg, rline;
    bool regfound = false;

    cout << "\n\t\t\t\tFor Updating a Specific Student Record.\n";
    batchfound(); // Displays available batches.

    while (true) { // Retry loop for invalid inputs.
        regfound = false; // Reset flag for each retry.
        cout << "\n\t\t\t\tEnter Registration Number: ";
        getline(cin >> ws, inreg);

        ifstream batch(filename.c_str(), ios::in);
        ofstream tempfile("tempFile.txt");

        while (getline(batch, rline)) {
            stringstream ss(rline);
            string record[3];
            for (int i = 0; i < 3 && getline(ss, record[i], '|'); ++i); // Split record by '|'.

            if (inreg == record[0]) {
                regfound = true;
                cout << "\n\t\t\t\tRecord Found.\n\nThis is the Current Data:\n";
                cout << "\n\t\t\t\tRegistration No: " << record[0] << "\n\t\t\t\tName: " << record[1] 
                     << "\n\t\t\t\tGender: " << record[2] << endl;

                while (true) {
                    cout << "\n\t\t\t\tWhat do you want to update?\n\t\t\t\t 1.Registration Number\n\t\t\t\t 2.Name\n\t\t\t\t 3.Gender\n\t\t\t\tEnter: ";
                    int choice;
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            string newreg;
                            cout << "\n\t\t\t\tEnter New Registration Number: ";
                            getline(cin >> ws, newreg);

                            // Check if the new registration number already exists.
                            ifstream checkfile(filename.c_str(), ios::in);
                            string checkLine;
                            bool regTaken = false;

                            while (getline(checkfile, checkLine)) {
                                stringstream checkSS(checkLine);
                                string regCheck;
                                getline(checkSS, regCheck, '|');

                                if (regCheck == newreg) {
                                    cout << "\n\t\t\t\tRegistration Number already exists. Please choose another.\n";
                                    regTaken = true;
                                    break;
                                }
                            }
                            checkfile.close();

                            if (regTaken) continue; // Retry entering new registration number.

                            tempfile << newreg << "|" << record[1] << "|" << record[2] << "\n";
                            cout << "Updated Record:\nRegistration #: " << newreg 
                                 << "\nName: " << record[1] << "\nGender: " << record[2] << "\n";
                            break;
                        }
                        case 2: {
                            string newname;
                            cout << "\n\t\t\t\tEnter New Name: ";
                            getline(cin >> ws, newname);

                            tempfile << record[0] << "|" << newname << "|" << record[2] << "\n";
                            cout << "Updated Record:\nRegistration #: " << record[0] 
                                 << "\nName: " << newname << "\nGender: " << record[2] << "\n";
                            break;
                        }
                        case 3: {
                            char newgen;
                            cout << "\n\t\t\t\tEnter New Gender: ";
                            cin >> newgen;

                            tempfile << record[0] << "|" << record[1] << "|" << newgen << "\n";
                            cout << "Updated Record:\nRegistration #: " << record[0] 
                                 << "\nName: " << record[1] << "\nGender: " << newgen << "\n";
                            break;
                        }
                        default:
                            cout << "\n\t\t\t\tInvalid Option. Please Try Again.\n";
                            continue;
                    }
                    break; // Exit inner loop after successful update.
                }
            } else {
                tempfile << record[0] << "|" << record[1] << "|" << record[2] << "\n"; // Copy unchanged records.
            }
        }

        batch.close();
        tempfile.close();

        if (!regfound) {
            int retryOption;
            cout << "\n\t\t\t\tNo Record Found for this Registration Number.\n 1.Re-Enter \n 2.Back \nEnter: ";
            cin >> retryOption;
            if (retryOption == 1) {
                continue;
            } else if (retryOption == 2) {
                remove("tempFile.txt"); // Clean up temporary file.
                return;
            } else {
                cout << "\n\t\t\t\tInvalid Input. Please Retry.\n";
                continue;
            }
        } else {
            remove(filename.c_str());
            rename("tempFile.txt", filename.c_str());
            cout << "\n\t\t\t\tRecord Updated Successfully.\n";
            return;
        }
    }
}

void batchmodule::batchfound() {
    string nw_std;
    bool f_exist = false;

    do {
        if (f_exist) {
            cout << "\n\t\t\t\tSection not found. Please re-enter.\n";
        }

        cout << "\n\t\t\t\tEnter Class and Section of the Student: ";
        getline(cin >> ws, nw_std);

        // Convert input to uppercase
        for (char &ch : nw_std) {
            if (isalpha(ch)) {
                ch = toupper(ch);
            }
        }

        filename = "Class " + nw_std + " Students.txt";
        batch.open(filename.c_str(), ios::in);

        if (batch.is_open()) {
            f_exist = true;
            batch.close();
        } else {
            f_exist = false;
        }
    } while (!f_exist);
}

void batchmodule::showStudents() {

	batchmodule::batchfound();
	batch.open(filename.c_str(),ios::in);
	string showline, regn, name, gender;
	int lineCounter=0;
	while(getline(batch,showline))
	{
		lineCounter++;
		if(lineCounter<3)
		continue;
		
            stringstream ss(showline);
            getline(ss, regn, '|');
            getline(ss, name, '|');
            getline(ss, gender, '|');
			
			cout<<"\n\t\t\t\t Name: "<<name<<"\n\t\t\t\t Registration: "<<regn<<"\n\t\t\t\t Gender: "<<gender<<endl;	
	
	}
	}
//array function
// Function to output the contents of a Student array 
void batchmodule::printStudentArray(std std[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "  Registration No: " << std[i].regno << "\n";
        cout << "  Name: " << std[i].sname << "\n";
        cout << "  Gender: " << std[i].sgender << "\n";
        cout << endl;
    }
}