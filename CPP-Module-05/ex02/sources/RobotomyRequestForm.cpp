/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:45:51 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 18:25:45 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	log(GREEN, this->getName() + " Created.");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	this->_target = other._target;
	log(GREEN, this->getName() + " Created by copy constructor.");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
	if (this != &other) 
		this->_target = other._target;
	log(GREEN, this->getName() + " Created by copy assignment operator.");
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	log(RED, this->getName() + " Destroyed.");
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	log(CYAN, this->getName() + " Execute method called.");
	std::cout << MAGENTA << "Robotomy execution LOUD noises..." << RESET << std::endl;
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	static int i = 0;
	if ((i % 2) == 0)
		log(YELLOW, this->_target + " has been robotomized successfully.");
	else
		log(RED, this->_target + " robotomy has failed.");
	i++;
}