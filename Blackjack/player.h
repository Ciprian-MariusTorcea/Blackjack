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

private:
    vector<Card> hand;           // Vector cu toate cărțile din mână
};

#endif // PLAYER_H
