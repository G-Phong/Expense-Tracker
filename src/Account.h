#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <memory>

class Account
{
private:
    double _balance;

public:
    // Account for Users -> initialize with 0
    Account();

    double getBalance() const;

    //changing balance
    void transfer(const double amount);

    virtual ~Account() = default;
};

#endif // ACCOUNT_H