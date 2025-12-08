#include<iostream>

class Square
{
    private:
        int panjang;
    
    public:
        Square(int panjang) : panjang(panjang) {}
        Square() = default;

        void set_panjang(int panjang) { this->panjang=panjang;}
        int get_panjang() { return panjang; }

        void print() { std::cout << "Square!" << '\n'; }
};
 
class Rectangle : public Square
{
    private:
        int lebar;
    
    public:
        Rectangle(int panjang, int lebar) : Square(panjang), lebar(lebar) {}
        Rectangle() = default;

        void set_lebar(int lebar) { this->lebar=lebar;}
        int get_lebar() {return lebar;}

        void print() { std::cout << "Rectangle!" << '\n'; }
};

void foo(Square& s) // polymorphic function
{
    s.print();
}

int main()
{
    Square s(5);
    Rectangle r(10, 5);

    foo(r);

    return 0;

}