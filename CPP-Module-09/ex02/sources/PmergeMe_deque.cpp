/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:29:11 by ebmarque          #+#    #+#             */
/*   Updated: 2024/07/09 19:47:05 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

typedef std::deque<int>::iterator iterator;
typedef std::deque<std::pair<int, int> >::iterator pair_it;

void printdeque(std::deque<int> &deque, std::string name)
{
	std::cout << MAGENTA << name << RESET;
	for (size_t i = 0; i < deque.size(); i++)
	{
		std::cout << CYAN << deque[i] << " ";
	}
	std::cout << RESET << std::endl;
}

std::deque<int> CreateJacobsthal_deque(size_t max_n)
{
	std::deque<int> jacob_seq;
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

std::deque<int> CreateInsertionSequenceDeque(const std::deque<int> &jacob)
{
	std::deque<int> insertion_sequence;
	std::deque<int>::const_iterator it;
	for (it = jacob.begin(); it != jacob.end(); ++it)
	{
		if (*it == 0 || *it == 1)
		{
			insertion_sequence.push_back(*it);
		}
		else
		{
			int prev = *(it - 1);
			int current = *it;
			for (int i = current - prev; i > 0; --i)
			{
				int candidate = prev + i;
				if (candidate <= current && candidate > prev &&
					std::find(insertion_sequence.begin(), insertion_sequence.end(), candidate) == insertion_sequence.end())
				{
					insertion_sequence.push_back(candidate);
				}
			}
		}
	}
	insertion_sequence.pop_front();
	insertion_sequence.pop_front();
	return (insertion_sequence);
}


std::deque<std::pair<int, int> > create_deque_pairs(std::deque<int> &p_deque)
{
	std::deque<std::pair<int, int> > pairs;
	iterator it = p_deque.begin();
	while (it != p_deque.end())
	{
		int first = *it;
		it++;
		if (it != p_deque.end())
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

std::deque<int>::iterator binary_search_deque(std::deque<int> &deq, int value)
{
    int begin = 0;
    int end = deq.size();
    while (begin < end)
    {
        int middle = begin + (end - begin) / 2;
        if (value < deq[middle])
            end = middle;
        else
            begin = middle + 1;
    }
    
    return (deq.begin() + begin);
}

void insert_to_order(std::deque<int> &sorted, std::deque<int> &to_insert, std::deque<int> &insert_seq)
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
				int nbr_to_insert = to_insert[insert_index - 1];
				if (nbr_to_insert <= sorted.back())
				{
					it_at = binary_search_deque(sorted, nbr_to_insert);
					// std::cout << "will insert to_insert[" << insert_index - 1 << "]: " << nbr_to_insert << " before: " << *it_at << "\n";
					sorted.insert(it_at, nbr_to_insert);
				}
				else
				{
					// std::cout << "Pushed back to_insert[" << insert_index - 1 << "]: " << nbr_to_insert << "\n";
					sorted.push_back(nbr_to_insert);
				}
				elements--;
				insert_index--;
			}
			break;
		}
		int nbr_to_insert = to_insert[insert_index - 1];
		if (nbr_to_insert <= sorted.back())
		{
			it_at = binary_search_deque(sorted, nbr_to_insert);
			// std::cout << "will insert to_insert[" << insert_index - 1 << "]: " << nbr_to_insert << " before: " << *it_at << "\n";
			sorted.insert(it_at, nbr_to_insert);
		}
		else
		{
			// std::cout << "Pushed back to_insert[" << insert_index - 1 << "]: " << nbr_to_insert << "\n";
			sorted.push_back(nbr_to_insert);
		}
		it3++;
		elements--;
	}
}

void PmergeMe::sort_deque(void)
{
	clock_t start = clock();
	size_t jacob_size = (p_deque.size()) % 2 == 0 ? p_deque.size() / 2 : (p_deque.size() / 2) + 1;
	
	std::deque<std::pair<int, int> > pairs = create_deque_pairs(p_deque);
	
	std::sort(pairs.begin(), pairs.end(), comparePairs);

	std::deque<int> jacob = CreateJacobsthal_deque(jacob_size);
	std::deque<int> insert_seq = CreateInsertionSequenceDeque(jacob);
	std::deque<int> sorted, to_insert;

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

	/*----------------------------------- DEBUGGING MESSAGES ---------------------------------------*/
	// printdeque(jacob, "jacob sequence: ");
	// printdeque(insert_seq, "insersion sequence: ");
	// printdeque(sorted, "sorted from pairs: ");
	// printdeque(to_insert, "numbers to insert: ");
	insert_to_order(sorted, to_insert, insert_seq);
	clock_t end = clock();
	double time_sort_deque = (double(end - start) / CLOCKS_PER_SEC) * 1e6;
	this->sort_deque_time = time_sort_deque;
	printdeque(p_deque, RED BOLD"before sorting: ");
	printdeque(sorted, GREEN BOLD"after sorting: ");
}