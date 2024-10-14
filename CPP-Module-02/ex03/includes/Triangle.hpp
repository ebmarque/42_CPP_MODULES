/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:00:38 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/08 18:55:46 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "Point.hpp"

class Triangle
{
private:
	Point vertice_1;
	Point vertice_2;
	Point vertice_3;

public:
	Triangle();
	Triangle(const Triangle &ref);
	Triangle(const Point &a, const Point &b, const Point &c);
	Triangle &operator=(const Triangle &ref);
	~Triangle();

	Fixed area(void);
	Fixed abs(Fixed value) const;
};

#endif