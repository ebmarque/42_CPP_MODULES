/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:07:12 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/28 17:00:47 by ebmarque         ###   ########.fr       */
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
    std::cout << "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝    ╚═╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ ╚═════╝ " << std::endl;

	std::cout << std:: endl << "Harl has the following levels:" << std::endl;
	std::cout << "- INFO" << std::endl;
	std::cout << "- DEBUG" << std::endl;
	std::cout << "- WARNING" << std::endl;
	std::cout << "- ERROR" << std::endl;
	std::cout << "[ use 'exit' or 'Ctrl + D' to close the program ]" << std::endl;
}
void _get_level(void)
{
		std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		std::string level;
		Harl		hl;
		int			flag;
		_header();
	do
	{
		flag = 0;
		std::cout << std::endl << "Enter a level: ";
		std::getline(std::cin, level);
		if (std::cin.eof())
			exit(EXIT_SUCCESS);
		if (level.empty())
		{
			std::cout << "Error: empty input" << std::endl;
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			if (levels[i].compare(level) == 0)
			{
				std::cout << std::endl << "[" << level << "]:" << std::endl << std::endl;
				hl.complain(level);
				std::cout << std::endl;
				flag++;
			}
		}
		if (!flag && level.compare("exit"))
			std::cout << "Error: non existing level." << std::endl;
	} while (level.compare("exit"));

}

int main(void)
{
	_get_level();
	return EXIT_SUCCESS;
}
