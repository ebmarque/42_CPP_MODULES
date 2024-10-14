/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:17:53 by ebmarque          #+#    #+#             */
/*   Updated: 2024/10/14 11:18:53 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

std::ostream& operator<<(std::ostream &o, const Form& form)
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

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : \
	_name(name), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	log(GREEN, "Form Default constructor called.");
	this->_signed = false;
	if (this->_grade_sign < 1 || this->_grade_execute < 1)
		throw Form::GradeTooHighException();
	if (this->_grade_sign > 150 || this->_grade_execute > 150)
		throw Form::GradeTooLowException();
	std::cout << GREEN << this->getName() + " Created." << std::endl;
}

Form::Form(const Form& other)  : \
	_name(other._name), _grade_sign(other._grade_sign), _grade_execute(other._grade_execute)
{
	this->_signed = other._signed;
	log(GREEN, "Form Copy constructor called.");
}

Form& Form::operator=(const Form& other) 
{
	log(GREEN, "Form Copy assignment operator called:");
	if (this != &other) 
		this->_signed = other._signed;
	return (*this);
}

Form::~Form() 
{
	std::cout << RED << this->getName() + " Destroyed." << RESET << std::endl;
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

int Form::getGradeExecute(void) const
{
	return (this->_grade_execute);
}

int Form::getGradeSign(void) const
{
	return (this->_grade_sign);
}

void Form::beSigned(Bureaucrat &ref) 
{
	if (ref.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw Bureaucrat::GradeTooLowException();
	std::cout << BLUE << this->getName() + " got signed." << std::endl;
}