#include<iostream>
#include<list>

//polymorhpism : multiple forms

class Gudang
{
    public:
        std::string cabang;
        int jumlah;
        std::list<std::string> kode_barang;
    
    protected:
        std::string pemilik;
        int kualitasBarang=0;
    
    public:
        Gudang(std::string cabang, std::string pemilik)
        {
            cabang = cabang;
            pemilik = pemilik;
            jumlah = 0;
        }

        void printInfo()
        {
            std::cout << "Cabang Gudang: " << cabang << std::endl;
            std::cout << "Pemilik: " << pemilik << std::endl;
            std::cout << "Jumlah Barang: " << jumlah << std::endl;
            
            for(std::string kode : kode_barang)
            {
                std::cout << "Kode : " << kode << std::endl;
            }
        }

        void tambahBarang()
        {
            jumlah++;
        }

        void kurangBarang()
        {
            jumlah--;
        }

        void tambahKodeBarang(std::string kode)
        {
            kode_barang.push_back(kode);
        }

        void qualityAnalysis()
        {
            if(kualitasBarang > 5) { std::cout<<"Barang bagus!\n";}
            else { std::cout <<"Barang jelek!\n";}
        }
        
};

class GudangLaptop : public Gudang
{
    public:
        GudangLaptop(std::string cabang, std::string pemilik) : Gudang(cabang, pemilik) {}

        void research()
        {
            std::cout << "Riset dan Pengembangan Laptop" << std::endl;
            kualitasBarang++;
        }
};  

class GudangMobil : public Gudang
{
    public:
        GudangMobil(std::string cabang, std::string pemilik) : Gudang(cabang, pemilik) {}

        void research()
        {
            std::cout << "Riset dan Pengembangan Mobil" << std::endl;
            kualitasBarang++; 
        }
};  

int main()
{
    GudangLaptop Asus("Jakarta", "Reza");
    GudangMobil Toyota("Bandung", "Bundang");

    // intinya disini sih polymorph itu, nama sama, beda tempat.
    Asus.research();
    Toyota.research();

    // pointer base class bisa point ke derived class.
    Gudang* pointerSatu = &Asus;
    Gudang* pointerDua = &Toyota;

    pointerSatu->qualityAnalysis();
    pointerDua->qualityAnalysis();
}