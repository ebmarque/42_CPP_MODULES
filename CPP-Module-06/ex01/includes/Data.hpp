/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:20:20 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/13 19:07:47 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>
#include <string>

class Data 
{
	private:
		std::string	name;
		int			age;

	public:
		uintptr_t data;
		Data();
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();
		std::string getName(void) const;
		int getAge(void) const;
};


#endif // DATA_HPP