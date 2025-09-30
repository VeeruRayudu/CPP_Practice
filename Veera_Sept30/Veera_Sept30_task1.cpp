#include<iostream>

int main(){
    //a
    int const SIZE = 5;
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    //b
    unsigned int *vPtr;

    //c
    for(int i=0; i<SIZE; i++){
        std::cout<<values[i]<<" ";
    }
    std::cout<<"\n";

    //d
    vPtr = &values[0];
    vPtr = values;

    //e
    for(int j=0; j<SIZE; j++){
        std::cout<<*(vPtr+j)<<" ";
    }
    std::cout<<"\n";

    //f
    for(int k=0; k<SIZE; k++){
        std::cout<<*(values+k)<<" ";
    }
    std::cout<<"\n";

    //g
    for(int x=0; x<SIZE; x++){
        std::cout<<vPtr[x]<<" ";
    }
    std::cout<<"\n";

    //h
    std::cout<<"Fifth Element using array subscript notation: "<<values[4]<<std::endl;
    std::cout<<"Fifth Element using  pointer/offset notation with the array name as the pointer: "<<*(values+4)<<std::endl;
    std::cout<<"Fifth Element using pointer subscript notation: "<<vPtr[4]<<std::endl;
    std::cout<<"Fifth Element using pointer/offset notation: "<<*(vPtr+4)<<std::endl;

    //i
    std::cout<<"Address referenced by vPtr+3: "<<vPtr+3<<std::endl;
    std::cout<<"Value at the location vPtr+3: "<<*(vPtr+3)<<std::endl;

    //j
    vPtr = &values[4];
    std::cout<<"Address referenced by vPtr-4: "<<vPtr-4<<std::endl;
    std::cout<<"Value at the location vPtr-4: "<<*(vPtr-4)<<std::endl;






}
