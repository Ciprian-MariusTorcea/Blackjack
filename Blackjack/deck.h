#pragma once

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
using namespace std;

// Clasa Deck reprezintă un pachet de cărți de joc
class Deck {
public:
    Deck();                // Constructor care inițializează pachetul de 52 de cărți
    void shuffle();        // Amestecă pachetul de cărți
    Card dealCard();       // Extrage o carte din pachet

private:
    vector<Card> cards;    // Vector care conține toate cărțile din pachet
};

#endif // DECK_H
