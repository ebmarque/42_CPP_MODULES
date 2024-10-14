/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:44:41 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/06 17:45:29 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_H
#define Fixed_H

#include <iostream>
#include <string>
#include <cmath>
#include <stdbool.h>

class Fixed
{
private:
	int point_value;
	static const int fraction_part = 8;

public:
	Fixed();
	~Fixed();

	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &point);

	// OPERATOR OVERLOADING
	Fixed &operator=(const Fixed &point);

	// INCREMENT DECREMENT OPERATOR OVERLOADING
	Fixed &operator++(void); // PREFIX
	Fixed operator++(int);	 // POSTFIX
	Fixed &operator--(void); // PREFIX
	Fixed operator--(int);	 // POSTFIX

	// ARITHMETIC OPERATOR OVERLOADING
	Fixed operator+(const Fixed &point) const;
	Fixed operator-(const Fixed &point) const;
	Fixed operator*(const Fixed &point) const;
	Fixed operator/(const Fixed &point) const;

	// COMPARISON
	bool operator>(const Fixed &point) const;
	bool operator<(const Fixed &point) const;
	bool operator>=(const Fixed &point) const;
	bool operator<=(const Fixed &point) const;
	bool operator==(const Fixed &point) const;
	bool operator!=(const Fixed &point) const;

	// PUBLIC METHODS
	int getRawBits(void) const;
	int toInt(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;

	static Fixed &min(Fixed &point_1, Fixed &point_2);
	static const Fixed &min(const Fixed &point_1, const Fixed &point_2);
	static Fixed &max(Fixed &point_1, Fixed &point_2);
	static const Fixed &max(const Fixed &point_1, const Fixed &point_2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif