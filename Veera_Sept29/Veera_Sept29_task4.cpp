#include<iostream>
#define SIZE 70

char track[SIZE] = {' '};
void moveTortoise(int *pos);
void moveHare(int *pos);
void printRace(int tortoisePos, int harePos);

int main(){
    int tortoise = 1, hare = 1;
    srand((time(0)));
    std::cout<<"BANG !!!!\n"<<"AND THEY'RE OFF !!!!"<<std::endl;
    while(tortoise<SIZE && hare<SIZE){
        moveTortoise(&tortoise);
        moveHare(&hare);

        if(tortoise<1) tortoise = 1;
        if(hare < 1) hare = 1;

        printRace(tortoise, hare);
    }

    if(tortoise>=SIZE && hare>=SIZE){
        std::cout<<"It's a tie"<<std::endl;
    }else if(tortoise >= SIZE){
        std::cout<<"TORTOISE WINS!!! YAY!!!"<<std::endl;
    }else{
        std::cout<<"Hare wins. Yuch"<<std::endl;
    }
}

void moveTortoise(int *pos){
    int i = 1+rand()%10;

    if(i>=1 && i<=5){
        *pos += 3;
    }else if(i==6 || i==7){
        *pos -= 6;
    }else{
        *pos += 1;
    }
}

void moveHare(int *pos){
    int i = 1+rand()%10;

    if(i==1 && i==2){
        *pos += 0;
    }else if(i==3 || i==4){
        *pos += 9;
    }else if(i==5){
        *pos -= 12;
    }else if(i>=6 && i<=8){
        *pos += 1;
    }else{
        *pos -= 2;
    }
}

void printRace(int tortoisePos, int harePos){
    std::string track(SIZE, ' ');

    if(tortoisePos == harePos){
        track.replace(tortoisePos - 1, 5, "OUCH!");
    }else {
        if(tortoisePos<=SIZE){
        track[tortoisePos-1] = 'T';
        }
        if(harePos<=SIZE){
            track[harePos-1] = 'H';
        }
    }
    std::cout<<track<<std::endl;
}


