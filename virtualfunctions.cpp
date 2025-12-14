#include<iostream>

class Gun
{
    public:
        virtual void shoot() = 0; // pure virtual function
};

class RocketLauncher : public Gun
{
    public:
        void shoot() { std::cout << "Launching a rocket projectile! boom!\n";}
};

class Thompson : public Gun
{
    public:
        void shoot() { std::cout << "Say hello to my little friend! brrrrrrrrrrrr!\n";}
};

int main()
{
    Gun* G = new RocketLauncher();
    //G->shoot();

    Gun* T = new Thompson();
    //T->shoot();

    Gun* arsenal[] = {G, T}; 
    for(int i = 0; i < 2; i++) // polymorphic behavior
        arsenal[i]->shoot();

    return 0;
}