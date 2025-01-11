#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"
#include <vector>

// Clasa Player reprezintă un jucător care poate trage cărți și calcula scorul
class Player {
public:
    void drawCard(Deck& deck);   // Trage o carte din pachet
    int getScore() const;        // Calculează și returnează scorul jucătorului
    void showHand() const;       // Afișează toate cărțile din mână și scorul curent
    const vector<Card>& getHand() const; // Returnează mâna jucătorului
    void printHand(const vector<Card>& hand); // Afiseaza cartea din mana
    int calculateHandValue(); //Calculează și returnează valorea cartii din mana
    bool hasBlackJack() const; // Verifica daca jucatorul are un BlackJack

private:
    vector<Card> hand;           // Vector cu toate cărțile din mână
};

#endif // PLAYER_H
