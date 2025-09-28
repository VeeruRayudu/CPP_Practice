#ifndef CARD_H
#define CARD_H
#include<string>

class Card{
    private:
    int face; 
    int suit; 
    static const std::string faces[13];
    static const std::string suits[4];

    public:
    // constructor
    Card(int=0, int=0); 
    //getters
    int getFace() const;
    int getSuit() const;
    
    std::string toString() const; 
};

#endif
