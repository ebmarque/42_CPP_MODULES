/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:35:29 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 17:35:43 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Undefined";
	print("[WRONGANIMAL]: Default constructor called.", BRIGHT_GREEN);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	print("[WRONGANIMAL]: Copy assignment operator called.", BRIGHT_GREEN);
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	print("[WRONGANIMAL]: Copy constructor called.", BRIGHT_GREEN);
	*this = ref;
}

WrongAnimal::~WrongAnimal()
{
	print("[WRONGANIMAL]: Deleted.", BRIGHT_GREEN);
}

void	WrongAnimal::makeSound(void) const
{
	print("[WRONGANIMAL]: Making indistinguishable sound.", BRIGHT_YELLOW);
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}