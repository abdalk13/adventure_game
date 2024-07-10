#include "world.h"
#include <iostream>

World::World() : currentRoomIndex(0), currentPlayer(nullptr) {}

void World::addRoom(const Room& room) {
    rooms.push_back(room);
}

void World::setCurrentRoom(int index) {
    if (index >= 0 && index < rooms.size()) {
        currentRoomIndex = index;
    }
}

Room* World::getCurrentRoom() const {
    if (currentRoomIndex >= 0 && currentRoomIndex < rooms.size()) {
        return const_cast<Room*>(&rooms[currentRoomIndex]);
    }
    return nullptr;
}

void World::setCurrentPlayer(Player* player) { 
    currentPlayer = player;
}

Player* World::getCurrentPlayer() const { 
    return currentPlayer;
}

void World::movePlayer(Player* player, int direction) {
    int newRoomIndex = currentRoomIndex + direction;
    if (newRoomIndex >= 0 && newRoomIndex < rooms.size()) {
        currentRoomIndex = newRoomIndex;
        std::cout << "Player moved to: " << rooms[currentRoomIndex].getDescription() << std::endl;
    } else {
        std::cout << "Cannot move in that direction." << std::endl;
    }
}

std::string World::getDescription() const {
    if (currentRoomIndex >= 0 && currentRoomIndex < rooms.size()) {
        return rooms[currentRoomIndex].getDescription();
    }
    return "No current room.";
}
