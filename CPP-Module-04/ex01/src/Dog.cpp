/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:56:57 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 20:05:40 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::~Dog()
{
	print("[DOG]: Deleted.", BRIGHT_BLUE);
	delete this->_brain;
}

Dog::Dog() : Animal()
{
	print("[DOG]: Default constructor called.", BRIGHT_BLUE);
	this->type = "DOG";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& ref)
{
	print("[DOG]: Copy constructor called.", BRIGHT_BLUE);
	*this = ref;
}

Dog& Dog::operator=(const Dog& ref)
{
	print("[DOG]: Copy assignment operator called.", BRIGHT_BLUE);
	if (this != &ref)
	{
		this->type = ref.type;
		this->_brain = new Brain(*ref._brain);
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	print("[DOG]: AUF AUF!", BRIGHT_YELLOW);
}