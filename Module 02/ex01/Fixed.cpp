#include "Fixed.hpp"
#include <cmath> 


Fixed::Fixed() : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _raw = n << _fractionalBits; 
}


Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _raw = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}


Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _raw = other._raw;
}


Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _raw = other._raw;
    return *this;
}

int Fixed::getRawBits(void) const {
    return _raw;
}

void Fixed::setRawBits(int const raw) {
    _raw = raw;
}

float Fixed::toFloat(void) const {
    return _raw / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _raw >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, Fixed const &fix) {
    os << fix.toFloat();
    return os;
}