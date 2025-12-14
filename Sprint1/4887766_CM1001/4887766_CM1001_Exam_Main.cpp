#include <iostream>
#include "4887766_CM1001_Exam.h"

int main(){
    Exam exam1(101, ExamType::ONLINE, 15, 8, 2025);
    Exam exam2(102, ExamType::OFFLINE, 29, 2, 2024);
    Exam exam3(101, ExamType::ONLINE, 31, 4, 2023);

    exam1.getDate().checkDay(15);
    exam2.getDate().checkDay(29);
    // exam3.getDate().checkDay(31); -->invalid

    exam1.display();
    exam2.display();

    //TC1
    std::cout<<"\n-----------TC1---------------\n";
    Date date1(15,8,2025);
    int day = date1.checkDay(15);
    if(day == 15){
        std::cout<<"Valid"<<"\n";
    }

    //TC2
    std::cout<<"\n-----------TC2---------------\n";
    Date date2(29,2,2024);
    day = date2.checkDay(29);
    if(day == 29){
        std::cout<<"Valid"<<"\n";
    }

    //TC3
    std::cout<<"\n-----------TC3---------------\n";
    Date date3(31,4,2023);
    day = date3.checkDay(31);
    if(day == 31){
        std::cout<<"Valid"<<"\n";
    }

    //TC4
    std::cout<<"\n-----------TC4---------------\n";
    Date date4(30,2,2023);
    day = date4.checkDay(30);
    if(day == 30){
        std::cout<<"Valid"<<"\n";
    }

    //TC5
    std::cout<<"\n-----------TC5---------------\n";
    day = exam1.getDate().checkDay(15);
    if(day == 15){
        std::cout<<"Success"<<"\n";
    }

    //TC6
    std::cout<<"\n-----------TC6---------------\n";
    day = exam2.getDate().checkDay(29);
    if(day == 29){
        std::cout<<"Success"<<"\n";
    }

    //TC7
    std::cout<<"\n-----------TC7---------------\n";
    day = exam3.getDate().checkDay(31);
    if(day == 31){
        std::cout<<"Success"<<"\n";
    }

    return 0;
}