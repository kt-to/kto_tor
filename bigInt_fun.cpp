#include "bigInt.h"


bigInt::bigInt() {}

bigInt::bigInt(int ch) {
    data_.clear();
    for (int i = 0; i < 10; ++i) {
        data_.push_back(ch % 10);
        ch /= 10;
    }
    norm();
}

bigInt::bigInt(std::string s) {
    data_.clear();
    bool open = false;
    int now = 0;
    for (auto to : s) {
        if (open) {
            if (to == ']') {
                data_.push_back(now);
                open = false;
                now = 0;
                continue;
            } else {
                now *= 10;
                now += (to - '0');
                continue;
            }
        }
        if (!open && to == '[') {
            open = true;
            continue;
        }
        data_.push_back(to - '0');
    }
    std::reverse(data_.begin(), data_.end());
}

bigInt::bigInt(std::string s, int sis) {
    data_.clear();
    bool open = false;
    int now = 0;
    for (auto to : s) {
        if (open) {
            if (to == ']') {
                data_.push_back(now);
                open = false;
                now = 0;
                continue;
            } else {
                now *= 10;
                now += (to - '0');
                continue;
            }
        }
        if (!open && to == '[') {
            open = true;
            continue;
        }
        data_.push_back(to - '0');
    }
    sis_ = sis;
    std::reverse(data_.begin(), data_.end());
}

void bigInt::print() {
    norm();
    std::reverse(data_.begin(), data_.end());
    for (auto to : data_) {
        std::cout << to;
    }
    std::reverse(data_.begin(), data_.end());
}

void bigInt::to10() {
    bigInt now(1);
    bigInt ans(0);
    bigInt wi(0);
    bool open = false;
    for (int i = 0; i < data_.size(); ++i) {
        if (open) {
            if (data_[i] == ']') {
                open = false;
                ans = ans + (wi * now);
                now = now * sis_;
                wi = 0;
                continue;
            } else {
                wi = wi * sis_;
                wi = wi + data_[i];
            }
        } else {
            if (data_[i] == '[') {
                open = true;
                continue;
            } else {
                ans = ans + (bigInt(data_[i]) * now);
                now = now * sis_;
            }
        }
    }
    sis_ = 10;
    *this = ans;
    return;
}

void bigInt::toNsis(bigInt sis) {
    norm();
    bigInt ans(0);
    ans.data_.clear();
    while (*this >= sis) {
        bigInt now = (*this) % sis;
        ans.data_.push_back(now.to_int());
        (*this) = (*this) / sis;
        norm();
    }
    sis_ = sis.to_int();
    ans.data_.push_back(this->to_int());
    (*this) = ans;
}

int bigInt::to_int() {
    int ans = 0;
    int st = 1;
    for (int i = 0; i < data_.size(); ++i) {
        ans += data_[i] * st;
        st *= 10;
    }
    return ans;
}

void bigInt::norm() {
    while (data_.size() > 1 && data_.back() == 0) {
        data_.pop_back();
    }
}

void bigInt::fix_size(int n) {
    while (data_.size() < n) {
        data_.push_back(0);
    }
}

std::string bigInt::to_str() {
    std::string ans;
    norm();
    std::reverse(data_.begin(), data_.end());
    for (int to : data_) {
        if (to >= 10) {
            ans += '[';
        }
        std::string g = std::to_string(to);
        ans += g;
        if (to >= 10) {
            ans += ']';
        }
    }
    return ans;
}

bigInt gcd(bigInt a, bigInt b) {
    while (b > 0) {
        a = a % b;
        std::swap(a, b);
    }
    return a;
}

bigInt lcm(bigInt a, bigInt b) {
    return (a * b) / gcd(a, b);
}

void bigInt::set_sis(int n) {
    sis_ = n;
}

void bigInt::cross(bigInt new_sis) {
    this->to10();
    this->toNsis(new_sis);
}