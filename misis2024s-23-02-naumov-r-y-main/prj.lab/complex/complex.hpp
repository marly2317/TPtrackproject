#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <algorithm>
#include <cmath>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <stdexcept>
struct Complex {
	[[nodiscard]] Complex();
	[[nodiscard]] Complex(const Complex&);
	Complex(Complex&&) = default;
	[[nodiscard]] explicit Complex(const double real);
	[[nodiscard]] Complex(const double real, const double imaginary);

	Complex& operator=(Complex&&) = default;
	Complex& operator=(const Complex& other);
	~Complex() = default;

	[[nodiscard]] Complex operator-() const;

	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator*(const Complex& other);
	Complex operator/(const Complex& other);

	Complex& operator+=(const Complex& other);
	Complex& operator+=(const double rhs);
	Complex& operator-=(const Complex& other);
	Complex& operator-=(const double rhs);
	Complex& operator*=(const Complex& other);
	Complex& operator*=(const double rhs);
	Complex& operator/=(const Complex& other);
	Complex& operator/=(const double rhs);

	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const;

	[[nodiscard]] std::ostream& writeTo(std::ostream& ostrm) const;
	[[nodiscard]] std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

Complex operator+(double lhs, const Complex& rhs);
Complex operator-(double lhs, const Complex& rhs);
Complex operator*(double lhs, const Complex& rhs);
Complex operator/(double lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, double rhs);
Complex operator-(const Complex& lhs, double rhs);
Complex operator*(const Complex& lhs, double rhs);
Complex operator/(const Complex& lhs, double rhs);

inline std::ostream& operator<<(std::ostream& os, const Complex& complex) {
	return complex.writeTo(os);
};
inline std::istream& operator>>(std::istream& is, Complex& complex) {
	return complex.readFrom(is);
};

#endif