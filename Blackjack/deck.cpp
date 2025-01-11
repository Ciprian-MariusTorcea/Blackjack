
#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Constructorul inițializează pachetul cu toate cele 52 de cărți
Deck::Deck() {
    const string suits[] = { "Inima", "Romb", "Trefla", "Pica"};
    string cardName;
    int value;
    for (const auto& suit : suits) {
        for (int i = 1; i <= 14; ++i) {
        
            if (i == 1) {
                cardName = "Ace";
                value = 1;
            }
            else if (i == 11) {
                cardName = "Ace";
                value = 11;
            }
            else {
                cardName = to_string(i);
                value = i;
            }
      
            cards.emplace_back(cardName, suit, value);  // Adaugă fiecare carte în pachet
        }
    }
}

// Metoda amestecă cărțile folosind funcția random_shuffle
void Deck::shuffle() {
    srand(static_cast<unsigned int>(time(0)));  // Inițializează generatorul de numere aleatoare
    random_shuffle(cards.begin(), cards.end());
}

// Metoda extrage și returnează ultima carte din pachet
Card Deck::dealCard() {
    Card card = cards.back();
    cards.pop_back();  // Elimină cartea din pachet
    return card;
}
