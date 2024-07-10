// game.h
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "world.h"

class Game {
public:
    Game();
    ~Game();
    void start();

private:
    Player* player;
    World* world;
    void processInput(char input);
};

#endif 
