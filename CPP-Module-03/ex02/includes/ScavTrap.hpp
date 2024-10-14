/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:43:20 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/15 14:07:41 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string n);
	ScavTrap(const ScavTrap &ref);
	ScavTrap &operator=(const ScavTrap &ref);
	void guardGate(void);
	void attack(const std::string &target);
};

#endif