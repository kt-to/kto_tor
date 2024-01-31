#pragma once
#include "bigInt.h"

class fraction {
public:
    void print();

    fraction();
    fraction(bigInt num, bigInt dum);
    fraction(std::string num, std::string dum);

    fraction operator+(fraction other);
    fraction operator-(fraction other);
    fraction operator*(fraction other);
    fraction operator/(fraction other);

    bool operator <(fraction other);
    bool operator >(fraction other);
    bool operator ==(fraction other);
    bool operator !=(fraction other);
    bool operator >=(fraction other);
    bool operator <=(fraction other);
private:
    void norm();
    bigInt num_, dum_;
};