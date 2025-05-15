#include "Enemy.h"
#include "Character.h"

// Static member
int Enemy::objectCount = 0;

// Enemy
Enemy::Enemy(string n, int hp, int ap)
    : name(n), health(hp), attackPower(ap) {
    objectCount++;
    cout << name << " enemy appeared!\n";
}

Enemy::~Enemy() {
    cout << "Enemy destructor called\n";
}

int Enemy::getObjectCount() {
    return objectCount;
}

void Enemy::describe() {
    cout << name << " is a normal enemy.\n";
}

void Enemy::attack(Character& character) {
    cout << name << " attacks!\n";
    character.getHit(attackPower);
}

void Enemy::getHit(int damage) {
    health -= damage;
    cout << name << " takes " << damage << " damage. Remaining HP: " << health << "\n";
}

string Enemy::getName() const {
    return name;
}

// Monster
Monster::Monster(string n, int hp, int ap) : Enemy(n, hp, ap) {
    cout << name << " the Monster is born!\n";
}

Monster::~Monster() {
    cout << "Monster destructor called\n";
}

void Monster::roar() {
    cout << name << " roars fiercely!\n";
}

void Monster::describe() {
    cout << name << " is a scary monster with " << health << " HP.\n";
}

// Robot
Robot::Robot(string n, int hp, int ap) : Enemy(n, hp, ap) {
    cout << name << " the Robot activates!\n";
}

Robot::~Robot() {
    cout << "Robot destructor called\n";
}

void Robot::describe() {
    cout << name << " is a shiny robot with " << health << " HP.\n";
}
