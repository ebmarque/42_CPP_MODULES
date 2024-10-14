/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:53:06 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/22 17:52:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Floor.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		~Character();
		Character();
		Character(const Character &ref);
		Character(std::string n);
		Character &operator=(const Character &ref);

		/*----------------- OVERRIDED FUNCTIONS ------------------*/
		
		void 					equip(AMateria *m);
		void 					unequip(int idx);
		std::string const 		&getName() const;
		void 					use(int idx, ICharacter &target);
};

#endif