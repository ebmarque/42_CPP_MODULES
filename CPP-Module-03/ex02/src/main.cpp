/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:41:37 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/12 12:11:51 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main(void)
{
	FragTrap a("Little-Dogo");
	a.status();
	a.attack("Boring cat");
	a.takeDamage(5);
	a.beRepaired(3);
	a.beRepaired(3);
	a.beRepaired(3);
	a.beRepaired(3);
	a.highFivesGuys();
	return 0;
}
