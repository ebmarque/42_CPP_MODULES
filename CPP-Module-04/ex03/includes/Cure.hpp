/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:56:40 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/22 13:38:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		~Cure();
		Cure();
		Cure(const Cure& ref);
		Cure& operator=(const Cure& ref);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter &target);
};

#endif