/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:08:35 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/10 12:26:39 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << CYAN << "\n\n----------> TEST 1 decrement until grade above 150 <-----------\n"
				  << RESET;
		Bureaucrat test1("Bene", 1);
		std::cout << YELLOW \
				  << "\n\noverload of \"<<\" for Bureaucrat class: " \
				  << test1 << RESET << std::endl << std::endl;


		for (size_t i = 0; i < 200; i++)
		{
			test1.decrement();
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n\n----------> TEST 2 increment until grade bellow 1 <-----------\n"
				  << RESET;
		Bureaucrat test2("Johnny", 150);
		for (size_t i = 0; i < 158; i++)
		{
			test2.increment();
		}
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	/*In C++, objects are automatically destroyed when they go out of scope. 
	In the case of `test3` and `test4`, they are created within the `try` blocks. 
	If an exception is thrown during the construction of these objects, as the grades 
	are outside the valid range, 
	the constructor will not complete and the object will not be fully formed. 
	As a result, the destructor will not be called for these partially-formed objects.

	However, any resources that were successfully acquired during the part of the 
	constructor that did execute will be properly released. This is because C++ guarantees 
	that if an exception is thrown during the execution of a constructor, 
	all the objects that were fully constructed at the point the exception was thrown will 
	have their destructors called. This is part of the C++ exception safety guarantee.

	In summary, `test3` and `test4` are not destroyed because they were never fully c
	onstructed due to the exceptions thrown in their constructors.*/
	
	try
	{
		std::cout << CYAN << "\n\n----------> TEST 3 instanciate with grade bellow 1 <-----------\n"
				  << RESET;
		Bureaucrat test3("Tiago", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n\n----------> TEST 4 instanciate with grade above 150 <-----------\n"
				  << RESET;
		Bureaucrat test4("Bilu", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
