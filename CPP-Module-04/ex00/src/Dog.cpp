/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:56:57 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 17:19:04 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::~Dog()
{
	print("[DOG]: Deleted.", BRIGHT_BLUE);
}

Dog::Dog() : Animal()
{
	print("[DOG]: Default constructor called.", BRIGHT_BLUE);
	this->type = "DOG";
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
		this->type = ref.type;
	return *this;
}

void	Dog::makeSound(void) const
{
	print("[DOG]: AUF AUF!", BRIGHT_YELLOW);
}