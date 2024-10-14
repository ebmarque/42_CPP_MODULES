/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:44:25 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/10 15:39:10 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool is_valid_number(std::string number)
{
	if (number.empty())
		return (false);
	if (number == "-" || number == "+")
		return (false);
	for (size_t i = 0; i < number.size(); i++)
	{
		if (!std::isdigit(number[i]))
		{
			if (number[i] == '+' && i == 0)
				continue;
			return (false);
		}
	}
	long double big_number = std::atoll(number.c_str());
	if (big_number == 0 || big_number > std::numeric_limits<int>::max())
		return (false);
	return(true);
}

bool	is_valid_arguments(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (!is_valid_number(argv[i]))
			return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{

	if (argc < 2)
	{
		ERROR("Insuficient number of arguments.");
		exit(EXIT_FAILURE);
	}
	else if (!is_valid_arguments(argc, argv))
	{
		ERROR("Invalid list of arguments.");
		exit(EXIT_FAILURE);
	}
	PmergeMe algo(argc, argv);
	algo.sort_deque();
	algo.sort_list();
	std::cout << GREEN BOLD << "deque took: " << algo.getDequeTime() << " us." << std::endl;
	std::cout << GREEN BOLD << "list took: " << algo.getListTime() << " us." << std::endl;
	return (0);
}
