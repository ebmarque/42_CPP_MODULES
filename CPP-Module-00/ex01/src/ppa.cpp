/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppa.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:08:00 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/21 14:53:55 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

#include <iostream>

void	_instruction(void)
{
	std::cout << "Welcome to your Personal PhoneBook Assistent\n\n"
			  << "Please insert one of the following commands: ⤵️\n"
			  << GREEN << "• ADD: save a new contact\n" << RESET
			  << GREEN << "• SEARCH: display a specific contact\n" << RESET
			  << GREEN << "• EXIT\n\n" << RESET;
}

void	_header_msg(void)
{
	system("clear");
	std::cout << std::endl;
    std::cout << std::endl;
	std::cout << "██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗        ██████╗  ██████╗  ██████╗ ██╗  ██╗\n";
    std::cout << "██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝        ██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝\n";
    std::cout << "██████╔╝███████║██║   ██║██╔██╗ ██║█████╗          ██████╔╝██║   ██║██║   ██║█████╔╝ \n";
    std::cout << "██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝          ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n";
    std::cout << "██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗\n";
    std::cout << "╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
	_instruction();
}

bool	_is_valid_command(std::string input)
{
	if (!input.compare("ADD") || !input.compare("SEARCH") \
		|| !input.compare("EXIT"))
		return (true);
	return (false);
}

void	_action(std::string input, PhoneBook &ppa)
{
	if (!input.compare("ADD"))
		ppa.add();
	else if (!input.compare("SEARCH"))
		ppa.search();
	else
	{
		std::cout << RED << "\n\nBye Bye!\n\n" << RESET;
		exit(0);
	}
}
void _trim(std::string &input)
{
	size_t start = input.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ;
	size_t end = input.find_last_not_of(" \t\r\n");
	input = input.substr(start, end - start + 1);
	for (size_t i = 0; i < input.size(); i++)
		input[i] = (char)toupper(input[i]);
}

void _get_command(PhoneBook &ppa)
{
	std::string input;
	while (1)
	{
		_header_msg();
		std::cout << RED << "Command: " << RESET;
		std::cin.clear();
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		_trim(input);
		if (!_is_valid_command(input))
		{
			std::cout << YELLOW << "Error: Invalid command"
					  << " please try again.\n\n" << RESET;
			sleep(2);
		}
		else
			_action(input, ppa);
		std::cin.clear();
	}
}

int main(void)
{

	PhoneBook ppa;
	_get_command(ppa);
	return (0);
}
