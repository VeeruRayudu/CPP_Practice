#include<iostream>
#include "Veera_Sept25_task2_DeckOfCards.h"

int main(){
    DeckOfCards deck;

    deck.shuffle();

    std::cout<<"Dealing 52 cards:\n"<<std::endl;
    int count = 0;
    while (deck.moreCards()) {
        std::cout<<deck.dealCard().toString()<<"\t";
        count++;
        if(count%4 == 0){
            std::cout<<std::endl;
        }
    }
    return 0;
}
