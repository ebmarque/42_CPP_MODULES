/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:16:00 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/10 15:37:12 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

static void LOG(std::string msg, const char *color)
{
	std::cout << color << msg << RESET << std::endl;
}

void ERROR(std::string &msg)
{
	std::cout << RED BOLD << "Error: " << msg << RESET << std::endl;
}

static bool isOperator(std::string token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

static bool isNumber(const std::string &token)
{
	if (token.empty())
		return (false);
	if (token == "-" || token == "+")
		return (false);
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!std::isdigit(token[i]))
		{
			if ((token[i] == '-' || token[i] == '+') && i == 0)
				continue;
			return (false);
		}
	}
	if(std::atoll(token.c_str()) > 10)
		throw RPN::ToLargeNumber();
	return (true);
}

static bool isValidExpression(const std::vector<std::string> &tokens)
{
	int operandCount = 0;

	for (size_t i = 0; i < tokens.size(); i++)
	{
		if (isNumber(tokens[i]))
			operandCount++;
		else if (isOperator(tokens[i]))
		{
			if (operandCount < 2)
				return (false);
			operandCount--;
		}
		else
			return (false);
	}
	return (operandCount == 1);
}

std::vector<std::string> RPN::tokenizeRPN(const std::string &expression)
{
	std::vector<std::string> tokens;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		if (!isNumber(token) && !isOperator(token))
			throw InvalidInput();
		tokens.push_back(token);
	}
	if (!isValidExpression(tokens))
		throw InvalidInput();
	return tokens;
}

RPN::RPN()
{
	LOG("RPN object created with default constructor.", GREEN);
	this->operators = "*+-/";
}

RPN::RPN(std::string exp) : expression(exp), operators("*+-/")
{
	LOG("RPN object created from expression: " + exp + ".", GREEN);
	notation = tokenizeRPN(exp);
}

RPN::RPN(const RPN &other)
{
	LOG("RPN object created with Copy constructor.", GREEN);
	this->notation = other.notation;
}

RPN &RPN::operator=(const RPN &other)
{
	LOG("RPN Copy assigment operator called.", GREEN);
	if (this != &other)
	{
		this->notation = other.notation;
	}
	return (*this);
}

RPN::~RPN()
{
	LOG("RPN Object deleted.", RED BOLD);
}

void RPN::display_notation(void)
{
	for (size_t i = 0; i < this->notation.size(); i++)
	{
		std::cout << GREEN BOLD << notation[i] << RESET << std::endl;
	}
}

long double operation(float a, float b, char operation)
{
	switch (operation)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
		{
			if (b == 0)
				throw RPN::DivisionByZero();
			return (a / b);
		}
		default:
			throw std::invalid_argument("Invalid operation");
	}
}

long double RPN::calculate()
{
    std::stack<long double> stack;
    for (size_t i = 0; i < notation.size(); i++)
    {
        if (isNumber(notation[i]))
            stack.push(std::atol(notation[i].c_str()));
        else if (isOperator(notation[i]))
        {
            if (stack.size() < 2)
                throw std::invalid_argument("Invalid expression");
            long double b = stack.top(); stack.pop();
            long double a = stack.top(); stack.pop();
            long double result = operation(a, b, notation[i][0]);
            stack.push(result);
        }
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Invalid expression");
    return stack.top();
}