#include <iostream>
#include "4887766_CM1001_Exam.h"

// constructor
Exam::Exam(int examCode_, ExamType examType_, unsigned int day_, unsigned int month_, unsigned int year_) : m_examCode(examCode_), m_examType(examType_), exam_date(day_, month_, year_) {};

Exam::~Exam(){};

Date &Exam::getDate()
{
    return exam_date;
}

std::string examTypeToString(ExamType type){
    switch (type)
    {
    case ExamType::OFFLINE: return "Offline";
    case ExamType::ONLINE: return "Online";
    default: return "Unknown";
    }
}

void Exam::display()
{
    std::cout << "Exam Code: " << m_examCode << ", Type: " << examTypeToString(m_examType)<<" ";
    exam_date.print();
}