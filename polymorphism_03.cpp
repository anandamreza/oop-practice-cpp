#include<iostream>

class Manusia
{
    public:
        std::string nama;  

        Manusia(std::string nama) : nama(nama) {};

        virtual void print() { std::cout << "Nama : " << nama << std::endl; }
};

class Dokter : public Manusia
{
    public:
        std::string kerja;

        Dokter(std::string nama, std::string kerja) : kerja(kerja), Manusia(nama) {};

        void print() { std::cout << nama << " bekerja sebagai " << kerja << ".\n"; }
};

int main()
{
    Manusia* orang[] =
    {
        new Manusia("Yongki"),
        new Manusia("Andi"),
        new Manusia("Budi"),
        new Dokter("Jacob", "Dokter Anak"),
        new Dokter("Endah", "Dokter Gigi"),
        new Dokter("Roy", "Dokter Sunat")
    };

    for(int i = 0; i < 6; i++) { orang[i]->print(); }
    for(int i = 0; i < 6; i++) { delete orang[i]; }

    return 0;
}