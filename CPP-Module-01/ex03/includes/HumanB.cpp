/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:10:20 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/13 14:52:50 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string new_name)
{
	this->name = new_name;
	this->gun = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (!this->gun)
	{
		std::cout << this->name << ": I am unarmed. :(" << std::endl;
		return ;
	}
	std::cout << this->name
			  << " attacks with their "
			  << this->gun->getType()
			  << std::endl;
}

void HumanB::setWeapon(Weapon &new_gun)
{
	this->gun = &new_gun;
}
