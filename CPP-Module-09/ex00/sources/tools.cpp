/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:50:48 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/06 17:16:31 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

bool isValidDate(std::string &date)
{
	if (date.length() != 10)
		return (false);

	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return (false);
		}
		else
		{
			if (!std::isdigit(date[i]))
				return (false);
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);

	const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear && month == 2 && day == 29)
		return (true);

	return (day > 0 && day <= daysInMonth[month - 1]);
}

std::string findClosestPreviousDate(const std::map<std::string, std::string> &dateMap, const std::string &date)
{
	std::map<std::string, std::string>::const_iterator it = dateMap.lower_bound(date);

	if (it != dateMap.end() && it->first == date)
		return it->first;

	if (it == dateMap.begin())
		throw std::out_of_range("Date => " + date + " preceeds data base oldest date: " + it->first);

	--it;
	return it->first;
}

float isValidNumber(std::string &value, bool db_check = false)
{
	for (size_t i = 0; i < value.size(); i++)
	{
		int dots = 0;
		if (!std::isdigit(value[i]))
		{
			if (value[i] == '+' && i == 0)
				continue;
			else if (value[i] == '.' && dots == 0)
			{
				dots++;
				continue;
			}
			else if (value[i] == '-' && i == 0)
				throw std::out_of_range("not a positive number.");
			else
				throw std::out_of_range("not a number.");
		}
	}
	float nbr = std::atof(value.c_str());
	if (!db_check && nbr > MAX_VALUE)
		throw std::out_of_range("too large a number.");
	return (nbr);
}

void clean_spaces(std::string &str)
{
	str.erase(0, str.find_first_not_of(" \n\r\t"));
	str.erase(str.find_last_not_of(" \n\r\t") + 1);
}