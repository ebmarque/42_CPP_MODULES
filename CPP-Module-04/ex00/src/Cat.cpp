/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:43:00 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 17:19:00 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::~Cat()
{
	print("[CAT]: Deleted.", BRIGHT_RED);
}

Cat::Cat() : Animal()
{
	print("[CAT]: Default constructor called.", BRIGHT_RED);
	this->type = "Cat";
}

Cat::Cat(const Cat& ref)
{
	print("[CAT]: Copy constructor called.", BRIGHT_RED);
	*this = ref;
}

Cat& Cat::operator=(const Cat& ref)
{
	print("[CAT]: Copy assignment operator called.", BRIGHT_RED);
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

void Cat::makeSound(void) const
{

	print("[CAT]: Meow!", BRIGHT_YELLOW);
}
