#ifndef EXAM_H
#define EXAM_H
#include "4887766_CM1001_Date.h"

enum ExamType{ONLINE, OFFLINE};

class Exam{
    private:
    int m_examCode;
    ExamType m_examType;
    Date exam_date;

    public:
    Exam(int examCode_, ExamType examType_, unsigned int day_, unsigned int month_, unsigned int year_);
    ~Exam();
    Date& getDate();
    void display();
};

#endif