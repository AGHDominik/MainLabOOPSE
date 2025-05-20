#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Enemy;

class HealthObserver {
public:
    virtual void healthChanged() = 0;
};

class Subject {
public:
    virtual void addObserver(HealthObserver* observer) = 0;
    virtual void removeObserver(HealthObserver* observer) = 0;
    virtual void notifyObservers() = 0;
};

class Character : public Subject {
protected:
    string name;
    int health;
    int attackPower;

    string weapon;

private:
    vector<HealthObserver*> observers;

public:
    Character(string n, int hp, int ap, string w);
    virtual ~Character();
    virtual void describe() = 0;

    void attack(Enemy& enemy);
    void getHit(int damage);
    string getName() const;
    void addObserver(HealthObserver* observer) override;
    void removeObserver(HealthObserver* observer) override;
    void notifyObservers() override;
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

class HealthLogger : public HealthObserver {
private:
    Character* character;
public: 
    HealthLogger(Character* character);
    void update() override;
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
