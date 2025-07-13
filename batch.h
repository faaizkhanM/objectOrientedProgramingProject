#ifndef BATCH_H
#define BATCH_H
#include <string>
#include <iostream>
using namespace std;


class batchmodule{
	
	public:
	
	void std_details();
	void batchfound();
	void addNewBatch();
	void addNewStudent();
	void updateStudentRecord();
	void showStudents();
	void updateWholeRecord();
	void updateSpecificRecord();
	struct std {
    string regno;
    string sname;
    char sgender;
	};
	//array function
	void printStudentArray(std std[], int size);
	~batchmodule() {
    // Destructor implementation
    cout << "\n\t\t\t\tDestroying batchmodule object" << endl;
}
		
		
	
};



#endif