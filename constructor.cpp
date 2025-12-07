#include<iostream>

class Car
{
    private:
        std::string name;
        int year;
    
    public:
        //Car(std::string carName, int carYear) : name(carName), year(carYear) {}

        Car(std::string name, int year)
        {
            this->name = name;
            this->year = year;
        }

        Car() = default; // Default constructor

        std::string getOutput()
        {
            return name + " " + std::to_string(year);
        }
};

int main()
{
    Car mercedes("Mercedes", 2025);
    std::cout << mercedes.getOutput();

    Car lamborghini;

    return 0;
}