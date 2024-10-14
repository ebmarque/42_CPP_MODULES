/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:05:54 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 18:05:45 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)  
{
	this->_target = target;
	log(GREEN, this->getName() + " Created.");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	this->_target = other._target;
	log(GREEN, this->getName() + " Created by copy constructor.");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) 
{
	if (this != &other) 
		this->_target = other._target;
	log(GREEN, this->getName() + " Created by copy assignment operator.");
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	log(RED, this->getName() + " Destroyed");
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	log(CYAN, this->getName() + " Execute method called.");
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	log(YELLOW, this->_target + " has been pardoned by Zaphod Beeblebrox.");
}
