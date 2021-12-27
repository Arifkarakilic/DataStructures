#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include <iostream>
#include "Dugum.hpp"
#include "nokta.hpp"

using namespace std;

class Kuyruk{
   public:
    Kuyruk();
    ~Kuyruk();
    Dugum* enKucukDugum();
    void ekle (nokta veri);
    void uzaklik();
    void sil(Dugum* dugum);
    friend ostream& operator<<(ostream& os, Kuyruk* kuyruk);
    Dugum* ilk;
    Dugum* son;
    int count;
    int uzunluk();


};

#endif