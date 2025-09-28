#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

int rollDice();

int main(){
    enum Status{ CONTINUE, WON, LOST };
    
    const int GAMES =1000;
    int wins[22] = {0};
    int losses[22] = {0};
    int totalRolls = 0;
    int totalWins = 0, totalLosses = 0;

    srand(time(0));

    for(int i=0;i<GAMES;i++){

        int myPoint;
        Status gameStatus;
        int rollCount = 1;

        int sumOfDice = rollDice();

        switch (sumOfDice)
        {
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            break;
        }

        while (gameStatus == CONTINUE)
        {
            sumOfDice = rollDice();
            rollCount++;
            if(sumOfDice == myPoint){
                gameStatus = WON;
            }else{
                if(sumOfDice == 7){
                    gameStatus = LOST;
                }
            }
        }

        if(rollCount > 20) rollCount = 21;

        if(gameStatus == WON){
            wins[rollCount]++;
            totalWins++;
        }else{
            losses[rollCount]++;
            totalLosses++;
        }

        totalRolls += rollCount;
        
    }

    std::cout<<std::setw(10)<<"Roll"<<std::setw(10)<<"Wins"<<std::setw(10)<<"Losses"<<std::endl;

    for(int i=1;i<=20;i++){
        std::cout<<std::setw(10)<<i<<std::setw(10)<<wins[i]<<std::setw(10)<<losses[i]<<std::endl;
    }

    std::cout<<std::setw(10)<<">20"<<std::setw(10)<<wins[21]<<std::setw(10)<<losses[21]<<std::endl;

    std::cout<<"\ntotal wins: "<<totalWins<<"\ntotal losses: "<<totalLosses<<std::endl;

    std::cout<<"\n Chances of Winning: "<<(100.0*totalWins)/GAMES<<"%\n";

    std::cout<<"Average Length : "<<totalRolls/GAMES<<" rolls"<<std::endl;

    return 0;
}

int rollDice(){
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;

    return die1 + die2;
}