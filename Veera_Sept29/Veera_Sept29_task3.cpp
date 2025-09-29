#include<iostream>

int main(){
   
    void exchange(double &x, double &y); //a
    void exchange(double *, double *); //b
    int evaluate(int x, int (*poly)(int)); //c
    char vowel[] = {'A', 'E', 'I', 'O', 'U'}; //d
    char vowel[] = "AEIOU"; //e
}