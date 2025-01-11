
#include "Player.h"
#include <iostream>
;
// Metoda permite jucătorului să tragă o carte din pachet
void Player::drawCard(Deck& deck) {
    hand.push_back(deck.dealCard());  // Adaugă o carte în mână
}

// Metoda calculează scorul jucătorului, luând în considerare valoarea specială a Asului
int Player::getScore() const {
    int score = 0; // Scorul total
    int aces = 0;  // Numărăm câte AS-uri sunt

    // Calculăm scorul inițial și numărăm AS-urile
    for (const auto& card : hand) {
        int cardValue = card.getValue();

        if (cardValue == 1) { // AS detectat
            aces++; // Incrementăm numărul de AS-uri
            score += 11; // Considerăm AS-ul ca 11 inițial
        }
        else {
            score += cardValue; // Adăugăm valoarea normală a cărților
        }
    }

    // Ajustăm valoarea AS-urilor doar dacă scorul depășește 21
    while (score > 21 && aces > 0) {
        score -= 10; // Ajustăm un AS din 11 în 1
        aces--;      // Reducem numărul de AS-uri disponibile pentru ajustare
    }

    return score;
}


int Player::calculateHandValue() {
    int totalValue = 0;
    int aceCount = 0;

    for (const auto& card : hand) {
        if (card.getCardName() == "Ace") {
            ++aceCount;
            totalValue += 11; // Inițial tratează AS-ul ca 11
        }
        else {
            totalValue += card.getValue();
        }
    }

    // Ajustează valoarea AS-urilor dacă totalul depășește 21
    while (totalValue > 21 && aceCount > 0) {
        totalValue -= 10; // Transformă un AS din 11 în 1
        --aceCount;
    }

    return totalValue;
}
// Metoda afișează cărțile din mână și scorul curent
void Player::showHand() const {
    for (const auto& card : hand) {
        card.printCard();  // Afișează fiecare carte
    }
    cout << "Scor: " << getScore() << endl;
}

const vector<Card>& Player::getHand() const {
    return hand;
}

bool Player::hasBlackJack() const {
    return hand.size() == 2 && getScore() == 21;
}
