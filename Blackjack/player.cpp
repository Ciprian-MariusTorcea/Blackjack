
#include "Player.h"
#include <iostream>

// Metoda permite jucătorului să tragă o carte din pachet
void Player::drawCard(Deck& deck) {
    hand.push_back(deck.dealCard());  // Adaugă o carte în mână
}

// Metoda calculează scorul jucătorului, luând în considerare valoarea specială a Asului
int Player::getScore() const {
    int score = 0, aces = 0;
    for (const auto& card : hand) {
        int cardValue = card.getValue();
        score += cardValue;       // Adaugă valoarea fiecărei cărți
        if (cardValue == 1) aces++; // Numără Așii pentru calcul special
    }
    while (score <= 11 && aces > 0) {
        score += 10;  // Așii pot valora 11 dacă scorul total nu depășește 21
        aces--;
    }
    return score;
}

// Metoda afișează cărțile din mână și scorul curent
void Player::showHand() const {
    for (const auto& card : hand) {
        card.printCard();  // Afișează fiecare carte
    }
    cout << "Scor: " << getScore() << endl;
}
