#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
using namespace std;

class Character;

class Enemy {
protected:
    string name;
    int health;
    int attackPower;

public:
    static int objectCount;
    Enemy(string n, int hp, int ap);
    virtual ~Enemy();
    static int getObjectCount();
    virtual void describe();
    void attack(Character& character);
    void getHit(int damage);
    string getName() const;
};

class Monster : public Enemy {
public:
    Monster(string n, int hp, int ap);
    ~Monster();
    void roar();
    void describe() override;
};

class Robot : public Enemy {
public:
    Robot(string n, int hp, int ap);
    ~Robot();
    void describe() override;
};

#endif
