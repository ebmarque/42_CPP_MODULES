/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:38:12 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/26 14:33:18 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int health;
	int attack_damage;
	int energy;

public:
	ClapTrap();
	ClapTrap(std::string n);
	ClapTrap(const ClapTrap &ref);
	ClapTrap &operator=(const ClapTrap &ref);
	~ClapTrap();

	std::string	getName(void) const;
	int			getHealth(void) const;
	int			getAttackDamage(void) const;
	int			getEnergy(void) const;
	void 		attack(const std::string &target);
	void 		takeDamage(unsigned int amount);
	void 		beRepaired(unsigned int amount);
	void 		status(void);
};

#endif