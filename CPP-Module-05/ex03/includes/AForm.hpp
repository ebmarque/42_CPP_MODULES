/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:14:30 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 18:05:07 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_execute;
		
	public:
		AForm(const std::string name, const int grade_sign, const int grade_execute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeSign(void) const;
		int				getGradeExecute(void) const;

		void			beSigned(Bureaucrat &ref);
		virtual void	execute(Bureaucrat const &executor) const = 0;

	/*------------------------------> EXCEPTION CLASSES <----------------------------------*/
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw() {return "Grade too high execption.";}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw() {return "Grade too low execption.";}
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw() {return "Form not signed exception.";}
	};

};

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );


#endif