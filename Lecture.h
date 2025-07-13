#ifndef LECTURE_H
#define LECTURE_H

#include <string>

class Lecture {
private:
	//encapsulation done here 
    std::string courseTitle;
    std::string courseCode;
    std::string lectureTopic;
    std::string lectureType;
    std::string room;
    std::string date;

public:
    // Constructors ,Default Functions 
    Lecture();
    Lecture(const std::string& courseTitle, const std::string& courseCode, const std::string& lectureTopic,
            const std::string& lectureType, const std::string& room, const std::string& date);
    Lecture(const Lecture& other);
    ~Lecture();

    // Assignment operator
    Lecture& operator=(const Lecture& other);

    // Getters
    std::string getCourseTitle() const;
    std::string getCourseCode() const;
    std::string getLectureTopic() const;
    std::string getLectureType() const;
    std::string getRoom() const;
    std::string getDate() const;

    // Setters
    void setCourseTitle(const std::string& courseTitle);
    void setCourseCode(const std::string& courseCode);
    void setLectureTopic(const std::string& lectureTopic);
    void setLectureType(const std::string& lectureType);
    void setRoom(const std::string& room);
    void setDate(const std::string& date);

    // Menu and operations
    void lect();
    void addLectures();
    void showLecdata();
    void deleteLecture();
    
    // Overloaded setLectureDetails functions
	void setLectureDetails(const std::string& courseTitle, const std::string& courseCode, const std::string& lectureTopic,
	                       const std::string& lectureType, const std::string& room, const std::string& date);
	
	void setLectureDetails(const std::string& details, char delimiter);

private:
    // Helper functions
    bool fileExists(const std::string& filename);
    void formatClassSection(std::string& cl_sec);
    void writeLectureToFile(const std::string& filename, Lecture* l, int nlec);
    void deleteLectureFromFile(const std::string& filenameLec);
};

#endif // LECTURE_H
