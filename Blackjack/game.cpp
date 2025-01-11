
#include "Game.h"
#include <iostream>
using namespace std;

// Constructorul inițializează jocul și extrage primele cărți pentru jucător și dealer
Game::Game() {
    deck.shuffle();            // Amestecă pachetul de cărți
    player.drawCard(deck);      // Jucătorul trage două cărți
    player.drawCard(deck);
    dealer.drawCard(deck);      // Dealerul trage două cărți
    dealer.drawCard(deck);
}

// Metoda principală de joc pentru o rundă de Blackjack
void Game::play() {
    cout << "Mana jucatorului:\n";
    player.showHand();
    cout << "Scorul jucatorului: " << player.calculateHandValue() << "\n";

    // Verifică dacă jucătorul are Blackjack
    if (player.hasBlackJack()) {
        cout << "Blackjack! Ai castigat!\n";
        return; // Termină jocul, jucătorul câștigă automat
    }

    // Jucătorul decide dacă trage o carte sau se oprește
    while (player.calculateHandValue() < 21) {
        char choice;
        cout << "Doresti sa tragi o carte (h) sau sa te opresti (s)? ";
        cin >> choice;
        if (choice == 'h') {
            player.drawCard(deck);  // Jucătorul trage o carte
            cout << "Ai tras:\n";
            player.showHand();
            cout << "Scorul jucatorului: " << player.calculateHandValue() << "\n";
        }
        else {
            break;
        }
    }

    // Verifică dacă jucătorul a depășit scorul de 21
    if (player.getScore() > 21) {
        cout << "Ai depasit 21! Ai pierdut.\n";
        return;
    }

    // Dealerul își joacă mâna, trăgând cărți până la 17
    cout << "Mana dealerului:\n";
    dealer.showHand();
    cout << "Scorul dealerului: " << dealer.calculateHandValue() << "\n";

    while (dealer.calculateHandValue() < 17) {
        dealer.drawCard(deck);
        cout << "Dealerul a tras o carte.\n";
        dealer.showHand();
        cout << "Scorul dealerului: " << dealer.calculateHandValue() << "\n";
    }

    // Se determină câștigătorul jocului
    int playerScore = player.calculateHandValue();
    int dealerScore = dealer.calculateHandValue();

    if (dealerScore > 21 || playerScore > dealerScore) {
        cout << "Ai castigat!\n";
    }
    else if (playerScore < dealerScore) {
        cout << "Ai pierdut.\n";
    }
    else {
        cout << "Egalitate.\n";
    }
}



Player& Game::getPlayer() {
    return player;
}

Player& Game::getDealer() {
    return dealer;
}
