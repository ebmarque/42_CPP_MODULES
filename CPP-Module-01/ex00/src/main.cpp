/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:52:58 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/29 15:07:12 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *fresh_zombie = new Zombie(name);
	return (fresh_zombie);
}

void randomChump(std::string name)
{
	Zombie *random = newZombie(name);
	random->announce();
	delete random;
}

int main(void)
{
	randomChump("Foo");
	return (0);
}


