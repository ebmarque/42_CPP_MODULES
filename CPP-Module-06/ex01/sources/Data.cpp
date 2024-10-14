/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:04:27 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/13 19:08:58 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data() 
{
	this->name = "Ebenezer Marquezine";
	this->age = 26;
}

Data::Data(const Data& other) 
{
	this->age = other.age;
	this->name = other.name;
}

Data& Data::operator=(const Data& other) 
{
	if (this != &other) 
	{
		this->age = other.age;
		this->name = other.name;
	}
	return (*this);
}

Data::~Data() 
{
	std::cout << this->name + " was destroyed." << std::endl; 	
}

std::string Data::getName(void) const
{
	return (this->name);
}

int Data::getAge(void) const
{
	return (this->age);
}