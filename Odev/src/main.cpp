
/**
* @file main.cpp
* @description dosya okuma islemini ve fonksiyonlari calistiran kod
* @course 1. ogretim b grubu
* @assignment 1
* @date 4/11/2021
* @author Suleyman Arif Karakilic suleyman.karakilic@ogr.sakarya.edu.tr
**/
#include <iostream>
#include <fstream>
#include <locale.h>
#include "Dugum.hpp"
#include "Bagliliste.hpp"
#include "Windows.h"


int main(){
    SetConsoleOutputCP(65001);
    Bagliliste* liste = new Bagliliste();
    ifstream inVeri ("./doc/Veri.txt");
    string tempVeri,veri;
    int sira;
    int i;
    while(!inVeri.eof())
    {
        getline(inVeri, veri, '(');
        switch(tolower(veri[0]))
        {
            case 's':
                getline(inVeri, veri, ')');
                liste->sil(stoi(veri));
                break;
            case 'e':
                getline(inVeri, veri, '#');
                sira = stoi(veri);
                getline(inVeri, veri, ')');
                liste->ekle(sira, veri);
                break;
        }
        getline(inVeri, veri);
    }
    liste->yazdir();
}