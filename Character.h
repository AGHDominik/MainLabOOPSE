#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
using namespace std;

class Enemy;

class Character {
protected:
    string name;
    int health;
    int attackPower;
    string weapon;

public:
    Character(string n, int hp, int ap, string w);
    virtual ~Character();
    virtual void describe() = 0;
    void attack(Enemy& enemy);
    void getHit(int damage);
    string getName() const;
};

class Hero : public Character {
public:
    static int heroCount;
    Hero(string n, int hp, int ap, string w);
    ~Hero();
    void heal();
    void describe() override;
    static string getDefaultWeapon();
    void equipItem(const string& item); //
};

class Villager : public Character {
public:
    Villager(string n, int hp, int ap, string w);
    ~Villager();
    void describe() override;
    void talkTo(const string& other);
    void boostAttack(); //
};

namespace FantasyWorld {
    class HeroActivities {
    public:
        void speak();
    };
    class EnemyActivities {
    public:
        void attack();
    };
}
namespace SciFiWorld {
    class HeroActivities {
    public:
        void speak();
    };
    class EnemyActivities {
    public:
        void attack();
    };
}

#endif
