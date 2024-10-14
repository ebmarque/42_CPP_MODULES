/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:01:26 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 17:20:17 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

void	print(std::string text, std::string color)
{
	std::cout << color << text << RESET << std::endl;
}

Animal::Animal()
{
	this->type = "Undefined";
	print("[ANIMAL]: Default constructor called.", BRIGHT_GREEN);
}

Animal& Animal::operator=(const Animal& ref)
{
	print("[ANIMAL]: Copy assignment operator called.", BRIGHT_GREEN);
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

Animal::Animal(const Animal& ref)
{
	print("[ANIMAL]: Copy constructor called.", BRIGHT_GREEN);
	*this = ref;
}

Animal::~Animal()
{
	print("[ANIMAL]: Deleted.", BRIGHT_GREEN);
}

void	Animal::makeSound(void) const
{
	print("[ANIMAL]: Making indistinguishable sound.", BRIGHT_YELLOW);
}

std::string Animal::getType(void) const
{
	return this->type;
}