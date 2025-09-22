#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include<string>

class GradeBook{
    private:
    std::string courseName;
    std::string instructorName;

    public:
    //constructor
    GradeBook(std::string courseName_, std::string instructorName_);

    //setters
    void setCourseName(const std::string courseName_);
    void setInstructorName(const std::string instructorName_);

    //getters
    std::string getCourseName() const;
    std::string getInstructorName() const;

    //Display function
    void displayMessage()const;
};

#endif