// room.cpp
#include "room.h"
#include <iostream>

Room::Room(const std::string& description) : description(description) {}

void Room::addItem(const Item& item) {
    items.push_back(item);
}

void Room::removeItem(const Item& item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

void Room::listItems() const {
    if (items.empty()) {
        std::cout << "The room is empty." << std::endl;
    } else {
        for (const auto& item : items) {
            std::cout << "- " << item.getName() << ": " << item.getDescription() << " (" << item.getWeight() << " kg)" << std::endl;
        }
    }
}

Item* Room::getItem(const std::string& itemName) {
    for (auto& item : items) {
        if (item.getName() == itemName) {
            return &item;
        }
    }
    return nullptr;
}

const std::vector<Item>& Room::getItems() const { 
    return items;
}

std::string Room::getDescription() const {
    return description;
}
