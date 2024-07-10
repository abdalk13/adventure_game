#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "item.h"

class Player {
public:
    Player(const std::string& name);

    void addItemToInventory(const Item& item);
    void removeItemFromInventory(const Item& item);
    void listInventory() const;
    void displayInventory();
    double getTotalWeight() const;
    Item* getItem(const std::string& itemName);

private:
    std::string name;
    std::vector<Item> inventory;
};

#endif 
