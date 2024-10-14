/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:26:10 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/09 16:10:20 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() 
{
	log(GREEN, "Intern object created.");
}

Intern::Intern(const Intern& other)
{
	(void)other;
	log(GREEN, "Intern copy constructor called.");
}

Intern& Intern::operator=(const Intern& other) 
{
	(void)other;
	log(GREEN, "Intern copy assignment operator called.");
	return (*this);
}

Intern::~Intern() 
{
	log(RED, "Intern object destroyed.");
}

AForm* Intern::makePresidential(std::string target) const 
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomy(std::string target) const 
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubbery(std::string target) const 
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formType, std::string target) const
{
	std::string types[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};	
	AForm* (Intern::*factory[3])(std::string fileName) const = {
		&Intern::makePresidential,
		&Intern::makeRobotomy,
		&Intern::makeShrubbery,
	};

	for (int i = 0; i < 3; i++)
	{
		if (!types[i].compare(formType))
		{
			log(BLUE, "Intern will create: " + types[i] + "form, tageted to " + target);
			return ((this->*factory[i])(target));
		}
	}

		throw Intern::noFormTypeEncountered();	
}

