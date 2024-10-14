/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:41:37 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/26 15:23:26 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"     /* Red */
#define BLUE "\033[34m"    /* Blue */

int main(void)
{
    std::cout << BLUE << "FERNANDO CREATION\n"
              << RESET;
    DiamondTrap Diamond1("Fernando");

    std::cout << RED << "\n\nCOPY OF FERNANDO CREATION\n"
              << RESET;

    DiamondTrap Diamond2(Diamond1);

    Diamond2.attack("Quim");
    Diamond2.takeDamage(5);
    Diamond2.beRepaired(5);

    Diamond2.attack("Quim");

    Diamond2.whoAmI();
    Diamond2.status();

    std::cout << std::endl;
    return (0);
}
