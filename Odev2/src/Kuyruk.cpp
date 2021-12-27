/**
* @file Kuyruk.cpp
* @description kuyrugun fonksiyonlarinin bulundugu kaynak
* @course 1. ogretim b grubu
* @assignment 2
* @date 25/12/2021
* @author Suleyman Arif Karakilic suleyman.karakilic@ogr.sakarya.edu.tr
**/
#include <iostream>
#include <math.h>
#include "Kuyruk.hpp"
#include "nokta.hpp"
#include "Dugum.hpp"

using namespace std;

Kuyruk::Kuyruk()
    {
       ilk=son=0;
       count=0;
    }
Kuyruk::~Kuyruk(){
       while(ilk!=0)
       {
           Dugum* gec= ilk;
           ilk=ilk->sonraki;
           delete gec;
       }
   }
Dugum* Kuyruk::enKucukDugum()
{
    Dugum* dugum= ilk;
    if(ilk==nullptr) return 0;
    Dugum* enkucuk= ilk;
    while (dugum->sonraki!=nullptr)
    {
        if(dugum->sonraki->veri.uzaklik < enkucuk->veri.uzaklik)
        {
            enkucuk= dugum->sonraki;
        }
        dugum= dugum->sonraki;
    }
    return enkucuk;
}

void Kuyruk::ekle (nokta veri)
{
    if(ilk==nullptr)
    {
        ilk = new Dugum(veri);
        son= ilk;
        count++;
    }
    else
    {
        Dugum* yeni = new Dugum(veri);
        Dugum* onceki = ilk;
        while (onceki->sonraki!=nullptr)
        {
            onceki = onceki->sonraki;
        }
        onceki->sonraki=yeni;
        count++;
    }          
}
void Kuyruk::sil(Dugum* dugum)
{
    if(ilk==nullptr) return;
    if(ilk==dugum)
    {
        ilk=ilk->sonraki;
        delete dugum;
        count--;
    }
    else
    {
        Dugum* temp =ilk;
        while (temp->sonraki!=nullptr)
        {

            if(temp->sonraki==dugum)
            {
                temp->sonraki=dugum->sonraki;
                delete dugum;
                count--;
                break;
            }
            temp= temp->sonraki;
        }
        
    }
}
 int Kuyruk::uzunluk()
{
    if(ilk == nullptr) return 0;
    int uzunluk = 0;
    Dugum* dugum = ilk;
   
       
        for (int i = 0; i < count-1; i++)
        {
            uzunluk +=sqrt(pow((dugum->veri.x - dugum->sonraki->veri.x),2) + 
                       pow((dugum->veri.y - dugum->sonraki->veri.y),2) + 
                       pow((dugum->veri.z - dugum->sonraki->veri.z),2));

             dugum = dugum->sonraki;


        }
    
    return uzunluk;
}       
 ostream& operator<<(ostream& os, Kuyruk* kuyruk)
 {
     Kuyruk* temp = new Kuyruk();
     Dugum* dugum = kuyruk->ilk;
     for (int i = 0; i < kuyruk->count; i++)
     {
        temp->ekle(dugum->veri);
        dugum= dugum->sonraki;
     }
     for (int i = 0; i < kuyruk->count; i++)
     {
        dugum= temp->enKucukDugum();
        os<< dugum->veri.uzaklik<< " ";
        temp->sil(dugum);
     }
     os<<endl;
     delete temp;
    return os;
     
     

     
 }