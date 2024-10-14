/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:07:12 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/22 17:19:16 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point()
{
}

Point::Point(const float a, const float b)
{
	this->setX(Fixed(a).toFloat());
	this->setY(Fixed(b).toFloat());
}

Point::~Point()
{
}

Point::Point(const Point &ref)
{
	this->setX(ref.getX());
	this->setY(ref.getY());
}

Point &Point::operator=(const Point &ref)
{
	if (this != &ref)
	{
		this->setX(ref.getX());
		this->setY(ref.getY());
	}
	return *this;
}

bool Point::operator==(const Point &ref) const
{
	return this->getX() == ref.getX() && this->getY() == ref.getY();
}

bool Point::operator!=(const Point &ref) const
{
	return !(*this == ref);
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}

void Point::setX(const Fixed &value)
{
	const_cast<Fixed&>(this->x) = value;
}

void Point::setY(const Fixed &value)
{
	const_cast<Fixed&>(this->y) = value;
}
