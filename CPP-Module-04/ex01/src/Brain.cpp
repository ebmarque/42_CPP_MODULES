/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:39:35 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 19:48:53 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::~Brain()
{
	print("[BRAIN]: Deleted.", WHITE);
}

Brain::Brain()
{
	print("[BRAIN]: Default constructor called.", WHITE);
}

Brain::Brain(const Brain& ref)
{
	print("[BRAIN]: Copy constructor called.", WHITE);
	*this = ref;
}

Brain& Brain::operator=(const Brain& ref)
{
	print("[BRAIN]: Copy assignment operator called.", WHITE);
	if (this != &ref)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = ref.ideas[i];
	}
	return *this;
}

