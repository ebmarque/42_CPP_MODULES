/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:53:19 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/09 19:05:38 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <set>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <limits>
#include <sys/time.h>
#include <ctime>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"


typedef std::list<int>::iterator list_iterator;
typedef std::deque<int>::const_iterator deque_iterator;
class PmergeMe 
{
	private:
	
		std::list<int> p_list;
		std::deque<int> p_deque;
		double sort_list_time;
		double sort_deque_time;

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
		void	sort_deque(void);
		void	sort_list(void);
		
		double	getListTime(void);
		double	getDequeTime(void);

};

bool	comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b);
void	ERROR(std::string msg);
void	LOG(std::string msg, const char *color);

#endif // PMERGEME_HPP