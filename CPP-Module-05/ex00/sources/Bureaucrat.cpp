/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:54:08 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/10 12:29:12 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &o, const Bureaucrat &ref) 
{
	o << "Bureaucrat name: " << ref.getName() << ", bureaucrat grade " << ref.getGrade();
    return (o);
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade): name(_name)
{
	log(GREEN, "Bureaucrat constructor called.");
	this->grade = _grade;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << this->getName() + " CREATED." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	log(GREEN, "Bureaucrat copy called.");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	log(GREEN, "Bureaucrat copy assignment operator called.");
	if (this != &other) 
		this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() 
{
	log(RED, "Bureaucrat: " + this->name + " destroyed.");
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::increment(void) 
{
	this->grade -= 1;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrement(void) 
{
	this->grade  += 1;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
