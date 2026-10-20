#include <string>
#include <iostream>
#include "../player.h"
using namespace std;

int main()
{
    Player *pPlayer = nullptr;
    int items;

    pPlayer = new Player;
    pPlayer->inputItems(); cout << "\n";
    cout << "Dein Inventar: ";
    pPlayer->showItems(); cout << "\n";

    cout << "Inventar wird gespeichert...\n";
    pPlayer->saveItems();

    pPlayer->clearItems();
    cout << "Inventar ist leer.\n";
    pPlayer->showItems();

    cout << "Inventar wird geladen...\n";
    pPlayer->loadItems();

    cout << "Dein Inventar: ";
    pPlayer->showItems(); cout << "\n";
}