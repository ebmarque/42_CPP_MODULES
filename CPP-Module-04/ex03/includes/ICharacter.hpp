/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:42:59 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/22 13:27:44 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

class AMateria;
class ICharacter
{
	public:
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual std::string const &getName() const = 0;
		virtual void use(int idx, ICharacter &target) = 0;
		virtual ~ICharacter() {};
};

#endif