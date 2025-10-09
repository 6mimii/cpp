#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _raw(0) {}
Fixed::Fixed(const int n) { _raw = n << _fractionalBits; }
Fixed::Fixed(const float f) { _raw = static_cast<int>(roundf(f * (1 << _fractionalBits))); }
Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed::~Fixed() {}
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _raw = other._raw;
    return *this;
}

float Fixed::toFloat(void) const { return _raw / static_cast<float>(1 << _fractionalBits); }
int Fixed::toInt(void) const { return _raw >> _fractionalBits; }
int Fixed::getRawBits(void) const { return _raw; }
void Fixed::setRawBits(int const raw) { _raw = raw; }

bool Fixed::operator>(const Fixed& other) const { return _raw > other._raw; }
bool Fixed::operator<(const Fixed& other) const { return _raw < other._raw; }
bool Fixed::operator>=(const Fixed& other) const { return _raw >= other._raw; }
bool Fixed::operator<=(const Fixed& other) const { return _raw <= other._raw; }
bool Fixed::operator==(const Fixed& other) const { return _raw == other._raw; }
bool Fixed::operator!=(const Fixed& other) const { return _raw != other._raw; }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    res.setRawBits((_raw * other._raw) >> _fractionalBits);
    return res;
}
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed res;
    res.setRawBits((_raw << _fractionalBits) / other._raw);
    return res;
}

Fixed& Fixed::operator++() { _raw++; return *this; }       // pre
Fixed Fixed::operator++(int) { Fixed tmp(*this); _raw++; return tmp; } // post
Fixed& Fixed::operator--() { _raw--; return *this; }
Fixed Fixed::operator--(int) { Fixed tmp(*this); _raw--; return tmp; }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b ? a : b); }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b ? a : b); }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b ? a : b); }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b ? a : b); }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}