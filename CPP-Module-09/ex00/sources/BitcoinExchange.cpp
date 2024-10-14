/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:56:03 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/06 17:14:47 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

float isValidNumber(std::string &value, bool db_check = false);


std::map<std::string, std::string> BitcoinExchange::loadDB(const char *filename)
{
	std::map<std::string, std::string> dataMap;
	std::ifstream file;
	std::string line, key, value;

	file.open(filename);
	if (file.is_open())
	{
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			if (std::getline(ss, key, ',') && std::getline(ss, value, ','))
			{
				clean_spaces(key);
				clean_spaces(value);
				if (!isValidDate(key))
				{
					ERROR_MESSAGE("DataBase file bad formated.");
					exit(EXIT_FAILURE);
				}
				try
				{
					isValidNumber(value, true);
				}
				catch(const std::exception& e)
				{
					ERROR_MESSAGE("on DB -> " + (std::string)e.what());
					exit(EXIT_FAILURE);
				}
				dataMap[key] = value;
			}
		}
		file.close();
	}
	else
	{
		throw NoAccessToDB();
	}
	return (dataMap);
}

BitcoinExchange::BitcoinExchange()
{
	LOG("BitcoinExchange Default constructor called.", GREEN);
	try
	{
		this->db = loadDB(DATA);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED BOLD << e.what() << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
}

BitcoinExchange::~BitcoinExchange()
{
	LOG("BitcoinExchange object deleted.", RED);
}

void BitcoinExchange::displayDB(void)
{
	typedef std::map<std::string, std::string>::iterator iterator;

	for (iterator it = db.begin(); it != db.end(); it++)
	{
		std::cout << BLUE << it->first
				  << RESET << " , " << YELLOW
				  << it->second << RESET << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	LOG("BitcoinExchange Copy constructor called.", GREEN);
	this->db = other.db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	LOG("BitcoinExchange Copy assignment operator called.", GREEN);
	if (this != &other)
	{
		this->db = other.db;
	}
	return (*this);
}



void BitcoinExchange::run(const char *file)
{
	std::ifstream ExchangeRate;
	std::string line, key, value;

	ExchangeRate.open(file);

	std::getline(ExchangeRate, line);
	if (line != "date | value")
	{
		std::cerr << RED BOLD << "Error: invalid input => " + line << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	while (std::getline(ExchangeRate, line))
	{
		size_t delim = line.find('|');
		if (delim == std::string::npos)
		{
			std::cerr << RED BOLD << "Error: bad format line input => " + line << RESET << std::endl;
			continue;
		}
		key = line.substr(0, delim); 
		value = line.substr(delim + 1, line.size());
		clean_spaces(key);
		clean_spaces(value);

		if (!isValidDate(key))
			std::cerr << RED BOLD << "Error: bad date format => " + key << RESET << std::endl;
		else
			try
			{
				std::string date = findClosestPreviousDate(this->db, key);
				float f_value = isValidNumber(value);
				float rate = std::atof(this->db[date].c_str()) * f_value;
				if (((int)rate > std::numeric_limits<int>::max()))
					throw std::out_of_range("too large a number.");
				std::cout << key << " => " << value << " = " << rate << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << RED BOLD << "Error: " + (std::string)e.what() << RESET << std::endl;
			}
	}
	ExchangeRate.close();
}