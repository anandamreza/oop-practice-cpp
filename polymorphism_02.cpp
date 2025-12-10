#include<iostream>

class Vehicle
{
    public:
    // pake virtual -> bindingsnya pas runtime. (override)
    // tidak pake virtual -> bindingnya pas compile time. (redefine)
    virtual void Go() { std::cout<<"The vehicle is moving!"<<std::endl; }
};

class Car : public Vehicle
{
    void Go() { std::cout<<"The car is moving!"<<std::endl; }
};
class Boat : public Vehicle 
{
    void Go() { std::cout<<"The boat is moving!"<<std::endl; }
};
class Plane : public Vehicle 
{
    void Go() { std::cout<<"The plane is flying!"<<std::endl; }
};

int main()
{
    Car car1;
    Boat boat1;
    Plane plane1;

    Vehicle* vehicles[] = {&car1, &boat1, &plane1};

    for(Vehicle* v : vehicles)
    {
        // masing-masing pake fungsi go yang sudah di-override.
        // disini polymorhismnya, Go() punya banyak versi.
        v->Go();
    }

    return 0;
}