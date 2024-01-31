#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>

class bigInt {
public:
    bigInt();
    bigInt(int ch);
    bigInt(std::string s);
    bigInt(std::string s, int sis);

    // функции
    void print();
    void cross(bigInt new_sis);
    void set_sis(int n);

    std::string to_str();
    int to_int();

    //арифметика
    bigInt operator +(bigInt other);
    bigInt operator -(bigInt other);
    bigInt operator *(bigInt other);
    bigInt operator /(bigInt other);
    bigInt operator %(bigInt other);

    // логика
    bool operator <(bigInt other);
    bool operator >(bigInt other);
    bool operator ==(bigInt other);
    bool operator >=(bigInt other);
    bool operator <=(bigInt other);
    bool operator !=(bigInt other);
private:
    // вспомогательные функции
    void norm();
    void fix_size(int n);
    void del_2();
    void to10();
    void toNsis(bigInt sis);
    int sis_ = 10;
    std::vector<int> data_;
};

bigInt gcd(bigInt a, bigInt b);
bigInt lcm(bigInt a, bigInt b);