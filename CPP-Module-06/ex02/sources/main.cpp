/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:03:46 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/13 20:34:42 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/Base.hpp"
#include "../includes/C.hpp"
#include <cmath>
#include <time.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */

// Rest of the code...

Base * generate(void)
{
	int	i = rand() % 3;
	switch (i)
	{
		case 0:
			return (new A);
			break;
		
		case 1:
			return (new B);
			break;
		
		case 2:
			return (new C);
			break;
		
		default:
			break;
	}
	return (NULL);
}

void	printType(char type)
{
	std::cout << CYAN << "the Base pointer type is: " << type << RESET << std::endl;
}

void identify(Base* p)
{
	std::cout << YELLOW << "Using the Base *p -> " << RESET;
	if (dynamic_cast<A *>(p))
		printType('A');
	else if (dynamic_cast<B *>(p))
		printType('B');
	else if (dynamic_cast<C *>(p))
		printType('C');
}

void identify(Base& p)
{
	std::cout << YELLOW << "Using the Base &p -> " << RESET;

	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)(a);
		printType('A');
	}
	catch(const std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)(b);
			printType('B');
		}
		catch(const std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)(c);
				printType('C');
			}
			catch(const std::exception &e)
			{
				std::cerr << RED << e.what() << '\n' << RESET;
			}
		}
	}
}

int main(void)
{	
	srand(time(NULL));
	std::cout << GREEN;
	Base* ptr = generate();
	Base& ref = *ptr;
	std::cout << RESET;
	identify(ptr);
	identify(ref);

	delete ptr;
	return (0);
}