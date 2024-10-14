/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:16:22 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/07 11:25:21 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "• The memory address of the string variable: " << &str 
			  << std::endl
			  << "• The memory address held by stringPTR: " << &stringPTR 
			  << std::endl
			  << "• The memory address held by stringREF: " << &stringREF 
			  << std::endl << std::endl;

	std::cout << &str << ": " << str << std::endl;
    std::cout << stringPTR << ": " << *stringPTR << std::endl;
    std::cout << &stringREF << ": " << stringREF << std::endl;
	return (0);
}
