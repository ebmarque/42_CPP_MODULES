/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:30:20 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/06 17:08:12 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <cctype>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

#define ERROR_MESSAGE(msg) (std::cerr << RED << BOLD << UNDERLINE << "Error: " << msg << RESET << std::endl)
#define LOG(msg, color) (std::cout << color << msg << RESET << std::endl)

#define DATA "data.csv"
#define MAX_VALUE 1000
#define MIN_VALUE 0

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> db;
		std::map<std::string, std::string> loadDB(const char *filename);

	public:
		/* ------------------------------- CANONICAL ------------------------------ */

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void displayDB(void);

		void run(const char *file);

		/**
		 * @class NoAccessToDB
		 * @brief Exception class for when there is no access to the database file.
		 */
		class NoAccessToDB : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("Error: Unable to access 'data.csv'");
			}
		};
		class EmptyFile : public std::exception
		{
		public:
			virtual const char *what() const throw()
			{
				return ("Error: Empty file provided.");
			}
		};
};

bool isValidDate(std::string &date);
std::string findClosestPreviousDate(const std::map<std::string, std::string> &dateMap, const std::string &date);
void clean_spaces(std::string &str);

#endif // BITCOINEXCHANGE_HPP