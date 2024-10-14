/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:08:35 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/09 20:41:32 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	std::cout << CYAN << "\n\n----------> TEST 1 Instanciating an object with grade to sign < 1 <-----------\n" \
			  << RESET;
	try
	{
		Form form1("Fomr 1", 0, 1);
		// Bureaucrat bene("Bene", 65);
		// bene.signForm(form1);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n\n----------> TEST 2 Instanciating an object with grade to sign > 150 <-----------\n" \
			  << RESET;
	try
	{
		Form form2("Form2", 151, 1);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n\n----------> TEST 3 Instanciating an object with grade to execute < 1 <-----------\n" \
			  << RESET;
	try
	{
		Form form3("Form3", 1, 0);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n\n----------> TEST 4 Instanciating an object with grade to execute > 150 <-----------\n" \
			  << RESET;
	try
	{
		Form form4("Form4", 1, 151);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << CYAN << "\n\n----------> TEST 5 Bureaucrat that doesn't meet the grade requirement <-----------\n" \
			  << RESET;
	try
	{
		Form form5("Form5", 30, 120);
		Bureaucrat saitama("Saitama", 45);
		
		std::cout << YELLOW << saitama << RESET;
		std::cout << YELLOW << form5 << RESET;

		form5.beSigned(saitama);
		
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	/* std::cout << CYAN << "\n\n----------> TEST 1 Instanciating an object with grade < 1 <-----------\n" \
			  << RESET;
	try
	{
		Form form1("Ficha 1", 0, 1);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << GREEN << "[OK] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << "[KO] " << RESET;
		std::cerr << "Exception caught: " << e.what() << std::endl;
	} */
	return (0);
}
