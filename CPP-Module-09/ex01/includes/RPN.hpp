/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:00:54 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/10 14:53:17 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <exception>
#include <stack>
#include <vector>

#define RESET "\033[0m"
#define BOLD "\033[1m"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

class RPN 
{
	private:
		std::string					expression;
		std::string					operators;
		std::vector<std::string>	notation;

	public:
	
	/*--------------------------- CANONICAL ---------------------------*/
		
		RPN();
		RPN(std::string exp);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

	
	/*--------------------------- EXCEPTIONS --------------------------*/
	
	class InvalidInput : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: Invalid input format");
		}
	};
	class ToLargeNumber : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: Too large a number");
		}
	};
	class DivisionByZero : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: Impossible division by zero");
		}
	};

	std::vector<std::string>	tokenizeRPN(const std::string &expression);
	void						display_notation(void);
	long double					calculate(void);


};

#endif // RPN_HPP