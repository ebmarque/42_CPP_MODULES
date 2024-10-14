/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:08:01 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/08 17:56:01 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cmath>

#include "AForm.hpp"

// ASCII color codes
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int 				grade;
		Bureaucrat();

	public:
		~Bureaucrat();
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increment(void);
		void		decrement(void);
		void		signForm(AForm &form);
		void		executeForm(AForm const &form);
		
		/* ---------------- Exception Classes ---------------- */
		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw() {return "Grade too high execption: grade < 1";}
		};
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw() {return "Grade too low execption: grade > 150";}
		};
};

inline void	log(const char *color, std::string text)
{
	std::cout << color << text << RESET << std::endl;
}
std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );


#endif