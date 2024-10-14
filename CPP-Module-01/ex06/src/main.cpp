/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:07:12 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/29 14:39:16 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"


void	_header(void)
{
	system("clear");
	std::cout << "██╗  ██╗ █████╗ ██████╗ ██╗         ██╗███████╗    ██████╗  ██████╗ ██████╗ ██╗███╗   ██╗ ██████╗ " << std::endl;
    std::cout << "██║  ██║██╔══██╗██╔══██╗██║         ██║██╔════╝    ██╔══██╗██╔═══██╗██╔══██╗██║████╗  ██║██╔════╝ " << std::endl;
    std::cout << "███████║███████║██████╔╝██║         ██║███████╗    ██████╔╝██║   ██║██████╔╝██║██╔██╗ ██║██║  ███╗" << std::endl;
    std::cout << "██╔══██║██╔══██║██╔══██╗██║         ██║╚════██║    ██╔══██╗██║   ██║██╔══██╗██║██║╚██╗██║██║   ██║" << std::endl;
    std::cout << "██║  ██║██║  ██║██║  ██║███████╗    ██║███████║    ██████╔╝╚██████╔╝██║  ██║██║██║ ╚████║╚██████╔╝" << std::endl;
    std::cout << "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ ╚═════╝ " << std::endl
			  << std::endl
			  << std::endl
			  << std::endl
			  << std::endl;
}

void _get_level(char **argv)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string level = argv[1];
	Harl		hl;
	// int flag = 0;
	if (level.empty())
	{
		std::cout << "Error: empty argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	hl.complain(level);
}

int main(int argc, char **argv)
{
	_header();
	if (argc != 2)
		std::cerr << "Error: usage: ./Harl <level> [DEBUG, INFO, WARNING, ERROR]"
				  << std::endl
				  << std::endl
				  << std::endl;
	else
		_get_level(argv);
	return EXIT_SUCCESS;
}
