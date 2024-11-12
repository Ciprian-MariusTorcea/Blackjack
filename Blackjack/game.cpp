
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
    cout << "Mâna jucătorului:\n";
    player.showHand();

    // Jucătorul decide dacă trage o carte sau se oprește
    while (player.getScore() < 21) {
        char choice;
        cout << "Dorești să tragi o carte (h) sau să te oprești (s)? ";
        cin >> choice;
        if (choice == 'h') {
            player.drawCard(deck);  // Jucătorul trage o carte
            cout << "Ai tras:\n";
            player.showHand();
        }
        else {
            break;
        }
    }

    // Verifică dacă jucătorul a depășit scorul de 21
    if (player.getScore() > 21) {
        cout << "Ai depășit 21! Ai pierdut.\n";
        return;
    }

    // Dealerul își joacă mâna, trăgând cărți până la 17
    cout << "Mâna dealerului:\n";
    dealer.showHand();

    while (dealer.getScore() < 17) {
        dealer.drawCard(deck);
        cout << "Dealerul a tras o carte.\n";
        dealer.showHand();
    }

    // Se determină câștigătorul jocului
    if (dealer.getScore() > 21 || player.getScore() > dealer.getScore()) {
        cout << "Ai câștigat!\n";
    }
    else if (player.getScore() < dealer.getScore()) {
        cout << "Ai pierdut.\n";
    }
    else {
        cout << "Egalitate.\n";
    }
}
