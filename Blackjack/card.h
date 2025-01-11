#pragma once

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

// Clasa Card reprezintă un card individual din pachet
class Card {
public:
    Card(int v, string s);        // Constructor care inițializează valoarea și simbolul
   
    Card(const string& cardName, const string& suit, int value);

    int getValue() const;          // Returnează valoarea ajustată pentru Blackjack (10 pentru J, Q, K)
    void printCard() const;        // Afișează cardul
    string getCardName() const { return cardName; } // Returneaza numele cartii
    string getSuit() const { return suit; } //Returneaza simbolul cartii

  

private:
    int value;                     // Valoarea numerică a cardului
    string suit;                   // Simbolul cardului (Inimă, Romb, etc.)
    string cardName;              // Numele cărții (Ace, Valet, etc.)
};

#endif // CARD_H
