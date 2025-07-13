#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <string>
using namespace std;

// Declare file streams and associated filenames
extern fstream batch;       // For batch operations
extern fstream lectures_d; // For lecture-related operations
extern fstream attend;     // For attendance operations
extern string filename;    // General file name holder

#endif // FILE_MANAGER_H