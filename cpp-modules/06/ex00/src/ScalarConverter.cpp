#include "../inc/ScalarConverter.hpp"
#include "../inc/macros.hpp"

/* constructors */
ScalarConverter::ScalarConverter() {
	if (VERBOSE)
		std::cout << "[ScalarConverter] private constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string sliteral) : _sliteral(sliteral) {
	if (VERBOSE)
		std::cout << "[ScalarConverter] default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) : _sliteral(ref.getSliteral()) {
	if (VERBOSE)
		std::cout << "[ScalarConverter] copy constructor called" << std::endl;
}

/* destructors */
ScalarConverter::~ScalarConverter() {
	if (VERBOSE)
		std::cout << "[ScalarConverter] default destructor called" << std::endl;
}

/* overload operators */
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &ref) {
	if (VERBOSE)
		std::cout << "[ScalarConverter] copy overload operator called" << std::endl;
	this->_sliteral = ref.getSliteral();
	return (*this);
}

std::ostream	&operator<<(std::ostream &fd, const ScalarConverter &ref) {
	fd << "char: "; ref.printChar();
	fd << "int: "; ref.printInt();
	fd << "float: "; ref.printFloat();
	fd << "double: "; ref.printDouble();

	return (fd);
}

/* utils */
bool	ScalarConverter::isChar() const {
	if (this->getSliteral().length() == 1 &&\
		std::isalpha(this->getSliteral()[0]) && std::isprint(this->getSliteral()[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt() const {
	int j = 0;
	if (this->getSliteral()[0] == '-')
		j++;
	for (int i = j; this->_sliteral[i]; i++) {
		if (!std::isdigit(this->getSliteral()[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat() const {
	if (this->getSliteral().find('.') == std::string::npos || this->getSliteral()[this->getSliteral().length() - 1] != 'f'\
		|| this->getSliteral().find('.') == 0)
		return (false);
	int j = 0;
	int	float_bool = 0;
	if (this->getSliteral()[0] == '-')
		j++;
	for (int i = j; this->_sliteral[i + 1]; i++) {
		if (this->getSliteral()[i] == '.')
			float_bool++;
		if ((!std::isdigit(this->getSliteral()[i]) && this->getSliteral()[i] != '.' ) ||\
			float_bool >  1)
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isDouble() const {
	if (this->getSliteral().find('.') == std::string::npos || this->getSliteral().find('.') == 0)
		return (false);
	int j = 0;
	int	float_bool = 0;
	if (this->getSliteral()[0] == '-')
		j++;
	for (int i = j; this->_sliteral[i]; i++) {
		if (this->getSliteral()[i] == '.')
			float_bool++;
		if ((!std::isdigit(this->getSliteral()[i]) && this->getSliteral()[i] != '.' ) ||\
			float_bool >  1)
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isSpecial() const {
	if (this->_sliteral == "-inff" || this->_sliteral == "+inff" || this->_sliteral == "nanf")
		return (true);
	if (this->_sliteral == "-inf" || this->_sliteral == "+inf" || this->_sliteral == "nan")
		return (true);
	return (false);
}

bool	ScalarConverter::isImpossible() {
	char	*end;
	long	tmp;
	double	tmp2;
	switch (this->getType()) {
		case INT_T:
			tmp = std::strtol(this->_sliteral.c_str(), &end, 10);
			if (tmp > INT_MAX || tmp < INT_MIN) {
				throw OverflowExept;
				break ;
			}
			this->_intConvert = static_cast<int>(tmp);
			break;
		case FLOAT_T:
			tmp2 = std::atof(this->_sliteral.c_str());
			if (tmp2 > FLT_MAX || tmp2 < FLT_MIN) {
				throw OverflowExept;
				break ;
			}
			this->_floatConvert = static_cast<float>(tmp2);
			break;
		case DOUBLE_T:
			this->_doubleConvert = std::atof(this->_sliteral.c_str());
			if (std::isinf(_doubleConvert)) {
				throw OverflowExept;
				return (true);
			}
			break ;
	}
	return (false);
}

/* getters */
std::string ScalarConverter::getSliteral() const {
	return (_sliteral);
}

int		ScalarConverter::getType() const {
	return (this->_type);
}

char	ScalarConverter::getCharConvert() const {
	return (this->_charConvert);
}

int		ScalarConverter::getIntConvert() const {
	return (this->_intConvert);
}

float	ScalarConverter::getFloatConvert() const {
	return (this->_floatConvert);
}

double	ScalarConverter::getDoubleConvert() const {
	return (this->_doubleConvert);
}

/* setters */
void	ScalarConverter::setType() {
	if (this->isChar()) {
		this->_type = CHAR_T; }
	else if (this->isInt()) {
		this->_type = INT_T; }
	else if (this->isFloat()) {
		this->_type = FLOAT_T; }
	else if (this->isDouble()) {
		this->_type = DOUBLE_T; }
	else if (this->isSpecial()) {
		this->_type = SPECIAL_T; }
	else this->_type = NO_T;
}

/* actions */
void	ScalarConverter::convert() {
	this->setType();
	if (this->getType() == NO_T) {
		throw NotScalar;
		return ;
	}
	if (this->isImpossible())
		return ;
	switch (this->getType()) {
		case CHAR_T:
			this->_charConvert = this->_sliteral[0];
			this->_intConvert = (int)(this->_sliteral)[0];
			this->_floatConvert = (float)(this->_sliteral[0]);
			this->_doubleConvert = (double)(this->_sliteral[0]);
			break ;
		case INT_T:
			this->_charConvert = static_cast<char>(this->_intConvert);
			this->_floatConvert = static_cast<float>(this->_intConvert);
			this->_doubleConvert = static_cast<double>(this->_intConvert);
			break ;
		case FLOAT_T:
			this->_charConvert = static_cast<char>(this->_floatConvert);
			this->_intConvert = static_cast<int>(this->_floatConvert);
			this->_doubleConvert = static_cast<double>(this->_floatConvert);
			break ;
		case DOUBLE_T:
			this->_charConvert = static_cast<char>(this->_doubleConvert);
			this->_intConvert = static_cast<int>(this->_doubleConvert);
			this->_floatConvert = static_cast<float>(this->_doubleConvert);
			break ;
		default:
			break ;
	}
}

void	ScalarConverter::printChar() const {
	int type = this->getType();
	if (type == CHAR_T)
			std::cout << this->getCharConvert() << std::endl;
	else if ((type == INT_T || type == FLOAT_T || type == DOUBLE_T) && this->getDoubleConvert() < 128) {
		if (std::isprint(this->getDoubleConvert())) { std::cout << (char)this->getIntConvert() << std::endl; }
		else { std::cout << "Non displayable" << std::endl; }
	}
	else
		std::cout << "Impossible" << std::endl;
}

void	ScalarConverter::printInt() const {
	int type = this->getType();
	if (type == INT_T || type == CHAR_T)
		std::cout << this->getIntConvert() << std::endl;
	else if (type == FLOAT_T || type == DOUBLE_T) {
		if (this->getFloatConvert() > INT_MAX || this->getFloatConvert() < INT_MIN)
			std::cout << "Impossible" << std::endl;
		else
			std::cout << this->getIntConvert() << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;
}

void	ScalarConverter::printFloat() const {
	int type = this->getType();
	if (type == DOUBLE_T && (this->getDoubleConvert() > FLT_MAX || this->getDoubleConvert() < FLT_MIN))
		std::cout << "Impossible" << std::endl;
	else if (type == SPECIAL_T) {
		if (this->getSliteral() == "nanf")
			std::cout << this->getSliteral() << std::endl;
		else if (this->getSliteral()[this->getSliteral().length() - 2] == 'f')
			std::cout << this->getSliteral() << std::endl;
		else
			std::cout << this->getSliteral() + "f" << std::endl;
	}
	else if (this->getFloatConvert() - (long)this->getFloatConvert() == 0.0f)
		std::cout << this->getFloatConvert() << ".0f" << std::endl;
	else
		std::cout << this->getFloatConvert() << "f" << std::endl;
}

void	ScalarConverter::printDouble() const {
	if (this->getType() == SPECIAL_T) {
		if (this->getSliteral() == "nanf")
			std::cout << this->getSliteral().substr(0,this->getSliteral().length() - 1) << std::endl;
		else if (this->getSliteral()[this->getSliteral().length() - 2] == 'f')
			std::cout << this->getSliteral().substr(0,this->getSliteral().length() - 1) << std::endl;
		else
			std::cout << this->getSliteral() << std::endl;
	}
	else if (this->getDoubleConvert() - (long long)this->getDoubleConvert() == 0.0f)
		std::cout << this->getDoubleConvert() << ".0" <<std::endl;
	else
		std::cout << this->getDoubleConvert() << std::endl;
}