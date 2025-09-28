#include<iostream>


int main(){
    const int SIZE = 20;
    int array[SIZE];
    int countUnique;
    std::cout<<"Enter 20 numbers between 10 - 100: ";
    for(int i=0;i<SIZE;i++){
        int n;
        std::cin>>n;
        if(n<=10 || n>=100){
            std::cout<<"invalid, enter a number between 10 and 100";
            std::cin>>n;
        }
        bool isDuplicate = false;
        for(int i=0;i<countUnique;i++){
        if(array[i] == n){
            isDuplicate = true;
            break;
        }
    }
    if(!isDuplicate){
        array[countUnique] = n;
        countUnique++;
    }
    }
    for(int i=0;i<countUnique;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}