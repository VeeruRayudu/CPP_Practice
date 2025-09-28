#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include<vector>
#include "Veera_Sept25_task2_Card.h"

class DeckOfCards{
    private:
    std::vector<Card> deck;   
    int currentCard;//index of next card

    public:
    DeckOfCards(); 
    void shuffle();       
    Card dealCard();      
    bool moreCards() const; 

};

#endif
