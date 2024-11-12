
#include "Card.h"
#include <iostream>

// Constructorul inițializează un card cu valoarea și simbolul dat
Card::Card(int v, string s) : value(v), suit(s) {}

// Metoda returnează valoarea pentru Blackjack; cărțile mari (J, Q, K) au valoarea 10
int Card::getValue() const {
    return value > 10 ? 10 : value;
}

// Afișează cardul în format "Valoare de Suită"
void Card::printCard() const {
    cout << value << " de " << suit << endl;
}
