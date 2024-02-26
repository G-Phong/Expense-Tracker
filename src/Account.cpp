#include "Account.h"

Account::Account()
{
    _balance = 0.0;
    std::cout << "Constructing an account with initial balance: " << _balance << std::endl;
}

double Account::getBalance() const
{
    return _balance;
}

void Account::transfer(const double amount)
{
     _balance += amount;
}
