#include<iostream>

class GameEngineMaker
{
    public:
        virtual void physicsMachine()=0;
        virtual void lightingEngine()=0;
};

class Unity : public GameEngineMaker
{
    public:
        void physicsMachine() { std::cout << "Unity's way of simulating physics\n"; }
        void lightingEngine() { std::cout << "Unity's lighting engine\n"; }
};

class Unreal : public GameEngineMaker
{
    public:
        void physicsMachine() { std::cout << "Unreal Engine's physics simulation program\n"; }
        void lightingEngine() { std::cout << "Unreal Engine's lighting engine\n"; }
};

int main() 
{
    GameEngineMaker* one = new Unity();
    one->physicsMachine();

    GameEngineMaker* two = new Unreal();
    two->physicsMachine();
    two->lightingEngine();

    // developer unity & unreal engine tidak perlu tahu
    // bagaimana kompleksitas dari physics engine.

    return 0;
}