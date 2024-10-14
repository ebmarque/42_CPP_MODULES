/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:50:01 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/30 12:48:57 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BOLD "\033[1m";
# define UNDERLINE "\033[4m"

# define BRIGHT_BLACK "\033[90m"
# define BRIGHT_RED "\033[91m"
# define BRIGHT_GREEN "\033[92m"
# define BRIGHT_YELLOW "\033[93m"
# define BRIGHT_BLUE "\033[94m"
# define BRIGHT_MAGENTA "\033[95m"
# define BRIGHT_CYAN "\033[96m"
# define BRIGHT_WHITE "\033[97m"

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string type;
		bool		_taken;
	public:
		AMateria();
		AMateria(std::string const &t);
		AMateria(const AMateria& ref);
		AMateria& operator=(const AMateria& ref);


		std::string const &getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter &target);	
		virtual ~AMateria();
		bool	isTaken(void) const;
		void 	setTaken(bool value);

};

void print(std::string text, std::string COLOR);

#endif