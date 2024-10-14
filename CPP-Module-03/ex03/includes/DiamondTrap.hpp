/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:53:01 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/15 14:08:40 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
		
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& ref);
		DiamondTrap& operator=(const DiamondTrap& ref);
		DiamondTrap(std::string n);
		~DiamondTrap();
		void whoAmI(void);
};

#endif