/**
* @file AvlDugum.cpp
* @description agac dugum verisinin atandıgı kaynak
* @course 1. ogretim b grubu
* @assignment 2
* @date 25/12/2021
* @author Suleyman Arif Karakilic suleyman.karakilic@ogr.sakarya.edu.tr
**/
#include "AvlDugum.hpp"
#include "Kuyruk.hpp"

AvlDugum::AvlDugum(Kuyruk* veri)
{
    this->veri =veri;
    sol=sag=0;
}
AvlDugum::~AvlDugum()
{
    delete veri;
}