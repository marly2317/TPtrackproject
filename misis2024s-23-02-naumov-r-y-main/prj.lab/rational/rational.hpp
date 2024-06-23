#ifndef UNTITLED_RATIONAL_H
#define UNTITLED_RATIONAL_H
#endif //UNTITLED_RATIONAL_H
#include <iosfwd>

class Rational {
public:
    Rational() = default;
    explicit Rational(const int rhs);
    Rational(const Rational& rhs);
    Rational(const int num, const int denum);
    Rational& operator=(const Rational& rhs) = default;
    ~Rational() = default;

    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    bool operator>(const Rational& rhs) const;
    bool operator<(const Rational& rhs) const;

    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs) {
        return operator+= (Rational(rhs));
    }

    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int rhs) {
        return operator-= (Rational(rhs));
    }

    Rational& operator*= (const Rational& rhs);
    Rational& operator*= (const int rhs) {
        return operator*= (Rational(rhs));
    }

    Rational& operator/= (const Rational& rhs);
    Rational& operator/= (const int rhs) {
        return operator/= (Rational(rhs));
    }

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    Rational operator-();

private:
    int num_{ 0 };
    int denum_{ 1 };
    int NOD(int a, int b);
    static const char slash{ '/' };
    Rational& round();
};
inline Rational operator+ (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) += rhs;
}
inline Rational operator+ (const Rational& lhs, const int rhs) {
    return Rational(lhs) + Rational(rhs);
}
inline Rational operator+ (const int lhs, const Rational& rhs) {
    return Rational(lhs) + Rational(rhs);
}

inline Rational operator- (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) -= rhs;
}
inline Rational operator- (const Rational& lhs, const int rhs) {
    return Rational(lhs) - Rational(rhs);
}
inline Rational operator- (const int lhs, const Rational& rhs) {
    return Rational(lhs) - Rational(rhs);
}

inline Rational operator* (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) *= rhs;
}
inline Rational operator* (const Rational& lhs, const int rhs) {
    return Rational(lhs) * Rational(rhs);
}
inline Rational operator* (const int lhs, const Rational& rhs) {
    return Rational(lhs) * Rational(rhs);
}

inline Rational operator/ (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs) /= rhs;
}
inline Rational operator/ (const Rational& lhs, const int rhs) {
    return Rational(lhs) / Rational(rhs);
}
inline Rational operator/ (const int lhs, const Rational& rhs) {
    return Rational(lhs) / Rational(rhs);
}

std::ostream& operator<< (std::ostream& ostrm, const Rational& rhs);
std::istream& operator>> (std::istream& istrm, Rational& rhs);