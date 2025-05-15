#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Enemy.h"

namespace GameEngine {
    void showCharacterInfo(Character* ch);

    class Game {
    private:
        Hero* hero;
        Monster* monster;

    public:
        Game(Hero* h, Monster* m);
        void play();
    };

    namespace Battlefield {
        class Arena {
        public:
            Arena();
        };
    }
}
#endif
