#include <string>
#include <iostream>
#include "player.h"
#include <fstream>
using namespace std;

Player::Player() : Name(""), Energy(0.0f), xPos(0), yPos(0), zPos(0) {}

Player::Player(string Name, float Energy) : Name(Name), Energy(Energy), xPos(0), yPos(0), zPos(0) {}

Player::~Player() {
    // No dynamic memory to free, but definition required
}

string Player::getType() {
    return "Player";
}

void Player::inputData() {
	cout << "Wie ist dein Name? "; cin >> Name;
	cout << "Deine Energie (max 100)? "; cin >> Energy;
}
void Player::inputItems(int count) {
    string thing;

    for (int i = 0; i < count; ++i) {
        cout << "Nenne den " << i + 1 << ". Gegenstand: ";
        cin >> thing;

        if (thing == "#")
            break;

        Item.push_back(thing);
    }
}
void Player::showData() {
	cout << "Name: " << Name << endl;
	cout << "Typ: " << getType() << endl;
	cout << "Energie: " << Energy << " %.\n";
}
void Player::showItems() {
    for (const auto& thing : Item) {
        cout << thing << " ";
    }
    cout << "\n";
}
Warrior::Warrior() : Player() {
    for (int i = 0; i < WMax; ++i) {
        Weapon[i] = "";
        Ammo[i] = 0;
    }
}

Warrior::Warrior(string Name, float Energy) : Player(Name, Energy) {
    for (int i = 0; i < WMax; ++i) {
        Weapon[i] = "";
        Ammo[i] = 0;
    }
}

string Warrior::getType() {
    return "Warrior";
}

void Warrior::inputWeapons(int count) {
    for (int i = 0; i < count && i < WMax; ++i) {
        cout << "Enter weapon " << i + 1 << ": ";
        cin >> Weapon[i];
        cout << "Enter ammo for " << Weapon[i] << ": ";
        cin >> Ammo[i];
    }
}

void Warrior::showWeapons() {
    cout << "Weapons:\n";
    for (int i = 0; i < WMax; ++i) {
        if (!Weapon[i].empty()) {
            cout << Weapon[i] << " (Ammo: " << Ammo[i] << ")\n";
        }
    }
}
bool Player::foundItem(string seek) {
    for (const auto& thing : Item) {
        if (thing == seek)
            return true;
    }

    return false;
}
void Player::removeItem(int pos) {
    if (pos >= 0 && pos < Item.size()) {
        Item.erase(Item.begin() + pos);
    }
}
void Player::insertItem(int pos, string bonus) {
    if (pos >= 0 && pos <= Item.size()) {
        Item.insert(Item.begin() + pos, bonus);
    }
}
void Player::saveData() {
    ofstream GameFile("GameFile.dat");
    GameFile << Name << "\n";
    GameFile << Energy << "\n";
}
void Player::loadData() {
    ifstream GameFile("GameFile.dat");
    GameFile >> Name;
    GameFile >> Energy;
}
void Player::clearItems() {
    Item.clear();
}
void Player::saveItems() {
    ofstream GameFile("GameFile.inv");

    for (const auto& thing : Item)
        GameFile << thing << "\n";
}
void Player::loadItems() {
    ifstream GameFile("GameFile.inv");

    string thing;

    while (GameFile >> thing)
        Item.push_back(thing);
}