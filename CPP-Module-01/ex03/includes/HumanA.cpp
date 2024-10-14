/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:02:27 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/12 17:47:33 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_gun) : name(new_name), gun(new_gun){
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->name 
			  << " attacks with their " 
			  << this->gun.getType() 
			  << std::endl;
}
