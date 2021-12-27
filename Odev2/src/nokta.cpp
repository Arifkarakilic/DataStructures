/**
* @file nokta.cpp
* @description noktaya veri atanan kaynak kodu
* @course 1. ogretim b grubu
* @assignment 2
* @date 25/12/2021
* @author Suleyman Arif Karakilic suleyman.karakilic@ogr.sakarya.edu.tr
**/
#include <iostream>
#include "nokta.hpp"
#include <cmath>

using namespace std;

nokta::nokta(int x, int y, int z)
{
    this->x=x;
    this->y=y;
    this->z=z;
    uzaklik = sqrt(x*x+y*y+z*z);
}
nokta::nokta()
{
    x=y=z=0;
}
