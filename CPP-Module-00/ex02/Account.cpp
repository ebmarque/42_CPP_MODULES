/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:35:18 by ebmarque          #+#    #+#             */
/*   Updated: 2024/03/07 08:19:29 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <time.h>
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	time_t t;
	struct tm* tm;

	t = time(NULL);
	tm = localtime(&t);

	std::cout << YELLOW << "[" << tm->tm_year + 1900;
	if (tm->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << tm->tm_mon + 1;
	if (tm->tm_mday < 10)
		std::cout << "0";
	std::cout << tm->tm_mday
			  << "_";
	if (tm->tm_hour < 10)
		std::cout << "0";
	std::cout << tm->tm_hour;
	if (tm->tm_min < 10)
		std::cout << "0";
	std::cout << tm->tm_min;
	if (tm->tm_sec < 10)
		std::cout << "0";
	std::cout << tm->tm_sec << "]" << RESET;
}

Account::Account(int initial_deposit)
{
	_accountIndex = t::getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << " index:"
			  << BLUE << _accountIndex << RESET << ";"
			  << "amount:"
			  << BLUE << _amount << RESET << ";"
			  << "created" << std::endl;	

}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << " index:"
			  << BLUE << _accountIndex << RESET << ";"
			  << "amount:"
			  << BLUE << _amount << RESET << ";"
			  << "closed" << std::endl;
}

void Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << " index:"
			  << BLUE << _accountIndex << RESET << ";"
			  << "amount:"
			  << BLUE << _amount << RESET << ";"
			  << "deposits:" << BLUE << _nbDeposits << RESET << ";"
			  << "withdrawals:" << BLUE << _nbWithdrawals << RESET << ";"
			  << std::endl;	
}

void	Account::makeDeposit(int deposit)
{
	int p_amout = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout << " index:"
			  << BLUE << _accountIndex << RESET << ";"
			  << "p_amount:" << BLUE << p_amout << RESET << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:"
			  << BLUE << _amount << RESET << ";"
			  << "nb_deposits:" << BLUE << this->_nbDeposits << RESET 
			  << std::endl;	
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}


bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amout = this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		this->_displayTimestamp();
		std::cout << " index:"
				  << BLUE << _accountIndex << RESET << ";"
				  << "p_amount:" << BLUE << p_amout << RESET << ";"
				  << "withdrawal:" << RED << "refused" << RESET << std::endl;
				  return (false);
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	this->_displayTimestamp();
	std::cout << " index:"
			  << BLUE << _accountIndex << RESET << ";"
			  << "p_amount:" << BLUE << p_amout << RESET << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:"
			  << BLUE << _amount << RESET << ";"
			  << "nb_withdrawals:" << BLUE <<  this->_nbWithdrawals << RESET 
			  << std::endl;
	return (true);
}


void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:"
			  << GREEN << _nbAccounts << RESET << ";"
			  << "total:" << GREEN << _totalAmount << RESET << ";"
			  << "deposits:" << GREEN << _totalNbDeposits << RESET << ";"
			  << "withdrawals:"
			  << GREEN << _totalNbWithdrawals << RESET << std::endl;
}

