/**
* @file main.cpp
* @description main fonksiyonun ve okuma isleminin oldugu ana kaynak
* @course 1. ogretim b grubu
* @assignment 2
* @date 25/12/2021
* @author Suleyman Arif Karakilic suleyman.karakilic@ogr.sakarya.edu.tr
**/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Dugum.hpp"
#include "Avl.hpp"
#include "kuyruk.hpp"
#include "nokta.hpp"

using namespace std;

int main()
{
    Kuyruk* kuyruk;
    Avl* agac = new Avl();
    


    ifstream inVeri ("./doc/veri.txt");
    string veri;
    
    while(getline(inVeri, veri))
    {
      if(veri.empty())
      {
        continue;
      }
      kuyruk= new Kuyruk();
       istringstream iss (veri);
      while (!iss.eof())
      {
        int valx;
        int valy;
        int valz;
        iss >> valx>>valy>>valz;
        kuyruk->ekle(nokta(valx, valy, valz));
      }
     agac->ekle(kuyruk);
    }


 cout<<" "<<agac<<endl;
 delete agac;

}