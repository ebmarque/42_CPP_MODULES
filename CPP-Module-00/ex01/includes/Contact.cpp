/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:16:33 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/21 14:42:14 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string f_name, std::string l_name, \
	std::string n_name, std::string d_secret, std::string phone_number)
{
	first_name = f_name;
	last_name = l_name;
	nick_name = n_name;
	darkest_secret = d_secret;
	phone_nbr = phone_number;
}

Contact::Contact()
{
}

Contact::~Contact()
{
}
std::string _contact_grid(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);	
}

void Contact::display(int i)
{
	std::cout << GREEN << "| " << RESET << std::setw(10) << i << RESET << std::flush;
	std::cout << GREEN << "| " << RESET << std::setw(10) <<  _contact_grid(first_name) << std::flush;
	std::cout << GREEN << "| " << RESET << std::setw(10) <<  _contact_grid(last_name) << std::flush;
	std::cout << GREEN << "| " << RESET << std::setw(10) <<  _contact_grid(nick_name) << std::flush;
	std::cout << GREEN << "|" << RESET << std::endl; 
}

void	Contact::show()
{
	std::string	input;
	std::cout << std::endl << std::endl;
	std::cout << BLUE <<  std::setw(15) << std::right << "First name: " << RESET << std::flush << first_name << std::endl;
	std::cout << BLUE << std::setw(15) << std::right << "Last name: " << RESET << std::flush << last_name << std::endl;
	std::cout << BLUE << std::setw(15) << std::right << "Nick name: " << RESET << std::flush << nick_name << std::endl;
	std::cout << GREEN << std::setw(15) << std::right << "Phone number: " << RESET << std::flush << phone_nbr << std::endl;
	std::cout << YELLOW << std::setw(15) << std::right << "Secret: " << RESET << std::flush << darkest_secret << std::endl << std::endl;
	std::cout << RED << "--- PRESS ENTER TO LEAVE ---" << RESET;
	std::cout << std::endl << std::endl;
	std::getline(std::cin, input);
}