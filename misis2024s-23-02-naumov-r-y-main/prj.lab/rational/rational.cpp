#include <rational/rational.hpp>
#include <iostream>
#include <stdexcept>
#include <algorithm>

int Rational::NOD(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    if (a == b || a == 0) {
        return b;
    }
    if (a > b) {
        return NOD(a - b, b);
    }
    return NOD(a, b - a);
}

Rational& Rational::round() {
    if (denum_ < 0) {
        num_ *= -1;
        denum_ *= -1;
    }
    int nod = Rational::NOD(num_, denum_);
    num_ /= nod;
    denum_ /= nod;
    return *this;
}
bool Rational::operator==(const Rational& rhs) const {
    return (num_ == rhs.num_ && denum_ == rhs.denum_);
}

bool Rational::operator!=(const Rational& rhs) const {
    return !operator==(rhs);
}

Rational::Rational(const int num, const int denum) {
    if (denum == 0)
        throw std::invalid_argument("Creating Rational with 0 denum");
    num_ = num;
    denum_ = denum;
    this->round();
}
Rational::Rational(const int rhs)
{
    num_ = rhs;
    denum_ = 1;
    this->round();
}

Rational::Rational(const Rational& rhs)
{
    num_ = rhs.num_;
    denum_ = rhs.denum_;
    this->round();
}

bool Rational::operator>(const Rational& rhs) const {
    if (num_* rhs.num_ < 0) {
        return num_ > 0;
    }
    return num_ * rhs.denum_ > rhs.num_ * denum_;
}

bool Rational::operator<(const Rational& rhs) const {
    if (num_ * rhs.num_ < 0) {
        return num_ < 0;
    }
    return num_ * rhs.denum_ < rhs.num_ * denum_;
}

Rational& Rational::operator+=(const Rational& rhs) {
    int nod = NOD(denum_, rhs.denum_);
    num_ = (num_ * rhs.denum_) / nod + rhs.num_ * denum_ / nod;
    denum_ = (denum_ * rhs.denum_) / nod;
    this->round();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    int nod = NOD(denum_, rhs.denum_);
    num_ = (num_ * rhs.denum_) / nod - rhs.num_ * denum_ / nod;
    denum_ = (denum_ * rhs.denum_) / nod;
    this->round();
    return *this;
}

Rational& Rational::operator*= (const Rational& rhs) {
    num_ *= rhs.num_;
    denum_ *= rhs.denum_;
    this->round();
    return *this;
}

Rational& Rational::operator/= (const Rational& rhs) {
    denum_ *= rhs.num_;
    if (denum_ == 0 || rhs.denum_ == 0) {
        throw std::invalid_argument("division by zero");
    }
    num_ *= rhs.denum_;
    this->round();
    return *this;
}

Rational Rational::operator-() {
    return Rational(-num_, denum_);
}

std::ostream& operator<< (std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}
std::istream& operator>> (std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num_ << slash << denum_;
    return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm)
{
    int num1(0);
    char slash(0);
    int denum1(1);
    istrm >> num1;
    istrm.get(slash);
    int trash = istrm.peek();
    istrm >> denum1;
    if (!istrm || trash > '9' || trash < '0') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    if (istrm.good() || istrm.eof()) {
        if (Rational::slash == slash && denum1 > 0) {
            *this = Rational(num1, denum1);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
