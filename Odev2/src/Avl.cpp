/**
* @file Avl.cpp
* @description Avl agaclarinin fonksiyonlarının bulundugu kaynak
* @course 1. ogretim b grubu
* @assignment 2
* @date 25/12/2021
* @author Suleyman Arif Karakilic suleyman.karakilic@ogr.sakarya.edu.tr
**/
#include "Avl.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>

 using namespace std;

Avl::Avl()
{
    kok=0;
}
Avl::~Avl()
{
    agacSil(kok);
    kok=0;
}
void Avl::agacSil(AvlDugum* avlDugum)
{
    if(avlDugum!=nullptr)
    {
        agacSil(avlDugum->sol);
        agacSil(avlDugum->sag);
        delete avlDugum;
    }
}
void Avl::ekle(Kuyruk* eklenecek)
{
    kok = ekle(eklenecek, kok);
}
int Avl::yukseklik()
{
    return yukseklik(kok);
}
void Avl::postOrder()
{
    postOrder(kok);
}
void Avl::postOrder(AvlDugum* avlAktif)
{
    if(avlAktif)
    {
        postOrder(avlAktif->sol);
        postOrder(avlAktif->sag);
        cout<<avlAktif->veri<< " ";
    }
}
int Avl::yukseklik(AvlDugum* avlAktifDugum)
{
    if(avlAktifDugum)
    {
        return 1+max(yukseklik(avlAktifDugum->sol),
                     yukseklik(avlAktifDugum->sag));
    }
    return -1;
}
AvlDugum* Avl::ekle(Kuyruk* veri,AvlDugum* AvlAktifDugum) 
{
    if(AvlAktifDugum==0)
        return new AvlDugum(veri);

	else if(AvlAktifDugum->veri->uzunluk()<veri->uzunluk())
    {
        AvlAktifDugum->sag=ekle(veri,AvlAktifDugum->sag);
        if(yukseklik(AvlAktifDugum->sag)-yukseklik(AvlAktifDugum->sol)>1)
        {   
            if(veri->uzunluk()>AvlAktifDugum->sag->veri->uzunluk())
                AvlAktifDugum = soladondur(AvlAktifDugum);
                
            else
            {
                AvlAktifDugum->sag = sagadondur(AvlAktifDugum->sag);
                AvlAktifDugum =soladondur(AvlAktifDugum);
            }
        }
    }
    else
    {
        AvlAktifDugum->sol = ekle(veri,AvlAktifDugum->sol);
        if(yukseklik(AvlAktifDugum->sol)-yukseklik(AvlAktifDugum->sag)>1)
        {

            if(veri->uzunluk()<=AvlAktifDugum->sol->veri->uzunluk())
                AvlAktifDugum = sagadondur(AvlAktifDugum);
            else
            {
                AvlAktifDugum->sol = soladondur(AvlAktifDugum->sol);
                AvlAktifDugum =sagadondur(AvlAktifDugum);
            }
        }

    }
    return AvlAktifDugum;
}
AvlDugum* Avl::soladondur(AvlDugum* buyukEbeveyn) 
{
	AvlDugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
AvlDugum* Avl::sagadondur(AvlDugum* buyukEbeveyn) 
{
	AvlDugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}

ostream& operator<< (ostream& os, Avl* agac)
{
    agac->postOrder();
}