/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fm.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:50:16 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/27 21:54:52 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FM_H
#define FM_H


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


class Fm
{
private:
	std::string in_file;
	std::string out_file;
public:
	Fm(std::string file_name);
	~Fm();
	void	replace(std::string to_finde, std::string to_replace);
};


#endif