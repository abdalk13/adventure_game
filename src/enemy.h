#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health);
    std::string getName() const;
    int getHealth() const;
    void takeDamage(int damage);

private:
    std::string name;
    int health;
};

#endif // ENEMY_H
