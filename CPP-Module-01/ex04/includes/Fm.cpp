/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fm.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:55:01 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/27 22:20:58 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fm.hpp"


Fm::Fm(std::string file_name)
{
	this->in_file = file_name;
	this->out_file = file_name + ".replace";
}

Fm::~Fm()
{
	
}

void	Fm::replace(std::string to_find, std::string to_replace)
{
	std::fstream	ifs(this->in_file.c_str());
	if (ifs.is_open())
	{
		std::string text;
		std::getline(ifs, text, '\0');
		if (text.empty())
		{
			std::cerr << "Error: Empty file" << std::endl;
			exit(EXIT_FAILURE);
		}
		size_t pos = text.find(to_find);
		while (pos != std::string::npos)
		{
			text.erase(pos, to_find.size());
			text.insert(pos, to_replace);
			pos = text.find(to_find);
		}
		std::ofstream ofs(out_file.c_str());
		ofs << text;
		ofs.close();
	}
	else
	{
		std::cerr << "Error: Could not open " << this->in_file << std::endl;
		exit(EXIT_FAILURE);
	}
}