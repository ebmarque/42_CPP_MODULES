/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:54:02 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/26 20:06:07 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		std::string str;
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (unsigned long j = 0; j < str.size(); j++)
				std::cout << (char)toupper(str[j]);
		}
		std::cout << std::endl;
	}
	return 0;
}

