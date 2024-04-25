/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:00:16 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/10 14:45:34 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

//vars init
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Public Constructor */
Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), 
				_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";created" << std::endl;
}

/* Destructor */
Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= Account::checkAmount();
}

int Account::getNbAccounts(void) {   
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {   
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {   
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {   
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {   
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";" << std::flush;
	std::cout << "total:" << Account::getTotalAmount() << ";" << std::flush;
	std::cout << "deposits:" << Account::getNbDeposits() << ";" << std::flush;
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << std::flush;
	std::cout << "p_amount:" << Account::checkAmount() << ";" << std::flush;
	if (deposit < 0)
		std::cout << "deposit:refused" << std::endl;
	else {
		std::cout << "deposit:" << deposit << ";" << std::flush;
		this->_amount += deposit;
		this->_totalAmount += deposit;
		std::cout << "amount:" << Account::checkAmount() << ";" << std::flush;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	}
}

bool    Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";
	if (withdrawal < 0 || Account::checkAmount() - withdrawal < 0) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else {
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" << Account::checkAmount() << ";";
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int     Account::checkAmount(void) const {
	return (this->_amount);
}

void    Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void) {
	if (EVAL) {
		std::cout << "[19920104_091532] " << std::flush;
		return ;
	}
    std::time_t t = std::time(0);
    std::tm *t_n = std::localtime(&t);
    std::cout << "[" << t_n->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << t_n->tm_mon;
    std::cout << std::setfill('0') << std::setw(2) << t_n->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << t_n->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << t_n->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << t_n->tm_sec << "] " << std::flush;
}