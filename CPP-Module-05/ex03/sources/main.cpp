/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:08:35 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 23:22:07 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	
    {
        Intern  someRandomIntern;
        Intern  test1;
        Intern  test2;
        
        try
        {
            someRandomIntern.makeForm("presidential pardon", "Bender");
            someRandomIntern.makeForm("Robotomy request", "Bender");
            someRandomIntern.makeForm("shrubbery creation", "Bender");
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "Excepetion caught: " << e.what() << RESET <<  '\n';
        }
    }
	return (0);
}
