/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:59:09 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/26 15:03:15 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "[ScavTrap]: Default constructor called." << std::endl;
	this->health = 100;
	this->energy = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref)
{
	std::cout << "[ScavTrap]: Copy constructor called." << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << "[ScavTrap]: Copy assignment operator called." << std::endl;
	if (this != &ref)
		this->ClapTrap::operator=(ref);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap]: " << this->name << " destructed." << std::endl << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
	this->health = 100;
	this->energy = 50;
	this->attack_damage = 20;
	std::cout << "[ScavTrap]: " << this->name << " created!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap]: " << this->name 
			  << " is now in Gate keeper mode." 
			  << std::endl
			  << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->health == 0)
	{
		std::cout << "[ScavTrap]: " << this->name 
				  << " is dead" << std::endl << std::endl;
	}
	else if (this->energy > 0)
	{
		std::cout << "[ScavTrap]: " << this->name
				<< " attacks " << target << ", causing "
				<< this->attack_damage << " point(s) of damage!"
				<< std::endl << std::endl;
		this->energy--;
	}
	else {
		std::cout << "[ScavTrap]: " << this->name << " has no energy points left!" 
				  << std::endl << std::endl;	
	}
}