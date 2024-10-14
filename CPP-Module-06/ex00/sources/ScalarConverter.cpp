/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:08:59 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/13 11:52:52 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/*--------------------------------- CANONICAL ---------------------------------*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)(other); }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)(other);
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

/*-----------------------------------------------------------------------------*/

static bool isChar(std::string str)
{
	
	if (str.size() == 1 && std::isprint(str[0]) \
		&&( str[0] < '0' || str[0] > '9'))
		return (true);
	else if (str.size() == 3 \
		&& str[0] == '\'' && str[2] == '\'' \
		&& std::isprint(str[1]))
		return (true);
	return (false);
}

static bool	isInteger(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			continue ;
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

static bool isFloat(std::string str)
{
	int	dots = 0, fs = 0, numbers = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			continue;
		else if (std::isdigit(str[i]))
			numbers++;
		else if (str[i] == 'f')
			fs++;
		else if (str[i] == '.')
			dots++;
		else
			return (false);
	}
	if (fs == 1 && numbers > 0 && dots < 2)
	{
		if (str[str.find('.') + 1] < '0' || str[str.find('.') + 1] > '9')
			return (false);
		else
			return (true);
	}
	return (false);
}

static bool isDouble(std::string str)
{
	int	dots = 0, numbers = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			continue;
		else if (std::isdigit(str[i]))
			numbers++;
		else if (str[i] == '.')
			dots++;
		else
			return (false);
	}
	if (numbers > 0 && dots < 2)
	{
		if (str[str.find('.') + 1] < '0' || str[str.find('.') + 1] > '9')
			return (false);
		else
			return (true);
	}
	return (false);
}


static TYPE getType(std::string str)
{
	std::string	s_types[] = {"+inff", "-inff", "nanf", "+inf", "-inf", "nan"};
	TYPE		types[] = {_P_INFF, _N_INFF, _NANF, _P_INF, _N_INF, _NAN};
	
	for (size_t i = 0; i < 6; i++)
	{
		if (!str.compare(s_types[i]))
			return (types[i]);
	}
	if (isChar(str))
		return (_CHAR);
	if (isInteger(str))
		return (_INT);
	if (isFloat(str))
		return (_FLOAT);
	if (isDouble(str))
		return (_DOUBLE);
	return (INVALID);
}

void doChar(std::string str)
{
	char c;
	if (str.size() == 1)
		c = static_cast<char>(str[0]);
	else
		c = static_cast<char>(str[1]);
	std::cout << "Char: " << "'" << c << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;

}

void doInteger(std::string str)
{
	long double number = std::strtold(str.c_str(), NULL);

	std::cout << "Char: ";
	if (number > std::numeric_limits<char>::max() || number < std::numeric_limits<char>::min() || !std::isprint(number))
		std::cout << "Non displayable.\n";
	else
		std::cout << "\'" <<  static_cast<char>(number) << "\'" << std::endl;
	std::cout << "Int: ";
	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		std::cout << "overflow.\n";
	else
		std::cout << static_cast<int>(number) << std::endl;
		
	std::cout << "Float: ";
	if (number > std::numeric_limits<float>::max() || number < -std::numeric_limits<float>::max())
		std::cout << "overflow.\n";
	else
	{
		if (static_cast<float>(number) <= 999999)
			std::cout << static_cast<float>(number) << ".0f" << std::endl;
		else
			std::cout << static_cast<float>(number) << "f" << std::endl;
	}
		
	std::cout << "Double: ";
	if (number > std::numeric_limits<double>::max() || number < -std::numeric_limits<double>::max())
		std::cout << "overflow.\n";
	else
	{
		if (static_cast<double>(number) <= 999999)
			std::cout << static_cast<double>(number) << ".0" << std::endl;
		else
			std::cout << static_cast<double>(number) << std::endl;
	}	
}

