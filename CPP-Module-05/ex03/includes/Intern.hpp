/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:19:02 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/09 16:11:09 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

	public:
	
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		
		AForm	*makeForm(std::string formType, std::string target) const;
		AForm	*makePresidential(std::string target) const;
		AForm	*makeRobotomy(std::string target) const;
		AForm	*makeShrubbery(std::string target) const;
	class noFormTypeEncountered : public std::exception
	{
		public:
			virtual const char *what() const throw() { return ("No Form type was encountered with the provided name.");}
	};
};


#endif // INTERN_HPP