#include <iostream>
#include <string>
using namespace std;

class Enemy;

class Character {
protected:
    string name;
    int health;
    int attackPower;
    string weapon;

public:
    Character(string n, int hp, int ap, string w) {
        name = n;
        health = hp;
        attackPower = ap;
        weapon = w;
        cout << name << " joined with " << health << " HP\n";
    }

    virtual ~Character() {
        cout << "Character destructor called\n";
    }

    virtual void describe() = 0;

    void attack(Enemy& enemy);
    void getHit(int damage) {
        health -= damage;
        cout << name << " takes " << damage << " damage. Remaining HP: " << health << "\n";
    }

    string getName() const {
        return name;
    }
};

class Enemy {
protected:
    string name;
    int health;
    int attackPower;

public:
    static int objectCount;

    Enemy(string n, int hp, int ap) {
        name = n;
        health = hp;
        attackPower = ap;
        objectCount++;
        cout << name << " enemy appeared!\n";
    }

    ~Enemy() {
        cout << "Enemy destructor called\n";
    }

    static int getObjectCount() {
        return objectCount; //static member
    }

    virtual void describe() {
        cout << name << " is a normal enemy.\n";
    }

    void attack(Character& character) {
        cout << name << " attacks!\n";
        character.getHit(attackPower);
    }

    void getHit(int damage) {
        health -= damage;
        cout << name << " takes " << damage << " damage. Remaining HP: " << health << "\n";
    }

    string getName() const {
        return name; //const marker
    }
};

int Enemy::objectCount = 0;

void Character::attack(Enemy& enemy) {
    cout << name << " attacks " << enemy.getName() << " with " << weapon << "!\n";
    enemy.getHit(attackPower);
}

class Hero : public Character {
public:
    static int heroCount;

    Hero(string n, int hp, int ap, string w) : Character(n, hp, ap, w) {
        heroCount++;
        cout << name << " the Hero is ready!\n";
    }

    ~Hero() {
        cout << "Hero destructor called\n";
    }

    void heal() {
        health += 10;
        cout << name << " heals and now has " << health << " HP!\n";
    }

    void describe() override {
        cout << name << " is a brave hero with a " << weapon << ".\n";
    }

    static string getDefaultWeapon() {
        return "Sword"; // static function
    }
};

int Hero::heroCount = 0;

class Villager : public Character {
public:
    Villager(string n, int hp, int ap, string w) : Character(n, hp, ap, w) {
        cout << name << " the Villager joins the story.\n";
    }

    ~Villager() {
        cout << "Villager destructor called\n";
    }

    void describe() override {
        cout << name << " is a peaceful villager with " << weapon << ".\n";
    }

    void talkTo(const string& other) {
        cout << name << " talks to " << other << ".\n"; //const argument
    }
};

class Monster : public Enemy {
public:
    Monster(string n, int hp, int ap) : Enemy(n, hp, ap) {
        cout << name << " the Monster is born!\n";
    }

    ~Monster() {
        cout << "Monster destructor called\n";
    }

    void roar() {
        cout << name << " roars fiercely!\n";
    }

    void describe() override {
        cout << name << " is a scary monster with " << health << " HP.\n";
    }
};

class Robot : public Enemy {
public:
    Robot(string n, int hp, int ap) : Enemy(n, hp, ap) {
        cout << name << " the Robot activates!\n";
    }

    ~Robot() {
        cout << "Robot destructor called\n";
    }

    void describe() override {
        cout << name << " is a shiny robot with " << health << " HP.\n";
    }
};

void showCharacterInfo(Character* ch) {
    ch->describe();
}

class Game {
private:
    Hero* hero;
    Monster* monster;

public:
    Game(Hero* h, Monster* m) {
        hero = h;
        monster = m;
    }

    void play() {
        hero->attack(*monster);
        monster->attack(*hero);
        hero->heal();
        monster->roar();
    }
};

int main() {
    Hero* hero = new Hero("Bob", 50, 10, "Stick");
    Monster* monster = new Monster("Goblin", 30, 5);

    Game game(hero, monster);
    game.play();

    showCharacterInfo(hero);
    Villager villager("Tom", 20, 0, "Hoe");
    showCharacterInfo(&villager);

    villager.talkTo("Bob");

    Character* c = new Hero("Alice", 60, 15, "Sword");
    delete c;

    Enemy* e = new Monster("Orc", 40, 8);
    delete e;

    cout << "Total Enemies created: " << Enemy::getObjectCount() << endl;
    cout << "Default hero weapon: " << Hero::getDefaultWeapon() << endl;

    delete hero;
    delete monster;

    return 0;
}
