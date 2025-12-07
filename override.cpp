#include<iostream>

class Npc
{
    protected:
        std::string name;
        int health;
        int mana;
        bool hostile;
    
    public:
        Npc(std::string name, int health, int mana, bool hostile) : name(name), 
        health(health), mana(mana), hostile(hostile) {}

        Npc() = default;

        std::string getName() {return name;}
        int getHealth() {return health;}
        int getMana() {return mana;}
        bool isHostile() {return hostile;}

        void setName(std::string name) {this->name = name;}
        void setHealth(int health) {this->health = health;}
        void setMana(int mana) {this->mana = mana;}
        void setHostile(bool hostile) {this->hostile = hostile;}

        virtual void printInfo()
        {
            std::cout<<"Name : " << name << '\n';
            std::cout<<"Health : " << health << '\n';
            std::cout<<"Mana : " << mana << '\n';
            std::cout<<"Hostile : " << (isHostile() ? "Yes" : "No") << '\n';
        }
};

class Enemy : public Npc
{
    private:
        std::string weapon;
        std::string armor;
        std::string loot;
    
    public:
        Enemy(std::string name, int health, int mana, bool hostile,
        std::string weapon, std::string armor, std::string loot) : Npc(name, health, mana, hostile), 
        weapon(weapon), armor(armor), loot(loot) {}

        Enemy() = default;

        void setWeapon(std::string weapon) {this->weapon = weapon;}
        void setArmor(std::string armor) {this->armor = armor;}
        void setLoot(std::string loot) {this->loot = loot;}

        std::string getWeapon() {return weapon;}
        std::string getArmor() {return armor;}
        std::string getLoot() {return loot;}

        void printInfo() override
        {
            std::cout << "Name: " << name << '\n';
            std::cout << "Health: " << health << '\n';
            std::cout << "Mana: " << mana << '\n';
            std::cout << "Hostile: " << (hostile ? "Yes" : "No") << '\n';

            std::cout << "Weapon: " << weapon << '\n';
            std::cout << "Armor: " << armor << '\n';
            std::cout << "Loot: " << loot << '\n';
        }
};

int main()
{
    Enemy demons("Diablo", 1000, 500, true, 
        "Hellflame Sword", "Dragonspike Armor", "Root of The Demonic Tree");

    demons.setName("Netheron");
    
    demons.printInfo();
    
    return 0;
}