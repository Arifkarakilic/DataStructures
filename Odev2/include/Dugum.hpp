#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
#include "nokta.hpp"

using namespace std;

class Dugum
{
    
public:
    Dugum* onceki=nullptr;
    Dugum* sonraki=nullptr;
    nokta veri;
    Dugum(nokta veri);
    ~Dugum();
};

#endif