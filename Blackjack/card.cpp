
#include "Card.h"
#include <iostream>
#include <vector>

// Constructorul inițializează un card cu valoarea și simbolul dat
Card::Card(int v, string s) : value(v), suit(s) {}
Card::Card(const string& cardName, const string& suit, int value)
    : cardName(cardName), suit(suit), value(value) {}

// Metoda returnează valoarea pentru Blackjack; cărțile mari (J, Q, K) au valoarea 10
int Card::getValue() const {
    if (value > 11) {
        return 10;  // Valet, Dama, Rege
    }
    return value;  // AS (1) sau alte cărți
}

// Afișează cardul în format "Valoare de Suită"
void Card::printCard() const {
    cout << cardName << " de " << suit << endl;
   // cout << value << " de " << suit << endl;
}

void printHand(const vector<Card>& hand) {
    for (const auto& card : hand) {
        cout << card.getCardName() << " de " << card.getValue() << endl;
    }
}
