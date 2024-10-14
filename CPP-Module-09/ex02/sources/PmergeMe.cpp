/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:55:30 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/09 18:52:44 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

void ERROR(std::string msg)
{
	std::cout << RED BOLD << "Error: "
			  << msg << RESET
			  << std::endl;
}

void LOG(std::string msg, const char *color)
{
	std::cout << color
			  << msg << RESET
			  << std::endl;
}

PmergeMe::PmergeMe()
{
	LOG("PmergeMe Object created with default constructor.", GREEN);
	this->p_deque = std::deque<int>(0);
	this->p_list = std::list<int>(0);
	this->sort_deque_time = 0;
	this->sort_list_time = 0;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	LOG("PmergeMe Object created.", GREEN);
	this->sort_deque_time = 0;
	this->sort_list_time = 0;
	for (int i = 1; i < argc; i++)
	{
		this->p_list.push_back(std::atoll(argv[i]));
		this->p_deque.push_back(std::atoll(argv[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : p_list(other.p_list), p_deque(other.p_deque)
{
	sort_deque_time = other.sort_deque_time;
	sort_list_time = other.sort_list_time;
	LOG("PmergeMe Object created with Copy constructor.", GREEN);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	LOG("PmergeMe Copy assignment operator called.", GREEN);
	if (this != &other)
	{
		sort_deque_time = other.sort_deque_time;
		sort_list_time = other.sort_list_time;
		p_list = other.p_list;
		p_deque = other.p_deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	LOG("PmergeMe object deleted.", RED BOLD);
}

double	PmergeMe::getListTime(void)
{
	return (this->sort_list_time);
}

double	PmergeMe::getDequeTime(void)
{
	return (this->sort_deque_time);
}