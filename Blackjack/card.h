#pragma once

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

// Clasa Card reprezintă un card individual din pachet
class Card {
public:
    Card(int v, string s);         // Constructor care inițializează valoarea și simbolul
    int getValue() const;          // Returnează valoarea ajustată pentru Blackjack (10 pentru J, Q, K)
    void printCard() const;        // Afișează cardul

private:
    int value;                     // Valoarea numerică a cardului
    string suit;                   // Simbolul cardului (Inimă, Romb, etc.)
};

#endif // CARD_H
