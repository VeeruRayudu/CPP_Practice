#include <iostream>
#include "Veera_Sept22_task1_GradeBook.h"

//constructor initialization
GradeBook::GradeBook(std::string courseName_, std::string instructorName_){
    GradeBook::setCourseName(courseName_);
    GradeBook::setInstructorName(instructorName_);
}

//setters definition
void GradeBook::setCourseName(const std::string courseName_){
    courseName = courseName_;
}

void GradeBook::setInstructorName(const std::string instructorName_){
    instructorName = instructorName_;
}

//getters definition
std::string GradeBook::getCourseName() const {
    return courseName;
}

std::string GradeBook::getInstructorName() const{
    return instructorName;
}

//display function definition
void GradeBook::displayMessage() const {
    std::cout<<"Welcome to the grade book for\n"<<getCourseName()<<"!\n"<<"This is course is presented by "<<getInstructorName()<<std::endl;
}