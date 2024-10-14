/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:46:04 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/08 18:55:51 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Triangle.hpp"

Triangle::Triangle()
{
	this->vertice_3 = Point();
	this->vertice_2 = Point();
	this->vertice_3 = Point();
}

Triangle::Triangle(const Point &a, const Point &b, const Point &c)
{
	this->vertice_1 = a;
	this->vertice_2 = b;
	this->vertice_3 = c;
}

Triangle::Triangle(const Triangle &ref)
{
	this->vertice_1 = ref.vertice_1;
	this->vertice_2 = ref.vertice_2;
	this->vertice_3 = ref.vertice_3;
}

Triangle &Triangle::operator=(const Triangle &ref)
{
	this->vertice_1 = ref.vertice_1;
	this->vertice_2 = ref.vertice_2;
	this->vertice_3 = ref.vertice_3;
	return (*this);
}

Triangle::~Triangle()
{
}

Fixed Triangle::area(void)
{
	return (abs(((vertice_1.getX() * (vertice_2.getY() - vertice_3.getY())) +
			 (vertice_2.getX() * (vertice_3.getY() - vertice_1.getY())) +
			 (vertice_3.getX() * (vertice_1.getY() - vertice_2.getY()))) /
			2));
}

Fixed Triangle::abs(Fixed value) const
{
	if (value < 0)
		return (value * -1);
	return value;
}