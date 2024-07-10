// game.cpp
#include "game.h"
#include <iostream>
#include "room.h"
#include<ncurses/ncurses.h>

Game::Game() {
    player = new Player("Hero");
    world = new World();

    Room room1("You are in a dimly lit cave.");
    room1.addItem(Item("Sword", "A sharp blade", 5.0));
    room1.addItem(Item("Shield", "A sturdy shield", 7.5));
    room1.addItem(Item("Potion", "A healing potion", 1.0));
    room1.addItem(Item("Helmet", "A sturdy helmet", 3.0));
    room1.addItem(Item("Boots", "A pair of leather boots", 2.0));

    Room room2("You are in a forest clearing.");
    room2.addItem(Item("Bow", "A long bow", 4.0));
    room2.addItem(Item("Arrow", "A quiver of arrows", 1.5));
    room2.addItem(Item("Dagger", "A sharp dagger", 2.0));
    room2.addItem(Item("Ring", "A golden ring", 0.1));
    room2.addItem(Item("Lantern", "A bright lantern", 2.5));

    world->addRoom(room1);
    world->addRoom(room2);

    world->setCurrentRoom(0);
    world->setCurrentPlayer(player); 
}

Game::~Game() {
    delete player;
    delete world;
}

void Game::start() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    printw("Welcome to the Text Adventure Game!\n");
    printw("Press 'q' to quit.\n");
    printw("Press 'w' to move forward.\n");
    printw("Press 's' to move backward.\n");
    printw("Press 'i' to view inventory.\n");
    printw("Press 'l' to list items in the room.\n");
    printw("Press 'p' to pick up an item.\n");
    printw("Press 'd' to drop an item.\n");
    refresh();

    char ch;
    while ((ch = getch()) != 'q') {
        processInput(ch);
    }

    endwin();
}

void Game::processInput(char input) {
    clear(); 
    Room* currentRoom = world->getCurrentRoom();
    switch (input) {
        case 'w':
            world->movePlayer(player, 1);
            break;
        case 's':
            world->movePlayer(player, -1);
            break;
        case 'i':
            player->displayInventory();
            refresh(); 
            return; 
        case 'l':
            printw("Items in the room:\n");
            if (currentRoom != nullptr) {
                for (const auto& item : currentRoom->getItems()) {
                    printw("- %s\n", item.getName().c_str());
                }
            } else {
                printw("No room available.\n");
            }
            refresh(); 
            return; 
        case 'p': {
            printw("Enter the name of the item to pick up: ");
            refresh(); 
            char itemName[50];
            getstr(itemName);
            Item* item = currentRoom->getItem(itemName);
            if (item) {
                player->addItemToInventory(*item);
                currentRoom->removeItem(*item);
                printw("You picked up %s.\n", item->getName().c_str());
            } else {
                printw("Item not found.\n");
            }
            refresh(); 
            return; 
        }
        case 'd': {
            printw("Enter the name of the item to drop: ");
            refresh(); 
            char itemName[50];
            getstr(itemName);
            Item* item = player->getItem(itemName);
            if (item) {
                player->removeItemFromInventory(*item);
                currentRoom->addItem(*item);
                printw("You dropped %s.\n", item->getName().c_str());
            } else {
                printw("Item not found.\n");
            }
            refresh(); 
            return;
        }
        default:
            printw("Invalid input. Use 'w' to move forward, 's' to move backward, 'i' to view inventory, 'l' to list items in the room, 'p' to pick up an item, 'd' to drop an item.\n");
            break;
    }
    printw(world->getDescription().c_str());
    refresh();
}
