#include "Creature.h"

void printMenu( Creature& player,  Creature& opponent) {
    cout << "Menu d'attaque :\n";
    cout << "1. " << player.getName() << " attaque " << opponent.getName() << "\n";
    cout << "2. Quitter\n";
}


int main() 
{
	Creature creature1("Gobelin", 50, 1, false, false, false,true);
	Creature creature2("Bear", 100, 1, false, false, false, true);
    Creature creature3("Bat", 100, 1, true, false, false, true);
    Creature creature4("BloodySlime", 100, 1, false, true, false, true);
    Creature creature5("Golem", 100, 1, false, false, true, true);


	//cout << "Initial Information:\n";
	//cout << creature1 << endl;
	//cout << creature2 << endl;


    Creature* playerCreature;
    Creature* opponentCreature;

    // Demandez au joueur de choisir ses créatures
    cout << "Choose your monster (1-5) :" << endl;
    int playerChoice;
    cin >> playerChoice;

    switch (playerChoice) {
    case 1:
        playerCreature = &creature1;
        break;
    case 2:
        playerCreature = &creature2;
        break;
    case 3:
        playerCreature = &creature3;
        break;
    case 4:
        playerCreature = &creature4;
        break;
    case 5:
        playerCreature = &creature5;
        break;
    default:
        cout << "Choice out of bound. Closing the programme" << endl;
        return 1;
    }

    // Demandez au joueur de choisir l'adversaire
    cout << "Choose your opponent " << playerCreature->getName() << " (1-5) :\n";
    int opponentChoice;
    cin >> opponentChoice;

    switch (opponentChoice) {
    case 1:
        opponentCreature = &creature1;
        break;
    case 2:
        opponentCreature = &creature2;
        break;
    case 3:
        opponentCreature = &creature3;
        break;
    case 4:
        opponentCreature = &creature4;
        break;
    case 5:
        opponentCreature = &creature5;
        break;
    default:
        cout << "Choice out of bound. Closing the programme.\n";
        return 1;
    }

    // Boucle de combat
    while (playerCreature->isAlive() && opponentCreature->isAlive()) {
        printMenu(*playerCreature, *opponentCreature);

        int attackChoice;
        cin >> attackChoice;

        switch (attackChoice) {
        case 1:
            playerCreature->attack(*opponentCreature);
            break;
        case 2:
            cout << "Exit.\n";
            return 0;
        default:
            cout << "Choice out of bound.\n";
        }
    }

    // Affiche le résultat du combat
    cout << creature1.getHealthPoint();
    if (!playerCreature->isAlive()) {
        cout << "Your monster is dead.\n";
    }
    else {
        cout << "You win with a " << opponentCreature->getName() << ".\n";
    }

    return 0;
}
