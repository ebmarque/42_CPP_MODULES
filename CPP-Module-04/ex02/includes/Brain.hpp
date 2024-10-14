/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:36:55 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/17 20:35:22 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp"

class Brain
{
	private:
		std::string ideas[100];
			
	public:
		Brain();
		Brain(const Brain& ref);
		Brain& operator=(const Brain& ref);
		~Brain();
};

#endif