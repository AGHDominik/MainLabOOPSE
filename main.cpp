#include "Character.h"
#include "Enemy.h"
#include "Game.h"

using namespace GameEngine;

int main() {
    Battlefield::Arena arena;

    try {
        Hero* invalidHero = new Hero("Weakling", -20, 5, "Dagger");
        delete invalidHero;
    }
    catch (const exception& e) {
        cout << "Error creating hero: " << e.what() << endl;
    }

    try {
        Villager lowAttackVillager("Tim", 20, 0, "Dagger");
        lowAttackVillager.boostAttack();
    }
    catch (const exception& e) {
        cout << "Villager boost error: " << e.what() << endl;
    }

    try {
        Hero* averageHero = new Hero("John", 40, 10, "Stick");
        averageHero->equipItem("Heavy Axe");
        delete averageHero;
    }
    catch (const exception& e) {
        cout << "Equip error: " << e.what() << endl;
    }


    Hero* hero = new Hero("Bob", 50, 10, "Stick");
    FantasyWorld::HeroActivities FantasyHA;
    FantasyHA.speak();
    Monster* monster = new Monster("Goblin", 30, 5);
    FantasyWorld::EnemyActivities FantasyEA;
    FantasyEA.attack();

    Game game(hero, monster);
    game.play();

    showCharacterInfo(hero);
    Villager villager("Tom", 20, 0, "Hoe");
    showCharacterInfo(&villager);

    villager.talkTo("Bob");

    Character* c = new Hero("Alice", 60, 15, "Sword");
    SciFiWorld::HeroActivities SciFiHA;
    SciFiHA.speak();
    delete c;

    Enemy* e = new Monster("Orc", 40, 8);
    SciFiWorld::EnemyActivities SciFiEA;
    SciFiEA.attack();
    delete e;

    cout << "Total Enemies created: " << Enemy::getObjectCount() << endl;
    cout << "Default hero weapon: " << Hero::getDefaultWeapon() << endl;

    delete hero;
    delete monster;

    return 0;
}