/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:35:30 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/22 14:00:51 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::~Cure()
{
	print("[CURE]: Deleted.", RED);
}

Cure::Cure(void) : AMateria("cure")
{
	print("[CURE]: Default constructor called.", BRIGHT_GREEN);
}

Cure::Cure(const Cure &ref)
{
	print("[CURE]: Copy constructor called.", BRIGHT_GREEN);
	*this = ref;
}

Cure &Cure::operator=(const Cure &ref)
{
	print("[CURE]: Copy assignment operator called.", BRIGHT_GREEN);
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}

AMateria* Cure::clone(void) const
{
	print("[CURE]: 'clone' Method called.", BRIGHT_GREEN);
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	print("[CURE]: * heals " + target.getName() + "'s wounds *", BRIGHT_CYAN);
}