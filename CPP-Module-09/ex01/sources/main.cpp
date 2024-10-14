/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:57:00 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/07 11:33:56 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"


int	main(int argc, char *argv[])
{
	if (argc == 2 && argv[1][0])
	{
		try
		{
			RPN test(argv[1]);
			std::cout << GREEN BOLD << "result: " 
					  << test.calculate() 
					  << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
	{
		std::cout << RED BOLD 
				  << "Error: NULL expression or Invalid number of arguments." 
				  << RESET << std::endl;
	}
	return (0);
}
