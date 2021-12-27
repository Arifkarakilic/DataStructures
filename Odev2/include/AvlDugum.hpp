#ifndef AvlDugum_hpp
#define AvlDugum_hpp
#include "Kuyruk.hpp"

class AvlDugum
{

public:
    AvlDugum(Kuyruk* veri);
    ~AvlDugum();
    Kuyruk* veri;
    AvlDugum* sol;
    AvlDugum* sag;
};

#endif