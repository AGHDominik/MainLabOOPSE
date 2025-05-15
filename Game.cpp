#include "Game.h"

namespace GameEngine {
Game::Game(Hero* h, Monster* m) : hero(h), monster(m) {}

    void Game::play() {
        hero->attack(*monster);
        monster->attack(*hero);
        hero->heal();
        monster->roar();
    }

    void showCharacterInfo(Character* ch) {
        ch->describe();
    }

    namespace Battlefield {
        Arena::Arena() {
            cout << "Arena set in the Snow biome. Prepare for a battle!\n" << endl;
        }
    }
}