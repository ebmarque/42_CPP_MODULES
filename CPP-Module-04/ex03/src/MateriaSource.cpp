/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:15:51 by ebmarque          #+#    #+#             */
/*   Updated: 2024/08/30 18:04:26 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::~MateriaSource()
{
	print("[MATERIASOURCE]: Deleted.", RED);
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i])
			delete this->materials[i];
	}
}

MateriaSource::MateriaSource(void)
{
	print("[MATERIASOURCE]: Defautl constructor called.", BLUE);
	for (size_t i = 0; i < 4; i++)
	{
		this->materials[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	print("[MATERIASOURCE]: Copy constructor called.", BLUE);
	for (size_t i = 0; i < 4; i++)
	{
		if (ref.materials[i] != NULL)
			this->materials[i] = ref.materials[i]->clone();
		else
			this->materials[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
{
	print("[MATERIASOURCE]: Copy assignment operator called.", BLUE);
	if (this != &ref)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->materials[i] != NULL)
				delete this->materials[i];
		}
		for (size_t i = 0; i < 4; i++)
		{
			if (ref.materials[i] != NULL)
				this->materials[i] = ref.materials[i]->clone();
			else
				this->materials[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *ref)
{
	print("[MATERIASOURCE]: 'learnMAteria' mmember function called.", BLUE);
	for (size_t i = 0; i < 4; i++)
	{
		if (this->materials[i] == NULL)
		{
			this->materials[i] = ref;
			return ;
		}
	}
}

AMateria * MateriaSource::createMateria(std::string const &type)
{
	print("[MATERIASOURCE]: createMateria member function called.", BLUE);
	for (int i = 0; i < 4; i++)
    {
        if(this->materials[i] && this->materials[i]->getType() == type)
            return (materials[i]->clone());
    }
	print("[MATERIASOURCE]: Has not learned " + type + " yet.", RED);
    return (NULL);
}
