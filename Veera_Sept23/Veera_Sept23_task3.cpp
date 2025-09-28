#include<iostream>
#include<string>

const int SIZE = 10;
bool seats[SIZE] = {false};
int type;
int economy = 5, firstClass = 0;

void bookFirstClass();
void bookEconomy();


int main(){
    int choice;
    do{
        bool seatsFull = true;
        for(int i=0;i<SIZE;i++){
            if(!seats[i]){
                seatsFull = false;
                break;
            }
        }
        if(seatsFull){
            std::cout<<"All seats are full, Next flight leaves in 3 hrs.\n";
            break;
        }

        std::cout<<"\n Please type 1 for 'First Class', 2 for 'Second Class' ";
        std::cin>>type;

        if(type == 1){
            bookFirstClass();
        }else if(type == 2){
            bookEconomy();
        }else{
            std::cout<<"Next flight leaves in 3 hrs"<<std::endl;
            break;
        }
        std::cout<<"Enter '1' for Reservation OR '2' to Exit ";
        std::cin>>choice;
    }while(choice == 1) ;

    return 0; 
}

void bookFirstClass(){
    int choice = 0;
    if(firstClass<5){
        seats[firstClass] = true;
        std::cout<<"Seat assigned "<<firstClass+1<<" in the FirstClass section"<<std::endl;
        firstClass++;
    }else{
        if(economy<10){
        std::cout<<"\nFirst Class is full, would you prefer Economy? Enter '1' for Yes OR '0' for No ";
        std::cin>>choice;
        if(choice == 1){
            bookEconomy();
        }else{
            std::cout<<"Next flight leaves in 3 hrs"<<std::endl;
        }
        }
    }
}

void bookEconomy(){
    int choice = 0;
    if(economy<10){
        seats[economy] = true;
        std::cout<<"Seat assigned "<<economy+1<<" in the  Economy section"<<std::endl;
        economy++;
    }else{
        if(firstClass<5){
        std::cout<<"\nEconomy is full, would you prefer First Class ?Enter '1' for Yes OR '0' for No";
        std::cin>>choice;
        if(choice == 1){
            bookFirstClass();
        }else{
            std::cout<<"Next flight leaves in 3 hrs"<<std::endl;
        }
        }
    }
}