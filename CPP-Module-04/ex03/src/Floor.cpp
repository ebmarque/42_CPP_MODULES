/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:25:30 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/30 16:47:22 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Floor.hpp"

Floor::~Floor(void)
{
	print("[FLOOR]: Deleting materias droped on the floor.", RED);
	t_DropedMateria *tmp = NULL;

	while (this->droped)
	{
		tmp = droped->next;
		print("LOG: deleting ->" + this->droped->item->getType(), YELLOW);
		if (this->droped->item)
			delete this->droped->item;
		if (this->droped)
			delete this->droped;
		droped = tmp;
	}
}

void Floor::cleanFloor(AMateria *m, std::string name)
{

	t_DropedMateria *current = droped;
	t_DropedMateria *previous = NULL;

	while (current)
	{
		if (current->item == m)
		{
			if (previous)
				previous->next = current->next;
			else
				droped = current->next;
			delete current;
			std::cout << "[" << name << "]: Took " << m->getType() << " from the floor." << std::endl;
			break;
		}

		previous = current;
		current = current->next;
	}
}

void Floor::takeFromFloor(AMateria *m, std::string name)
{
	Floor::getInstace().cleanFloor(m, name);
}

Floor::Floor(void)
{
	print("[FLOOR]: Default constructor called.", MAGENTA);
	this->droped = NULL;
}

Floor &Floor::getInstace(void)
{
	static Floor instance;
	return (instance);
}

void Floor::addFront(AMateria *m)
{
	t_DropedMateria *new_item = new t_DropedMateria;

	new_item->item = m;
	new_item->next = this->droped;
	this->droped = new_item;
}

void Floor::dropMateria(AMateria *m)
{
	getInstace().addFront(m);
}