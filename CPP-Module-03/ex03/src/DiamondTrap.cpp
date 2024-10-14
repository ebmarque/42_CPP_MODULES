/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:55:19 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/26 16:23:51 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "[DiamondTrap]: Default constructor called." << std::endl;

	ScavTrap scav;
	FragTrap frag;

	this->name = "Default";
	this->ClapTrap::name = this->name + "_clap_name";
	this->health = frag.getHealth();
	this->energy = scav.getEnergy();
	this->attack_damage = frag.getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref)
{
	std::cout << "[DiamondTrap]: Copy constructor called." << std::endl;
	name = ref.name;
	energy = ref.energy;
	health = ref.health;
	attack_damage = ref.attack_damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
	std::cout << "[DiamondTrap]: Copy assignment operator called." << std::endl;
	if (this != &ref)
	{
		name = ref.name;
		energy = ref.energy;
		health = ref.health;
		attack_damage = ref.attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap]: "
			  << this->name << " has been destroyed!"
			  << std::endl;
}

DiamondTrap::DiamondTrap(std::string n) : ClapTrap(n), ScavTrap(n), FragTrap(n)
{
	ScavTrap scav(n);
	FragTrap frag(n);

	this->name = n;
	this->ClapTrap::name = n + "_clap_name";
	this->health = frag.getHealth();
	this->energy = scav.getEnergy();
	this->attack_damage = frag.getAttackDamage();

	std::cout << "[DiamondTrap]: "
			  << this->name
			  << " has been created!"
			  << std::endl
			  << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am a DiamondTrap named "
			  << this->name
			  << ", ClapTrap name: "
			  << ClapTrap::name << std::endl
			  << std::endl;
}