/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:38:51 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 17:42:50 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/WrongCat.hpp"

WrongCat::~WrongCat()
{
	print("[WRONGCAT]: Deleted.", BRIGHT_RED);
}

WrongCat::WrongCat() : WrongAnimal()
{
	print("[WRONGCAT]: Default constructor called.", BRIGHT_RED);
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& ref)
{
	print("[WRONGCAT]: Copy constructor called.", BRIGHT_RED);
	*this = ref;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	print("[WRONGCAT]: Copy assignment operator called.", BRIGHT_RED);
	if (this != &ref)
		this->type = ref.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	print("[WRONGCAT]: Meow!", BRIGHT_YELLOW);
}
