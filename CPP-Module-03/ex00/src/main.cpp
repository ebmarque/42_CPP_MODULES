/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:41:37 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/11 13:42:17 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Little-Dogo");
	a.status();
	a.attack("Boring cat");
	a.takeDamage(5);
	a.beRepaired(3);
	a.status();
	return 0;
}
