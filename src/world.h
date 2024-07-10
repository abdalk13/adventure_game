#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "room.h"
#include "player.h"

class World {
public:
    World();

    void addRoom(const Room& room);
    void setCurrentRoom(int index);
    Room* getCurrentRoom() const;

    void setCurrentPlayer(Player* player);
    Player* getCurrentPlayer() const;

    void movePlayer(Player* player, int direction);
    std::string getDescription() const;

private:
    std::vector<Room> rooms;
    int currentRoomIndex;
    Player* currentPlayer;
};

#endif 
