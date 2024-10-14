/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:55:27 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/22 13:36:40 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{	
	public:
		Ice();
		~Ice();
		
		Ice(const Ice& ref);
		Ice& operator=(const Ice& ref);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter &target);
};

#endif