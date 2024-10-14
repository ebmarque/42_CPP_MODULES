/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:30:43 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/12 16:12:14 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string str = argv[1];
		try
		{
			ScalarConverter::convert(str);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Invalid number of arguments." << std::endl;
		return (1);
	}
	return (0);
}
