/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:19:08 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/29 13:24:34 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Triangle.hpp"
#include "../includes/Point.hpp"

#define RESET_COLOR "\033[0m"
#define BOLD_RED "\033[1m\033[31m"
#define BOLD_WHITE "\033[1m\033[37m"

void _header(bool erase)
{
	if (erase)
		system("clear");
	std::cout << BOLD_RED
			  << "███████╗██╗██╗  ██╗███████╗██████╗    ██████╗  ██████╗ ██╗███╗   ██╗████████╗" << std::endl
			  << "██╔════╝██║╚██╗██╔╝██╔════╝██╔══██╗   ██╔══██╗██╔═══██╗██║████╗  ██║╚══██╔══╝" << std::endl
			  << "█████╗  ██║ ╚███╔╝ █████╗  ██║  ██║   ██████╔╝██║   ██║██║██╔██╗ ██║   ██║   " << std::endl
			  << "██╔══╝  ██║ ██╔██╗ ██╔══╝  ██║  ██║   ██╔═══╝ ██║   ██║██║██║╚██╗██║   ██║   " << std::endl
			  << "██║     ██║██╔╝ ██╗███████╗██████╔╝   ██║     ╚██████╔╝██║██║ ╚████║   ██║   " << std::endl
			  << "╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚═════╝    ╚═╝      ╚═════╝ ╚═╝╚═╝  ╚═══╝   ╚═╝   " << std::endl
			  << RESET_COLOR << std::endl
			  << std::endl
			  << std::endl
			  << std::endl;
}

bool isPointOnLine(const Point &a, const Point &b, const Point &point)
{
	// Calcula os vetores AB e AP
	float vectorAB_x = b.getX().toFloat() - a.getX().toFloat();
	float vectorAB_y = b.getY().toFloat() - a.getY().toFloat();

	float vectorAP_x = point.getX().toFloat() - a.getX().toFloat();
	float vectorAP_y = point.getY().toFloat() - a.getY().toFloat();

	// Calcula o produto vetorial
	float crossProduct = vectorAB_x * vectorAP_y - vectorAB_y * vectorAP_x;

	// Define uma tolerância para considerar valores muito próximos de zero
	const float tolerance = 1e-6; // Ou qualquer valor adequado

	// Se o valor absoluto do produto vetorial for menor que a tolerância, então os pontos estão na mesma linha
	return (std::fabs(crossProduct) < tolerance);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Triangle ABC(a, b, c);
	Triangle ABP(a, b, point);
	Triangle ACP(a, c, point);
	Triangle BCP(b, c, point);

	if (point == a || point == b || point == c)
		return (false);
	if (isPointOnLine(a, b, point) ||
		isPointOnLine(a, c, point) ||
		isPointOnLine(b, c, point))
		return (false);
	if (ABC.area() == (ABP.area() + ACP.area() + BCP.area()))
		return true;
	return false;
}

int main()
{
	// Test case 1: Points form a triangle, point lies inside the triangle
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 4);
	Point point(2, 2);
	bool result = bsp(a, b, c, point);
	std::cout << "Test case 1: " << (result ? "Passed" : "Failed <Point Outside>") << std::endl;
	
	// Test case 2: Points form a triangle, point lies outside the triangle
	Point a2(0, 0);
	Point b2(4, 0);
	Point c2(2, 4);
	Point point2(5, 5);
	bool result2 = bsp(a2, b2, c2, point2);
	std::cout << "Test case 2: " << (!result2 ? "Passed" : "Failed <Point Outside>") << std::endl;
	
	// Test case 3: Points form a line, point lies on the line
	Point a3(0, 0);
	Point b3(2, 2);
	Point c3(4, 4);
	Point point3(3, 3);
	bool result3 = bsp(a3, b3, c3, point3);
	std::cout << "Test case 3: " << (!result3 ? "Passed" : "Failed <Point Outside>") << std::endl;
	
	// Test case 4: Points form a line, point does not lie on the line
	Point a4(0, 0);
	Point b4(2, 2);
	Point c4(4, 4);
	Point point4(5, 5);
	bool result4 = bsp(a4, b4, c4, point4);
	std::cout << "Test case 4: " << (!result4 ? "Passed" : "Failed <Point Outside>") << std::endl;
	
	// Test case 5: Points form a triangle, point is one of the vertices
	Point a5(0, 0);
	Point b5(4, 0);
	Point c5(2, 4);
	Point point5(4, 0);
	bool result5 = bsp(a5, b5, c5, point5);
	std::cout << "Test case 5: " << (!result5 ? "Passed" : "Failed <Point Outside>") << std::endl;
	
	// Test case 6: Points form a triangle, point is on one of the edges
	Point a6(0, 0);
	Point b6(4, 0);
	Point c6(2, 4);
	Point point6(2, 0);
	bool result6 = bsp(a6, b6, c6, point6);
	std::cout << "Test case 6: " << (!result6 ? "Passed" : "Failed <Point Outside>") << std::endl;
	
	// Test case 6: Points form a triangle, point is on one of the edges
	Point a7(-3, 3);
	Point b7(2, -3);
	Point c7(-2, -3);
	Point point7(0, -2.9);
	bool result7 = bsp(a7, b7, c7, point7);
	std::cout << "Test case 7: " << (result7 ? "Passed" : "Failed <Point Outside>") << std::endl;
	return (0);
}