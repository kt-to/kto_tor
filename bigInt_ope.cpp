#include "bigInt.h"


bigInt bigInt::operator+(bigInt other) {
    bigInt ans = *this;
    ans.data_.push_back(0);
    other.data_.push_back(0);
    ans.fix_size(other.data_.size());
    other.fix_size(ans.data_.size());
    int last = 0;
    for (int i = 0; i < ans.data_.size(); ++i) {
        ans.data_[i] += other.data_[i] + last;
        last = ans.data_[i] / sis_;
        ans.data_[i] %= sis_;
    }
    ans.norm();
    return ans;
}

bigInt bigInt::operator-(bigInt other) {
    bigInt ans = *this;
    other.fix_size(ans.data_.size());
    int last = 0;
    for (int i = 0; i < data_.size(); ++i) {
        ans.data_[i] -= (other.data_[i] + last);
        if (ans.data_[i] < 0) {
            ans.data_[i] += sis_;
            last = 1;
        } else {
            last = 0;
        }
    }
    ans.norm();
    return ans;
}

bigInt bigInt::operator*(bigInt other) {
    bigInt ans;
    other.norm();
    for (int i = 0; i < other.data_.size(); ++i) {
        bigInt now = *this;
        int last = 0;
        for (int j = 0; j < data_.size(); ++j) {
            now.data_[j] *= other.data_[i];
            now.data_[j] += last;
            last = now.data_[j] / sis_;
            now.data_[j] %= sis_;
        }
        now.data_.push_back(last);
        std::reverse(now.data_.begin(), now.data_.end());
        for (int j = 0; j < i; ++j) {
            now.data_.push_back(0);
        }
        std::reverse(now.data_.begin(), now.data_.end());
        ans = ans + now;
    }
    return ans;
}

void bigInt::del_2() {
    norm();
    int last = 0;
    std::reverse(data_.begin(), data_.end());
    for (int i = 0; i < data_.size(); ++i) {
        int now = data_[i] + last;
        data_[i] = now / 2;
        last = now % 2;
        last *= sis_;
    }
    std::reverse(data_.begin(), data_.end());
}

bigInt bigInt::operator/(bigInt other) {
    bigInt l(0), r = *this + 1;
    while (r - l > 1) {
        bigInt mid = (r + l);
        mid.del_2();
        if (other * mid > *this) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

bigInt bigInt::operator%(bigInt other) {
    bigInt pre_ans = *this / other;
    return *this - (other * pre_ans);
}

bool bigInt::operator <(bigInt other) {
    norm();
    other.norm();
    if (data_.size() != other.data_.size()) return data_.size() < other.data_.size();
    std::reverse(other.data_.begin(), other.data_.end());
    std::reverse(data_.begin(), data_.end());
    for (int i = 0; i < data_.size(); ++i) {
        if (data_[i] != other.data_[i]) {
            bool ans = data_[i] < other.data_[i];
            std::reverse(other.data_.begin(), other.data_.end());
            std::reverse(data_.begin(), data_.end());
            return ans;
        }
    }
    std::reverse(other.data_.begin(), other.data_.end());
    std::reverse(data_.begin(), data_.end());
    return false;
}

bool bigInt::operator>(bigInt other) {
    return (other < *this);
}

bool bigInt::operator==(bigInt other) {
    return (!(*this < other) && !(*this > other));
}

bool bigInt::operator!=(bigInt other) {
    return !(*this == other);
}

bool bigInt::operator<=(bigInt other) {
    return ((*this < other) || (*this == other));
}

bool bigInt::operator>=(bigInt other) {
    return ((*this > other) || (*this == other));
}