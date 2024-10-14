/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:44:41 by ebmarque          #+#    #+#             */
/*   Updated: 2024/04/06 17:45:29 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_H
#define Fixed_H

#include <iostream>
#include <string>

class Fixed
{
private:
	int 				point_value;
	static const int	fraction_part = 8;
public:
	Fixed();
	Fixed(const Fixed &point);
	Fixed& operator=(const Fixed &point);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif