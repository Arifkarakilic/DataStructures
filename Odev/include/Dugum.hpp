#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>

using namespace std;

class Dugum
{
private:
    
public:
    string veri;
    Dugum* onceki=nullptr;
    Dugum* sonraki=nullptr;
    Dugum(string veri);
    ~Dugum();
};

#endif