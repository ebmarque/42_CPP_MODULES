/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:14:10 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/06 17:07:27 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/BitcoinExchange.hpp"

#define WRONG_ARGC "Error: Invalid number of arguments. Please provide a single .csv file as an argument."

void validate_entry(int argc, char *argv[])
{	
	if (argc == 2)
	{
		std::ifstream file;
		file.open(argv[1]);
		if (!file.is_open())
		{
			ERROR_MESSAGE("Could not open the file.");
			exit(EXIT_FAILURE);
		}
		else if (file.peek() == std::ifstream::traits_type::eof())
		{
			ERROR_MESSAGE("Empty input file provided.");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ERROR_MESSAGE("Error: Could not open the file.");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
{

	validate_entry(argc, argv);
	BitcoinExchange btc;
	try
	{
		btc.run(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED BOLD 
		<< e.what() 
		<< RESET << std::endl;
	}
	
	return (0);
}
