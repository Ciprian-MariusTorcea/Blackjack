#pragma once

#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

// Clasa Game gestionează logica jocului Blackjack
class Game {
public:
    Game();             // Constructor care inițializează jocul și pachetul de cărți
    void play();        // Metoda principală pentru a juca o rundă de Blackjack

private:
    Deck deck;          // Pachetul de cărți
    Player player;      // Jucătorul
    Player dealer;      // Dealerul
};

#endif // GAME_H
