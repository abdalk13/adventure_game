// room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <algorithm> 
#include "item.h"

class Room {
public:
    Room(const std::string& description);

    void addItem(const Item& item);
    void removeItem(const Item& item);
    void listItems() const;

    const std::vector<Item>& getItems() const;

    Item* getItem(const std::string& itemName);

    std::string getDescription() const;

private:
    std::string description;
    std::vector<Item> items;
};

#endif 
