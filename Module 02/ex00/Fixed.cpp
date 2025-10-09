#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue (0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

float Fixed::toFloat() const {
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);

}

int Fixed::toInt() const {
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out <<fixed.toFloat();
	return out;
}