#include "Game.h"
#include <iostream>
#include <fstream>
#include <exception>
#include "player.h"

using namespace std;

// Funcția salvează progresul jucătorului într-un fișier TXT
void saveProgress(const Player& player, const Player& dealer) {
    try {
        // Deschide fișierul în modul out pentru a goli conținutul existent
        ofstream outFile("progress.txt", ios::app);
        if (!outFile) {
            throw runtime_error("Nu s-a putut deschide fisierul progress.txt pentru scriere.");
        }
        outFile << "===============================" << endl;
        outFile << "Progresul unui nou joc:" << endl;

        // Salvează informațiile despre jucător
        outFile << "Scorul jucatorului: " << player.getScore() << endl;
        outFile << "Mana jucatorului:" << endl;
        for (const auto& card : player.getHand()) {
            outFile << card.getValue() << " de " << card.getSuit() << endl;
        }

        // Salvează informațiile despre dealer
        outFile << "\nScorul dealerului: " << dealer.getScore() << endl;
        outFile << "Mana dealerului:" << endl;
        for (const auto& card : dealer.getHand()) {
            outFile << card.getCardName() << " de " << card.getSuit() << endl;
        }

        // Închide fișierul
        outFile.close();
        cout << "Progresul a fost salvat in progress.txt" << endl;
    }
    catch (const exception& e) {
        cerr << "Eroare: " << e.what() << endl;
    }
}


int main() {
    Game game;
    bool exitGame = false;
    while (!exitGame) {
        cout << "\n=== Meniu Principal ===" << endl;
        cout << "1. Joaca jocul" << endl;
        cout << "2. Salveaza progresul" << endl;
        cout << "3. Iesire" << endl;
        cout << "Alege o optiune: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            game.play();
            break;
        }
        case 2: {
            saveProgress(game.getPlayer(), game.getDealer());
            break;
        }
        case 3:
            exitGame = true;
            cout << "Iesire din joc. La revedere!" << endl;
            break;
        default:
            cout << "Optiune invalida. Te rog sa alegi din nou." << endl;
        }
    }

    return 0;
}
