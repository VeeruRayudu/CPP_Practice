#include "Veera_Sept25_task2_Card.h"

const std::string Card::faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

const std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// constructor initialization
Card::Card(int cardFace, int cardSuit) : face(cardFace), suit(cardSuit) {}

//getters
int Card::getFace() const { return face; }
int Card::getSuit() const { return suit; }

//card as string
std::string Card::toString() const {
    return faces[face] +" of "+ suits[suit];
}
