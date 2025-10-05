#ifndef HPP_FIXED
#define HPP_FIXED

#include <iostream>

class Fixed {
private:
	int 				_fixedPointValue;
	static const int 	_fractionalBits = 8;

public:
	Fixed ();
	Fixed (const int intValue);
	Fixed (const float floatValue);
	float toFloat() const;
	int toInt() const;
	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif
