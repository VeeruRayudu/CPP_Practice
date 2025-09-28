#include "Veera_Sept25_task2_DeckOfCards.h"
#include<algorithm>
#include<random>
#include<ctime>

// constructor intialization
DeckOfCards::DeckOfCards(){
    currentCard=0;
    for (int s=0;s<4;s++) {
        for (int f=0;f<13;f++) {
            deck.push_back(Card(f, s));
        }
    }
}

// shuffle using Fisher-Yates
void DeckOfCards::shuffle() {
    currentCard = 0; // reset dealing position
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

// deal one card
Card DeckOfCards::dealCard(){
    if(moreCards()) {
        return deck[currentCard++];
    }
   
    return Card(-1, -1); // If no more cards, return dummy
}

bool DeckOfCards::moreCards() const {
    return (currentCard < deck.size());
}
