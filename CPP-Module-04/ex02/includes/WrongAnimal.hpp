/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:33:37 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 20:35:25 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"

class WrongAnimal
{
protected:
	std::string type;
		
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &ref);
	WrongAnimal& operator=(const WrongAnimal &ref);
	void makeSound(void) const;
	std::string getType(void) const;
};

#endif