#include "Character.h"
#include "Enemy.h"

// Static member
int Hero::heroCount = 0;

Character::Character(string n, int hp, int ap, string w)
    : name(n), health(hp), attackPower(ap), weapon(w) {
    cout << name << " joined with " << health << " HP\n";
}

Character::~Character() {
    cout << "Character destructor called\n";
}

void Character::attack(Enemy& enemy) {
    cout << name << " attacks " << enemy.getName() << " with " << weapon << "!\n";
    enemy.getHit(attackPower);
}

void Character::getHit(int damage) {
    health -= damage;
    cout << name << " takes " << damage << " damage. Remaining HP: " << health << "\n";
    notifyObservers();
}

string Character::getName() const {
    return name;
}

// Hero
Hero::Hero(string n, int hp, int ap, string w) : Character(n, hp, ap, w) {
    if (hp < 0) //Exception of a propertie below zero
    {
        throw invalid_argument("Hero cannot have negative health!\n");
    }
    heroCount++;
    cout << name << " the Hero is ready!\n";
}

Hero::~Hero() {
    cout << "Hero destructor called\n";
}

void Hero::heal() {
    health += 10;
    cout << name << " heals and now has " << health << " HP!\n";
}

void Hero::describe() {
    cout << name << " is a brave hero with a " << weapon << ".\n";
}

void Hero::equipItem(const string& item) //Method performing an action
{
    if (item == "Heavy Axe" && attackPower < 15)
    {
        throw logic_error("Not strong enough to equip the Heavy Axe!\n");
    }
    cout << name << " equiped " << item << ".\n";
}

string Hero::getDefaultWeapon() {
    return "Sword";
}

// Villager
Villager::Villager(string n, int hp, int ap, string w) : Character(n, hp, ap, w) {
    cout << name << " the Villager joins the story.\n";
}

Villager::~Villager() {
    cout << "Villager destructor called\n";
}

void Villager::describe() {
    cout << name << " is a peaceful villager with " << weapon << ".\n";
}

void Villager::talkTo(const string& other) {
    cout << name << " talks to " << other << ".\n";
}
void Villager::boostAttack() { //Method throwing an exception
    if (attackPower < 1)
    {
        throw runtime_error("Attack power too low to boost! Must be at least 1.\n");
    }
    attackPower += 5;
    cout << name << " boosted attack power to " << attackPower << "!\n";
}
void FantasyWorld::HeroActivities::speak() {
    cout << "Fantasy Hero: For glory!" << endl;
}
void FantasyWorld::EnemyActivities::attack() {
    cout << "Fantasy Enemy: Swing a sword!" << endl;
}
void SciFiWorld::HeroActivities::speak() {
    cout << "Fantasy Hero: Shields up!" << endl;
}
void SciFiWorld::EnemyActivities::attack() {
    cout << "Fantasy Hero: Fire the lasers!" << endl;
}

void HealthLogger::update() {
    cout << "[Observer] " << character ->getName() << "Health changed!\n";
}

void Character::addObserver(HealthObserver* observer) {
    observers.push_back(observer);
}
void Character::removeObserver(HealthObserver* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}
void Character::notifyObservers() {
    for (HealthObserver* observer : observers)
    {
        observer->update();
    }
}
