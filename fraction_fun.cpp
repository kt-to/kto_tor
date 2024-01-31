#include "fraction.h"
#pragma once

void fraction::print() {
    norm();
    num_.print();
    std::cout << "/";
    dum_.print();
}

fraction::fraction() {};

fraction::fraction(bigInt num, bigInt dum) {
    num_ = num;
    dum_ = dum;
}

fraction::fraction(std::string num, std::string dum) {
    num_ = bigInt(num);
    dum_ = bigInt(dum);
}

void fraction::norm() {
    bigInt sup = gcd(num_, dum_);
    num_ = num_ / sup;
    dum_ = dum_ / sup;
    return;
}