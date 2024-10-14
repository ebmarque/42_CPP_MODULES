/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:35:34 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/12 16:21:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include<string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string new_type);
	~Weapon();

	const std::string &getType();
	void setType(std::string new_type);
};


#endif