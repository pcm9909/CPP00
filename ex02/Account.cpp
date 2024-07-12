#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	std::cout << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "withdrawal:";
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		std::cout << withdrawal << ";"
				  << "amount:" << _amount << ';'
				  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << "refused" << std::endl;
		return false;
	}
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	time_t timer = time(NULL);
	struct tm *t = localtime(&timer);

	std::cout << "["
			  << t->tm_year + 1900
			  << std::setw(2) << std::setfill('0') << t->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << t->tm_mday
			  << "_"
			  << std::setw(2) << std::setfill('0') << t->tm_hour
			  << std::setw(2) << std::setfill('0') << t->tm_min
			  << std::setw(2) << std::setfill('0') << t->tm_sec
			  << "]";
}