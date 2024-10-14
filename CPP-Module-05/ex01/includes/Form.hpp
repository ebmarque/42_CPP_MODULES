/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:14:30 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/09 20:36:30 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_execute;
		
	public:
		Form(const std::string name, const int grade_sign, const int grade_execute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExecute(void) const;

		void		beSigned(Bureaucrat &ref);
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

};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );


#endif