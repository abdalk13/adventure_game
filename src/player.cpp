#include "player.h"
#include <ncurses/ncurses.h>
#include <algorithm>
#include <iostream>

Player::Player(const std::string& name) : name(name) {}

void Player::addItemToInventory(const Item& item) {
    inventory.push_back(item);
}

void Player::removeItemFromInventory(const Item& item) {
    inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
}

void Player::listInventory() const {
    for (const auto& item : inventory) {
        std::cout << "- " << item.getName() << std::endl;
    }
}

void Player::displayInventory() {
    clear();
    printw("Inventory:\n");
    for (const auto& item : inventory) {
        printw("- %s\n", item.getName().c_str());
    }
    refresh();
}

Item* Player::getItem(const std::string& itemName) {
    for (auto& item : inventory) {
        if (item.getName() == itemName) {
            return &item;
        }
    }
    return nullptr;
}

double Player::getTotalWeight() const {
    double totalWeight = 0;
    for (const auto& item : inventory) {
        totalWeight += item.getWeight();
    }
    return totalWeight;
}
