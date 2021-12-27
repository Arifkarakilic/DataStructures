/**
* @file main.cpp
* @description projenin fonksiyonlarinin oldugu kaynak dosyasi
* @course 1. ogretim b grubu
* @assignment 1
* @date 4/11/2021
* @author Suleyman Arif Karakilic suleyman.karakilic@ogr.sakarya.edu.tr
**/

#include <iostream>
#include "Dugum.hpp"
#include "Bagliliste.hpp"
using namespace std;

Bagliliste::Bagliliste(){
    uzunluk=0;
}

Bagliliste::~Bagliliste(){
    for(int i = uzunluk - 1; i >= 0; i--){
        sil(i);
        
    }
}

void Bagliliste::yazdir(){
    Dugum* tmp=this->kok;
    
    if(tmp != nullptr){
    cout<<tmp->veri;
    tmp=tmp->sonraki;
    }
    

    while(tmp != nullptr){
        cout<<" <--> " << tmp->veri;
        tmp=tmp->sonraki;
    }
}

void Bagliliste::ekle(string veri){

    Dugum* dgm=new Dugum(veri);

    if(kok==nullptr){
        kok=dgm;
    }
    else{
        Dugum* tmp= kok;
        while (tmp->sonraki!=nullptr)
        {
            tmp=tmp->sonraki;
        }
        tmp->sonraki=dgm;
        dgm->onceki=tmp;
    }
    uzunluk++;
}

void Bagliliste::ekle(int sira, string veri){


    if(kok==nullptr){
        Dugum* dgm=new Dugum(veri);
        kok=dgm;
        uzunluk++;
        return;
    }

    
    Dugum* tmp=kok;
    
    
if (sira>=0)
{
   if(uzunluk<=sira){
        ekle(veri);
        return;
    }

    ekle("");

    while (tmp->sonraki!=nullptr)
    {
        tmp=tmp->sonraki;
    }

    for(int i=0;i<uzunluk-sira-1;i++){
        tmp->veri=tmp->onceki->veri;
        tmp=tmp->onceki;
    }

    tmp->veri=veri;
}


    
    
}

void Bagliliste::sil(int sira){
    if (sira>=0)
    {
        Dugum* tmp=kok;

    if(uzunluk-1<=sira){
        sil();
        return;
    }

    for(int i=0;i<sira;i++){
        tmp=tmp->sonraki;
    }

    for(int i=0;i<uzunluk - sira - 1;i++){
        tmp->veri=tmp->sonraki->veri;
        tmp=tmp->sonraki;
    }
    if(tmp->onceki != nullptr){
        tmp->onceki->sonraki = nullptr;
    }

    delete tmp;
    tmp = nullptr;
    uzunluk--;
    }

    
    
    
    
}

void Bagliliste::sil(){

    Dugum* tmp=kok;

    for(int i=0;i<uzunluk-1;i++){
        tmp=tmp->sonraki;
    }
    
    if(tmp->onceki!=nullptr){
        tmp->onceki->sonraki=nullptr;
    }


    delete tmp;

    if(tmp == kok){
        kok = nullptr;
    }
    uzunluk--;

}




