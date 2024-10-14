/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:01:26 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 17:20:17 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

void	print(std::string text, std::string color)
{
	std::cout << color << text << RESET << std::endl;
}

AAnimal::AAnimal()
{
	this->type = "Undefined";
	print("[AANIMAL]: Default constructor called.", BRIGHT_GREEN);
}

AAnimal& AAnimal::operator=(const AAnimal& ref)
{
	print("[AANIMAL]: Copy assignment operator called.", BRIGHT_GREEN);
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

AAnimal::AAnimal(const AAnimal& ref)
{
	print("[AANIMAL]: Copy constructor called.", BRIGHT_GREEN);
	*this = ref;
}

AAnimal::~AAnimal()
{
	print("[AANIMAL]: Deleted.", BRIGHT_GREEN);
}


std::string AAnimal::getType(void) const
{
	return this->type;
}