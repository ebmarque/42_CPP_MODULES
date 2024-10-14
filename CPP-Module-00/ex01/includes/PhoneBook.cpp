/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:12:04 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/21 17:08:01 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::index = 0;
void _header_msg(void);

std::string _get_info(std::string text)
{
	std::string input;

	while (true)
	{
		_header_msg();
		std::cout << CYAN << text << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		size_t start = input.find_first_not_of(" \t\r\n");
		if (start == std::string::npos)
		{
			std::cout << RED << "ERROR: EMPTY FIELD.\n" << RESET;
			sleep(3);
			std::cin.clear();
			system("clear");
			continue ;
		}
		size_t end = input.find_last_not_of(" \t\r\n");
		input = input.substr(start, end - start + 1);
		break ;
	}
	return (input);
}

bool	_phone_validation(std::string input)
{
		for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
		{
			if (!std::isdigit(*it))
			{
				std::cout << RED << "ERROR: INVALID PHONE NUMBER." << RESET << std::endl;
				sleep(3);
				std::cin.clear();
				system("clear");
				return false;
			}
    }
		if (input.size() != 9)
		{
			std::cout << RED << "ERROR: PLEASE INSERT A 9 DIGIT NUMBER.\n" << RESET;
			sleep(3);
			std::cin.clear();
			system("clear");
			return (false) ;
		}
	return (true);
}

std::string	_get_phone_nbr(const std::string text)
{
	std::string input;

	while (true)
	{
		_header_msg();
		std::cin.clear();
		std::cout << CYAN << text << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		size_t start = input.find_first_not_of(" \t\r\n");
		if (start == std::string::npos)
		{
			std::cout << RED << "ERROR: EMPTY FIELD.\n" << RESET;
			sleep(3);
			system("clear");
			continue ;
		}
		if (!_phone_validation(input))
			continue ;
		size_t end = input.find_last_not_of(" \t\r\n");
		input = input.substr(start, end - start + 1);
		break ;
	}
	return (input);
}

void	PhoneBook::add(void)
{
	std::string	f_name;
	std::string	l_name;
	std::string	n_name;
	std::string	d_secret;
	std::string	phone_number;
	
	f_name = _get_info("Insert the contact first name: ");
	l_name = _get_info("Insert the contact last name: ");
	n_name = _get_info("Insert the contact nick name: ");
	d_secret = _get_info("Insert the contact darkest secret: ");
	phone_number = _get_phone_nbr("Insert the contact phone number: ");
	if (index < 7)
	{
		contacts[index] = Contact(f_name, l_name, n_name, d_secret, phone_number);
		index++;
	}
	else
	{
		contacts[index] = Contact(f_name, l_name, n_name, d_secret, phone_number);
		index = 0;
	}
}

int	_get_num() {
	int nbr;
	std::string input_str;
	while (true)
	{
		std::cout << "Insert the index of the contact you wish to display the information: ";
		std::getline(std::cin, input_str);
		std::stringstream ss(input_str);
		if (std::cin.eof())
			exit(0);
		if (!(ss >> nbr) || nbr < 1 || nbr > 8)
		{
			std::cout << RED 
					  << "Invalid input. Please enter a valid index (1 - 8)."
					  << RESET <<  std::endl;
			sleep(3);
			system("clear");
			std::cin.clear();
		}
		else
			break ;
	}
	return nbr;
}

void	PhoneBook::search()
{
	int input;
	std::cout << GREEN << std::endl
			  <<  "| " << std::setw(10) << "INDEX" << std::flush
			  <<  "| " << std::setw(10) << "FIRST NAME" << std::flush
			  <<  "| " << std::setw(10) << "LAST NAME" << std::flush
			  <<  "| " << std::setw(10) << "NICK NAME" << std::flush;
	std::cout << GREEN << "|" << RESET << std::endl;
	for (int i = 0; i < 8; i++)
	{
		contacts[i].display(i + 1);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	input = _get_num();
	contacts[input - 1].show();
}

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}
