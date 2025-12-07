#include<iostream>

class Person
{
    private:
        std::string private_name;
    
    public:
        void setName(std::string name) //setter method
        {
            this->private_name = name;
        }

        std::string getName() //getter method
        {
            return private_name;
        }
};

int main()
{
    Person one;
    one.setName("Diablo");
    std::cout << one.getName();

    return 0;
}