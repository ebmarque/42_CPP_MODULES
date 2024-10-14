/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:01:12 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/22 17:19:47 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <stdbool.h>
#include <cctype>
#include "Fixed.hpp"


class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	~Point();

	Point(const float a, const float b);
	Point(const Point &ref);

	Point &operator=(const Point &ref);

	bool operator==(const Point &ref) const;
	bool operator!=(const Point &ref) const;

	Fixed getX(void) const;
	Fixed getY(void) const;
	void setX(const Fixed &value);
	void setY(const Fixed &value);
};

#endif