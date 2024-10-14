/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:37:12 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/12 17:29:36 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon()

{
}
Weapon::Weapon(std::string new_type)
{
	this->setType(new_type);
}

const std::string &Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

