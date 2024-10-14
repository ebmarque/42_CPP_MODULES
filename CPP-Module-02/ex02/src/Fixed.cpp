/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:52:52 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/07 16:02:40 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

void print_msg(std::string str)
{
	std::cout << str << std::endl;
}

Fixed::Fixed()
{
	// print_msg("Default constructor called");
	this->point_value = 0;
}

Fixed::Fixed(const Fixed &point)
{
	// print_msg("Copy constructor called");
	this->setRawBits(point.getRawBits());
}

Fixed::Fixed(const int value)
{
	// print_msg("Int constructor called");
	this->point_value = value << fraction_part;
}

Fixed::Fixed(const float value)
{
	// print_msg("Float constructor called");
	this->point_value = roundf(value * (1 << fraction_part));
}

Fixed &Fixed::operator=(const Fixed &point)
{
	this->point_value = point.getRawBits();
	if (this != &point)
		this->point_value = point.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}

Fixed::~Fixed()
{
	// print_msg("Destructor called");
}

int Fixed::getRawBits(void) const
{
	// print_msg("getRawBits member function called");
	return this->point_value;
}

void Fixed::setRawBits(int const raw)
{
	// print_msg("setRawBits member function called");
	this->point_value = raw;
}

int Fixed::toInt(void) const
{
	return (this->point_value >> fraction_part);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits())) / (1 << this->fraction_part);
}

/* ------------------------ COMPARISON ------------------------ */

bool Fixed::operator>(const Fixed &point) const
{
	return this->getRawBits() > point.getRawBits();
}

bool Fixed::operator<(const Fixed &point) const
{
	return this->getRawBits() < point.getRawBits();
}

bool Fixed::operator>=(const Fixed &point) const
{
	return this->getRawBits() >= point.getRawBits();
}

bool Fixed::operator<=(const Fixed &point) const
{
	return this->getRawBits() <= point.getRawBits();
}

bool Fixed::operator==(const Fixed &point) const
{
	return this->getRawBits() == point.getRawBits();
}

bool Fixed::operator!=(const Fixed &point) const
{
	return this->getRawBits() != point.getRawBits();
}

/* ------------------------------------------------------------ */

/* ------------------------ ARITHMETIC ----------------------- */

Fixed Fixed::operator+(const Fixed &point) const
{
	return this->toFloat() + point.toFloat();
}

Fixed Fixed::operator-(const Fixed &point) const
{
	return this->toFloat() - point.toFloat();
}

Fixed Fixed::operator*(const Fixed &point) const
{
	return this->toFloat() * point.toFloat();
}

Fixed Fixed::operator/(const Fixed &point) const
{
	return this->toFloat() / point.toFloat();
}

/* ------------------------------------------------------------ */

/* --------------- Increment/Decrement operators -------------- */

Fixed &Fixed::operator++(void)
{
	++this->point_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp.point_value = this->point_value++;
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	--this->point_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp.point_value = this->point_value--;
	return tmp;
}

/* ------------------------------------------------------------ */

Fixed& Fixed::min(Fixed &point_1, Fixed &point_2)
{
	if (point_1.getRawBits() < point_2.getRawBits())
		return point_1;
	return point_2;
}

const Fixed& Fixed::min(const Fixed &point_1, const Fixed &point_2)
{
	if (point_1.getRawBits() < point_2.getRawBits())
		return point_1;
	return point_2;
}

Fixed& Fixed::max(Fixed &point_1, Fixed &point_2)
{
	if (point_1.getRawBits() > point_2.getRawBits())
		return point_1;
	return point_2;
}

const Fixed& Fixed::max(const Fixed &point_1, const Fixed &point_2)
{
	if (point_1.getRawBits() > point_2.getRawBits())
		return point_1;
	return point_2;
}