/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-05 14:37:01 by asangerm          #+#    #+#             */
/*   Updated: 2024-09-05 14:37:01 by asangerm         ###   ########.fr       */
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

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << blue << Account::_nbAccounts << reset << ";total:" << blue << Account::_totalAmount << reset << ";deposits:" << blue << Account::_totalNbDeposits << reset << ";withdrawals:" << blue << Account::_totalNbWithdrawals << reset << std::endl;
}

Account::Account( int initial_deposit )
{
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = this->getNbAccounts();
    this->_nbAccounts += 1;
    this->_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" << blue << this->_accountIndex << reset << ";amount:" << blue << this->_amount << reset << ";created" << std::endl;
}

Account::~Account( void )
{

}

void	Account::_displayTimestamp( void )
{
    time_t  t;

    t = time(NULL);
    std::cout << std::put_time(localtime(&t), "[%Y%m%d_%H%M%S] ");    
}

void	Account::makeDeposit( int deposit )
{
    this->_amount += deposit;
    this->_nbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (this->_amount >= withdrawal)
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        return (true);
    }
    return (false);
}

int		Account::checkAmount( void ) const
{
    return(this->_amount);
}

void	Account::displayStatus( void ) const
{

}
