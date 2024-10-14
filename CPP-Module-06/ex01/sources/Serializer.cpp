/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:18:11 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/13 19:10:49 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/*-------------------------------CANOCINAL---------------------------------*/

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) {(void)other;}
Serializer& Serializer::operator=(const Serializer& other) 
{
	(void)other;
	return (*this);
}
Serializer::~Serializer() {}

/*--------------------------------------------------------------------------*/

uintptr_t Serializer::serialize(Data *ptr) 
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) 
{
	return (reinterpret_cast<Data *>(raw));
}


