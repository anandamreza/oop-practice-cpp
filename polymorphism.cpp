#include<iostream>

class Square
{
    private:
        int panjang;
    
    public:
        Square(int panjang) : panjang(panjang) {}

        virtual ~Square() {};

        void set_panjang(int panjang) { this->panjang=panjang;}
        int get_panjang() { return panjang; }

        // karena virtual, tipe bindingsnya berubah dari static ke dinamic.
        virtual void print() { std::cout << "Square!" << '\n'; }
};
 
class Rectangle : public Square
{
    private:
        int lebar;
    
    public:
        Rectangle(int panjang, int lebar) : Square(panjang), lebar(lebar) {}

        virtual ~Rectangle() {};

        void set_lebar(int lebar) { this->lebar=lebar;}
        int get_lebar() {return lebar;}

        void print() { std::cout << "Rectangle!" << '\n'; }
};

class Goo : public Square
{
    public:
        Square::Square;
        void print() { std::cout << "Goo!" << '\n'; }

        virtual ~Goo() {};
};

void foo(Square& s) // polymorphic function
{
    std::cout << s.get_panjang();
}

void boo(Square& s) // polymorphism kudu pake reference atau pointers.
{
    s.print();
}

int main()
{
    Square s(5);
    Rectangle r(10, 5);

    // bisa karena rectangle adalah square.
    foo(r);

    boo(r);


    Square* sptr = &r;
    sptr->print();

    // works karena square adalah square, rectangle adalah square, dan goo adalah square!
    Square* squares[] = { new Square(3), new Rectangle(4,5), new Goo(3) };

    for(Square* sq : squares) { sq->print(); }
    for(Square* sq : squares) { delete sq; }

    return 0;

}