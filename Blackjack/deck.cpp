
#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Constructorul inițializează pachetul cu toate cele 52 de cărți
Deck::Deck() {
    const string suits[] = { "Inima", "Romb", "Treflă", "Pică" };
    for (const auto& suit : suits) {
        for (int i = 1; i <= 13; ++i) {
            cards.emplace_back(i, suit);  // Adaugă fiecare carte în pachet
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
