/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:35:59 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/29 14:32:26 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
    std::cout << std::endl << "[DEBUG]" << std::endl << std::endl;
	std::cout << "love having extra bacon for my " 
			  << "7XL-double-cheese-triple-pickle-special-ketchup "
			  << "burger. I really do!" << std::endl << std::endl; 
}

void	Harl::info()
{
    std::cout << std::endl << "[INFO]" << std::endl << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't "
			  << "put enough bacon in my burger! If you did, "
			  << "I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning()
{
    std::cout << std::endl << "[WARNING]" << std::endl << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years whereas you started working "
			  << "here since last month." << std::endl << std::endl;
}

void	Harl::error()
{
    std::cout << std::endl << "[ERROR]" << std::endl << std::endl;
	std::cout << "This is unacceptable! I want to speak "
			  << "to the manager now." << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && levels[i].compare(level))
        i++ ;
    switch (i)
    {
        case    0: 
            this->debug();
        case    1: 
            this->info();
        case    2: 
            this->warning();
        case    3: 
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl << std::endl;
    }
	
}

Harl::Harl()
{
	
}

Harl::~Harl()
{
	
}