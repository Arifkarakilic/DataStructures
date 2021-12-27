#ifndef Avl_hpp
#define Avl_hpp
#include <iostream>
#include "AvlDugum.hpp"

using namespace std;

class Avl
{
public:
    Avl();
    ~Avl();
    void agacSil(AvlDugum* avlDugum);
    void ekle(Kuyruk* veri);
    friend ostream& operator<<(ostream& os,Avl* kuyruk);
    void postOrder();
    void postOrder(AvlDugum* index);
    int yukseklik();
    int yukseklik(AvlDugum* avlAktifDugum);
    AvlDugum* soladondur(AvlDugum* avlDugum);
    AvlDugum* sagadondur(AvlDugum* avlDugum);
    AvlDugum* ekle(Kuyruk* veri, AvlDugum* avlAktifDugum);
    AvlDugum* kok;

};

















#endif