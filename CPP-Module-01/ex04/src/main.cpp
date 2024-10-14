/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:40:50 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/27 22:17:38 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fm.hpp"

bool	_valid_input(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string file = argv[1];
		std::string to_find = argv[2];
		std::string to_replace = argv[3];
		if (file.empty() || to_find.empty() || to_replace.empty())
			return (false);
		
		return (true);	
	}
	return (false);
}

int main(int argc, char *argv[])
{
	if (_valid_input(argc, argv))
	{
		Fm ifs(argv[1]);
		ifs.replace(argv[2], argv[3]);
	}
	else
	{
		std::cout << "Error: Invalid arguments" << std::endl;
		std::cout << "Usage: ./Fm <filename> <to_find> <replace>."
				  << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
