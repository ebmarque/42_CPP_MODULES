/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_list.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:29:00 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/10 16:31:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

typedef std::list<int>::iterator iterator;
typedef std::list<std::pair<int, int> >::iterator pair_it;

void printlist(std::list<int> &lst, std::string name)
{
	std::cout << MAGENTA << name << RESET;
	for (iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << CYAN BOLD << *it << " ";
	}
	std::cout << RESET << std::endl;
}

std::list<int> CreateJacobsthal_list(size_t max_n)
{
	std::list<int> jacob_seq;
	if (max_n < 3)
		max_n = 3;
	jacob_seq.push_back(0);
	jacob_seq.push_back(1);

	int j_minus_2 = 0;
	int j_minus_1 = 1;

	while (true)
	{
		int j_n = j_minus_1 + 2 * j_minus_2;
		jacob_seq.push_back(j_n);
		j_minus_2 = j_minus_1;
		j_minus_1 = j_n;
		if ((size_t)j_n > max_n)
			break;
	}
	return (jacob_seq);
}

std::list<int> CreateInsertionSequenceList(const std::list<int> &jacob)
{
	std::list<int> insertion_sequence;

	std::list<int>::const_iterator it_prev = jacob.begin();
	std::list<int>::const_iterator it = jacob.begin();
	for (it = jacob.begin(); it != jacob.end(); ++it)
	{
		if (*it == 0 || *it == 1)
		{
			insertion_sequence.push_back(*it);
		}
		else
		{
			int prev = *it_prev;
			int current = *it;
			for (int i = current - prev; i > 0; --i)
			{
				int candidate = prev + i;
				if (candidate <= current && candidate > prev &&
					std::find(insertion_sequence.begin(),
							  insertion_sequence.end(), candidate) == insertion_sequence.end())
				{
					insertion_sequence.push_back(candidate);
				}
			}
		}
		it_prev = it;
	}
	insertion_sequence.pop_front();
	insertion_sequence.pop_front();
	return (insertion_sequence);
}

bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return a.first < b.first;
}

std::list<std::pair<int, int> > create_list_pairs(std::list<int> &p_list)
{

	std::list<std::pair<int, int> > pairs;
	iterator it = p_list.begin();
	while (it != p_list.end())
	{
		int first = *it;
		it++;
		if (it != p_list.end())
		{
			int second = *it;
			it++;
			if (first > second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
			pairs.push_back(std::make_pair(-1, first));
	}
	return (pairs);
}

std::list<int>::iterator binary_search_list(std::list<int> &lst, int value)
{
	std::list<int>::iterator  begin = lst.begin();
	std::list<int>::iterator  end = lst.end();
	while (begin != end)
	{
		std::list<int>::iterator middle = begin;
        std::advance(middle, std::distance(begin, end) / 2);
		if (value < *middle)
			end = middle;
		else
			begin = ++middle;
	}
	return (begin);
}

iterator at(int index, std::list<int> lst)
{
	list_iterator it = lst.begin();
	if (index == 1)
		return (it);
	std::advance(it, index - 1);
	return (it);
}

void insert_to_order(std::list<int> &sorted, std::list<int> &to_insert, std::list<int> &insert_seq)
{
	iterator it_at = sorted.begin();
	iterator it3 = insert_seq.begin();
	size_t elements = to_insert.size();
	int insert_size = (int)to_insert.size();
	
	while (elements > 0)
	{
		int insert_index = *it3;
		if (insert_index > insert_size)
		{
			while (insert_index > insert_size)
				insert_index--;
			while (elements > 0)
			{
				iterator nbr_to_insert = at(insert_index, to_insert);
				it_at = binary_search_list(sorted, *nbr_to_insert);
				sorted.insert(it_at, *nbr_to_insert);
				elements--;
				insert_index--;
			}
			break;
		}
		iterator nbr_to_insert = at(insert_index, to_insert);
		it_at = binary_search_list(sorted, *nbr_to_insert);
		sorted.insert(it_at, *nbr_to_insert);
		it3++;
		elements--;
	}
}

void PmergeMe::sort_list(void)
{
	clock_t start = clock();
	size_t jacob_size = (p_list.size()) % 2 == 0 ? p_list.size() / 2 : (p_list.size() / 2) + 1;
	
	std::list<std::pair<int, int> > pairs = create_list_pairs(p_list);
	pairs.sort(comparePairs);

	std::list<int> jacob = CreateJacobsthal_list(jacob_size);
	std::list<int> insert_seq = CreateInsertionSequenceList(jacob);
	std::list<int> sorted, to_insert;

	for (pair_it it = pairs.begin(); it != pairs.end(); it++)
	{
		sorted.push_back(it->first);
		to_insert.push_back(it->second);
	}
	if (p_list.size() % 2 != 0)
	{
		sorted.pop_front();
		to_insert.pop_front();
		pair_it it = pairs.begin();
		to_insert.push_back(it->second);
	}
	insert_to_order(sorted, to_insert, insert_seq);
	clock_t end = clock();
	// printlist(p_list, "list before sort: ");
	// printlist(sorted, "sorted final list: ");
	double time_sort_list = (double(end - start) / CLOCKS_PER_SEC) * 1e6;
	this->sort_list_time = time_sort_list;
}