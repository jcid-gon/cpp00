#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	auto	now = std::chrono::system_clock::now();
	std::time_t	now_time = std::chrono::system_clock::to_time_t(now);
	tm	local_time = *localtime(&now_time);
	std::cout << std::setfill('0') << "[" << local_time.tm_year + 1900 
		<< std::setw(2) << local_time.tm_mon + 1
		<< std::setw(2) << local_time.tm_mday << "_"
		<< std::setw(2) << local_time.tm_hour + 1
		<< std::setw(2) << local_time.tm_min + 1
		<< std::setw(2) << local_time.tm_sec + 1 << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
		<< "amount:" << _amount << ";created\n"; 
}

Account::~Account()
{
	_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	       	<< "amount:" << _amount << ";" 
		<< "closed\n";
}

void	Account::makeDeposit (int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << _amount + deposit << ";" 
		<< "nb_deposits:" << _nbDeposits + 1 << "\n";
	_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal (int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
		<< "p_amount:" << _amount << ";";
	if (withdrawal <= _amount)
	{
		std::cout << "withdrawal:" << withdrawal << ";" 
			<< "amount:" << _amount - withdrawal << ";"
			<< "nb_withdrawals:" << _nbWithdrawals + 1 << "\n";
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (true);
	}
	std::cout << ";withdrawal:refused\n";
	return (false);
}

int	Account::checkAmount(void) const
{
	return(_amount);
}

void	Account::displayStatus (void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";" 
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << "\n"; 
}


