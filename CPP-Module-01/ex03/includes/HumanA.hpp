/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:01:26 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/12 17:46:27 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

# include "Weapon.hpp"


class HumanA
{
private:
	std::string name;
	Weapon &gun;	
public:
	HumanA(std::string new_name, Weapon &new_gun);
	~HumanA();
	void	attack();
};

	

#endif