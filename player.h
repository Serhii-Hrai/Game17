#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int IMax = 10;
const int WMax = 5;

class Player {
protected:
    string Name;
    float Energy;
    vector<string> Item;
    int xPos, yPos, zPos;

public:
    Player();
    Player(string Name, float Energy);
    virtual ~Player();

    virtual string getType();

    void inputData();
    void inputItems(int count = IMax);
    void showData();
    void saveData();
    void loadData();

    void removeItem(int pos);
    void insertItem(int pos, string bonus);

    void showItems();
    void clearItems();
    void saveItems();
    void loadItems();

    bool foundItem(string seek);
};

class Warrior : public Player {
protected:
    string Weapon[WMax];
    int Ammo[WMax];

public:
    Warrior();
    Warrior(string Name, float Energy);

    virtual string getType();

    void inputWeapons(int count = WMax);
    void showWeapons();
};