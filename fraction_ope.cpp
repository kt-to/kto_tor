#include "fraction.h"

fraction fraction::operator+(fraction other) {
    fraction ans;
    ans.dum_ = lcm(dum_, other.dum_);
    ans.num_ = num_ * (ans.dum_ / dum_) +
            other.num_ * (ans.dum_ / other.dum_);
    ans.norm();
    return ans;
}

fraction fraction::operator-(fraction other) {
    fraction ans;
    ans.dum_ = lcm(dum_, other.dum_);
    ans.num_ = num_ * (ans.dum_ / dum_) -
               other.num_ * (ans.dum_ / other.dum_);
    ans.norm();
    return ans;
}

fraction fraction::operator*(fraction other) {
    fraction ans;
    ans.num_ = num_ * other.num_;
    ans.dum_ = dum_ * other.dum_;
    ans.norm();
    return ans;
}

fraction fraction::operator/(fraction other) {
    fraction ans;
    ans.num_ = num_ * other.dum_;
    ans.dum_ = dum_ * other.num_;
    ans.norm();
    return ans;
}

bool fraction::operator<(fraction other) {
    return num_ * other.dum_ < other.num_ * dum_;
}

bool fraction::operator>(fraction other) {
    return other < *this;
}

bool fraction::operator==(fraction other) {
    return !(*this < other) && !(other < *this);
}

bool fraction::operator!=(fraction other) {
    return !(*this == other);
}

bool fraction::operator>=(fraction other) {
    return (*this > other) || (*this == other);
}

bool fraction::operator<=(fraction other) {
    return (*this < other) || (*this == other);
}