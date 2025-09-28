#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include "Veera_Sept25_task2_DeckOfCards.h"

// Functions
bool containsPair(const std::vector<Card> &hand) {
    std::map<int,int> freq;
    for (auto& c : hand){
        freq[c.getFace()]++;
    }
    for (auto& f : freq){
        if(f.second == 2) {
            return true;
        }
    return false;
    }
}

bool containsTwoPair(const std::vector<Card> &hand) {
    std::map<int,int> freq;
    int pairs = 0;
    for(auto& c : hand){
        freq[c.getFace()]++;
    }
    for(auto& f : freq){
        if(f.second == 2) pairs++;
    }
    return pairs == 2;
}

bool containsThreeOfKind(const std::vector<Card> &hand) {
    std::map<int,int> freq;
    for(auto& c : hand) {
        freq[c.getFace()]++;
    }
    for(auto& f : freq){
        if(f.second == 3){
            return true;
        }
    return false;
    }
}

bool containsFourOfKind(const std::vector<Card> &hand){
    std::map<int,int> freq;
    for(auto& c : hand){
        freq[c.getFace()]++;
    }
    for(auto& f : freq){
        if(f.second == 4) {
            return true;
        }
    }
    return false;
}

bool containsFlush(const std::vector<Card> &hand) {
    int suit =hand[0].getSuit();
    for (auto& c : hand) {
        if (c.getSuit() != suit) {
            return false;
        }
    }
    return true;
}

bool containsStraight(const std::vector<Card> &hand) {
    std::vector<int> faces;
    for (auto& c : hand) {
        faces.push_back(c.getFace());
    }

    sort(faces.begin(), faces.end());

    bool straight = true;
    for(int i=1;i<5;i++){
        if(faces[i] != faces[0]+i){
            straight = false;
        }
    }
    //Ace-low straight (A,2,3,4,5)
    if(!straight) {
        if(faces == std::vector<int>{0,1,2,3,12}) {
            return true;
        }
    }
    return straight;
}

int evaluateHand(const std::vector<Card> &hand) {
    bool flush = containsFlush(hand);
    bool straight = containsStraight(hand);

    // Straight Flush
    if(flush && straight) {
        return 8; 
    }
    
    if(containsFourOfKind(hand)) {
        return 7;
    }

    // Full house
    if(containsThreeOfKind(hand) && containsPair(hand)) {
        return 6; 
    }

    if(flush){
        return 5;
    }

    if(straight){
        return 4;
    }

    if(containsThreeOfKind(hand)){
        return 3;
    }

    if(containsTwoPair(hand)) return 2;

    if(containsPair(hand)) return 1;

    return 0; // High card
}

void printHand(const std::vector<Card> &hand) {
    for(auto& c : hand){
        std::cout<<c.toString()<<"\t";
    }
    std::cout<<std::endl;
}

int main() {
    DeckOfCards deck;
    deck.shuffle();

    std::vector<Card> hand1, hand2;

    // deal 5 cards to each hand
    for (int i = 0; i < 5; i++) hand1.push_back(deck.dealCard());
    for (int i = 0; i < 5; i++) hand2.push_back(deck.dealCard());

    std::cout<<"Hand 1: ";
    printHand(hand1);
    int score1 = evaluateHand(hand1);

    std::cout<<"Hand 2: ";
    printHand(hand2);
    int score2 = evaluateHand(hand2);

    std::cout<<"\nResult:\n";
    if(score1 > score2){
        std::cout<<"Hand 1 wins!"<<std::endl;
    }else if(score2 > score1){
        std::cout<< "Hand 2 wins!"<<std::endl;
    }else {
        std::cout<<"It's a tie!"<<std::endl;
    }

    return 0;
}
