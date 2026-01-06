#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

static bool isCharLiteral(const std::string& s) {
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isIntLiteral(const std::string& s) {
	if (s.empty()) return false;

	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') i++;
	if (i >= s.length()) return false;

	while (i < s.length()) {
		if (!std::isdigit(s[i])) return false;
		i++;
	}
	return true;
}

static bool isFloatLiteral(const std::string& s) {
	if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
		return true;

	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return false;

	std::string without_f = s.substr(0, s.length() - 1);

	size_t i = 0;
	if (without_f[i] == '+' || without_f[i] == '-') i++;

	bool has_dot = false;
	while (i < without_f.length()) {
		if (without_f[i] == '.') {
			if (has_dot) return false;
			has_dot = true;
		} else if (!std::isdigit(without_f[i])) {
			return false;
		}
		i++;
	}
	return has_dot;
}

static bool isDoubleLiteral(const std::string& s) {
	if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf")
		return true;

	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') i++;

	bool has_dot = false;
	while (i < s.length()) {
		if (s[i] == '.') {
			if (has_dot) return false;
			has_dot = true;
		} else if (!std::isdigit(s[i])) {
			return false;
		}
		i++;
	}
	return has_dot;
}

static void printChar(double value) {
	if (std::isnan(value) || std::isinf(value) || 
		value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<int>(value))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

static void printInt(double value) {
	if (std::isnan(value) || std::isinf(value) || 
		value < std::numeric_limits<int>::min() || 
		value > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

static void printFloat(double value) {
	float f = static_cast<float>(value);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double value) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	double value = 0.0;

	if (isCharLiteral(literal)) {
		value = static_cast<double>(literal[1]);
	}
	else if (isIntLiteral(literal)) {
		value = static_cast<double>(std::atoi(literal.c_str()));
	}
	else if (isFloatLiteral(literal)) {
		value = static_cast<double>(std::atof(literal.c_str()));
	}
	else if (isDoubleLiteral(literal)) {
		value = std::atof(literal.c_str());
	}
	else {
		std::cout << "Error: Invalid literal format" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
