/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:48:13 by ebmarque          #+#    #+#             */
/*   Updated: 2024/06/13 19:22:41 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"
#include "../includes/Serializer.hpp"

int main(void)
{
	Data *bene = new Data();

	std::cout << "Data->name: " << bene->getName() << std::endl;
	std::cout << "Data->age: " << bene->getAge() << std::endl;
	std::cout << "Data value serialized to uintptr_t: : " << Serializer::serialize(bene) << std::endl;
	
	std::cout << "deserialize(serialize(data))->getName(): ";
	std::cout << Serializer::deserialize(Serializer::serialize(bene))->getName() << std::endl;
	std::cout << "deserialize(serialize(data))->getAge(): ";
	std::cout << Serializer::deserialize(Serializer::serialize(bene))->getAge() << std::endl;

	delete bene;
	return (0);
}