void doFloat(std::string str)
{

	long double number = std::strtold(str.c_str(), NULL);
	float	f_nbr = std::strtof(str.c_str(), NULL);

	std::cout << "Char: ";
	if (number > std::numeric_limits<char>::max() || number < std::numeric_limits<char>::min() || !std::isprint(number))
		std::cout << "Non displayable.\n";
	else
		std::cout << "\'" <<  static_cast<char>(f_nbr) << "\'" << std::endl;
	std::cout << "Int: ";
	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		std::cout << "overflow.\n";
	else
		std::cout << static_cast<int>(f_nbr) << std::endl;
		
	std::cout << "Float: ";
	if (number > std::numeric_limits<float>::max() || number < -std::numeric_limits<float>::max())
		std::cout << "overflow.\n";
	else
	{
		if (f_nbr - static_cast<int>(f_nbr) == 0)
			std::cout << static_cast<float>(f_nbr) << ".0f" << std::endl;
		else
			std::cout << static_cast<float>(f_nbr) << "f" << std::endl;
	}
		
	std::cout << "Double: ";
	if (number > std::numeric_limits<double>::max() || number < -std::numeric_limits<double>::max())
		std::cout << "overflow.\n";
	else
	{
		if (static_cast<double>(f_nbr) -  static_cast<int>(f_nbr) == 0)
			std::cout << static_cast<double>(f_nbr) << ".0" << std::endl;
		else
			std::cout << static_cast<double>(f_nbr) << std::endl;
	}	
}

void doDouble(std::string str)
{

	long double number = std::strtold(str.c_str(), NULL);
	double	d_nbr = std::strtod(str.c_str(), NULL);

	std::cout << "Char: ";
	if (number > std::numeric_limits<char>::max() || number < std::numeric_limits<char>::min() || !std::isprint(number))
		std::cout << "Non displayable.\n";
	else
		std::cout << "\'" <<  static_cast<char>(d_nbr) << "\'" << std::endl;
	std::cout << "Int: ";
	if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
		std::cout << "overflow.\n";
	else
		std::cout << static_cast<int>(d_nbr) << std::endl;
		
	std::cout << "Float: ";
	if (number > std::numeric_limits<float>::max() || number < -std::numeric_limits<float>::max())
		std::cout << "overflow.\n";
	else
	{
		if (d_nbr - static_cast<int>(d_nbr) == 0)
			std::cout << static_cast<float>(d_nbr) << ".0f" << std::endl;
		else
			std::cout << static_cast<float>(d_nbr) << "f" << std::endl;
	}
		
	std::cout << "Double: ";
	if (number > std::numeric_limits<double>::max() || number < -std::numeric_limits<double>::max())
		std::cout << "overflow.\n";
	else
	{
		if (static_cast<double>(d_nbr) -  static_cast<int>(d_nbr) == 0)
			std::cout << static_cast<double>(d_nbr) << ".0" << std::endl;
		else
			std::cout << static_cast<double>(d_nbr) << std::endl;
	}	
}

void	doPInff(std::string)
{
	std::cout << "Char: not possible" << std::endl;
	std::cout << "Int: not possible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "Char: +inf" << std::endl;
}

void	doNInff(std::string)
{
	std::cout << "Char: not possible" << std::endl;
	std::cout << "Int: not possible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "Char: -inf" << std::endl;
}

void	doNanf(std::string)
{
	std::cout << "Char: not possible" << std::endl;
	std::cout << "Int: not possible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "Char: nan" << std::endl;
}

void	doPInf(std::string)
{
	std::cout << "Char: not possible" << std::endl;
	std::cout << "Int: not possible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "Char: +inf" << std::endl;
}

void	doNInf(std::string)
{
	std::cout << "Char: not possible" << std::endl;
	std::cout << "Int: not possible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "Char: -inf" << std::endl;
}

void	doNan(std::string)
{
	std::cout << "Char: not possible" << std::endl;
	std::cout << "Int: not possible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "Char: nan" << std::endl;
}


void doConversion(std::string str, TYPE type)
{

	typedef void (*ConversionFunction)(std::string);
	ConversionFunction conversionFunctions[] = {
		&doChar,
		&doInteger,
		&doFloat,
		&doDouble,
		&doPInff,
		&doNInff,
		&doNanf,
		&doPInf,
		&doNInff,
		&doNan
	};
	for (int i = 0; i < 10; i++)
	{
		if (type == i)
			conversionFunctions[i](str);
	}
	
}

void ScalarConverter::convert(std::string str)
{
	TYPE type = getType(str);
	if (type == INVALID)
		throw ScalarConverter::ImpossibleConversion();
	doConversion(str, type);
}