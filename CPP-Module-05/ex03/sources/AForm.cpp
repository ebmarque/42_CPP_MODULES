/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:17:53 by ebmarque          #+#    #+#             */
/*   Updated: 2024/10/14 11:19:33 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

std::ostream& operator<<(std::ostream &o, const AForm& form)
{
	std::string signature = "Unsigned";
	if (form.getSigned() == true)
		signature = "Signed";
	o << "\nForm Name: " << form.getName() << std::endl \
	  << "Grade Required to sign: " << form.getGradeSign() << std::endl \
	  << "Grade Required to execute: " << form.getGradeExecute() << std::endl \
	  << "Signature: " << signature << std::endl;
	return (o);
}

AForm::AForm(const std::string name, const int grade_sign, const int grade_execute) : \
	_name(name), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	log(GREEN, "AForm Default constructor called.");
	this->_signed = false;
	if (this->_grade_sign < 1 || this->_grade_execute < 1)
		throw AForm::GradeTooHighException();
	if (this->_grade_sign > 150 || this->_grade_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)  : \
	_name(other._name), _grade_sign(other._grade_sign), _grade_execute(other._grade_execute)
{
	this->_signed = other._signed;
	log(GREEN, "AForm Copy constructor called.");
}

AForm& AForm::operator=(const AForm& other) 
{
	log(GREEN, "AForm Copy assignment operator called:");
	if (this != &other) 
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm() 
{
	std::cout << RED << this->getName() + " Destroyed." << RESET << std::endl;
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

int AForm::getGradeExecute(void) const
{
	return (this->_grade_execute);
}

int AForm::getGradeSign(void) const
{
	return (this->_grade_sign);
}

void AForm::beSigned(Bureaucrat &ref) 
{
	if (ref.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw Bureaucrat::GradeTooLowException();
	std::cout << BLUE << this->getName() + " got signed." << RESET << std::endl;
}
