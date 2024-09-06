/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:37:01 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/06 02:35:44 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

#define blue "\033[38;5;117m"
#define reset "\033[0m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return(Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return(Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return(Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
    return(this->_amount);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << blue << Account::getNbAccounts() << reset;
    std::cout << ";total:" << blue << Account::getTotalAmount() << reset;
    std::cout << ";deposits:" << blue << Account::getNbDeposits() << reset;
    std::cout << ";withdrawals:" << blue << Account::getNbWithdrawals() << reset;
    std::cout << std::endl;
}

Account::Account( int initial_deposit )
{
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = this->getNbAccounts();
    Account::_nbAccounts ++;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << blue << this->_accountIndex << reset;
    std::cout << ";amount:" << blue << this->_amount << reset;
    std::cout << ";created" << std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << blue << this->_accountIndex << reset;
    std::cout << ";amount:" << blue << this->_amount << reset;
    std::cout << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t  t;

    t = time(NULL);
    std::cout << std::put_time(localtime(&t), "[%Y%m%d_%H%M%S] ");    
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << blue << this->_accountIndex << reset;
    std::cout << ";p_amount:" << blue << this->_amount << reset;
    std::cout << ";deposit:" << blue << deposit << reset;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    std::cout << ";amount:" << blue << this->_amount << reset;
    std::cout << ";nb_deposits:" << blue << this->_nbDeposits << reset;
    std::cout << std::endl;
    Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << blue << this->_accountIndex << reset;
    std::cout << ";p_amount:" << blue << this->_amount << reset;
    std::cout << ";withdrawal:";
    if (this->_amount >= withdrawal)
    {
        std::cout << blue << withdrawal << reset;
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        std::cout << ";amount:" << blue << this->_amount << reset;
        std::cout << ";nb_withdrawals:" << blue << this->_nbWithdrawals << reset;
        std::cout << std::endl;
        Account::_totalNbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        return (true);
    }
    else
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << blue << this->_accountIndex << reset;
    std::cout << ";amount:" << blue << this->_amount << reset;
    std::cout << ";deposits:" << blue << this->_nbDeposits << reset;
    std::cout << ";withdrawals:" << blue << this->_nbWithdrawals << reset;
    std::cout << std::endl;
}
