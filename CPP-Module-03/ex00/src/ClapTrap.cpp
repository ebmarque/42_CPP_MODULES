/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:58:30 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/13 17:16:09 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap created with default constructor!"
			<< std::endl
			<< std::endl;
	this->name = "Random";
	this->health = 10;
	this->energy = 10;
	this->attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap vanished!"
			<< std::endl
			<< std::endl;
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout << "ClapTrap: " << n << " created!"
			<< std::endl
			<< std::endl;
	this->name = n;
	this->health = 10;
	this->energy = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	this->name = ref.name;
	this->energy = ref.energy;
	this->health = ref.health;
	this->attack_damage = ref.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	if (this != &ref)
	{
		this->name = ref.name;
		this->energy = ref.energy;
		this->health = ref.health;
		this->attack_damage = ref.attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->health == 0)
	{
		std::cout << "ClapTrap " << this->name 
				  << " is dead" << std::endl << std::endl;
	}
	else if (this->energy > 0)
	{
		std::cout << "ClapTrap " << this->name
				<< " attacks " << target << ", causing "
				<< this->attack_damage << " point(s) of damage!"
				<< std::endl << std::endl;
		this->energy--;
	}
	else {
		std::cout << this->name << " has no energy points left!" 
				  << std::endl << std::endl;	
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->health < 10 && this->health > 0)
	{
		std::cout << "ClapTrap " << this->name
				<< " repairs itself " << amount << " health points!"
				<< std::endl << std::endl;
		if (this->health + amount > 10)
				this->health = 10;
		else
			this->health += amount;
		this->energy--;
	}
	else if (this->energy == 0)
	{
		std::cout << "ClapTrap " << this->name 
				  << " has no energy points left!" << std::endl << std::endl;
	}
	else if (this->health == 0)
	{
		std::cout << "ClapTrap " << this->name 
				  << " can't be repaired" << std::endl << std::endl;
	}
	else{
		std::cout << "ClapTrap " << this->name 
				  << " health is full [10]" << std::endl << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health > 0)
	{
		if ((this->health - (int)amount) < 0)
		{
			std::cout << "ClapTrap " << this->name 
				  << " died!" << std::endl << std::endl;
			this->health = 0;
		}
		else
		{
			std::cout << "ClapTrap " << this->name
				<< " suffered " << amount << " points of health demage!"
				<< std::endl << std::endl;
			this->health -= amount;
		}
	}
	else {
		std::cout << "ClapTrap " << this->name 
				  << " is already dead!" << std::endl << std::endl;
	}
}

void	ClapTrap::status(void)
{
	std::cout << "name: " << this->name << std::endl;
	std::cout << "health: " << this->health << std::endl;
	std::cout << "energy: " << this->energy << std::endl;
	std::cout << "attack damage: " << this->attack_damage << std::endl << std::endl;
}