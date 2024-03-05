#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <memory>

#include "User.h"
#include "Group.h"

class Group;
class User;

class Transaction
{
private:
    std::string _payReason;

    //save user and group references?
    User& _creditor;
    Group& _debtor;

    double _amount;
    

public:
    
    Transaction(User&, Group&, double, std::string);

    void printTransaction();

    double getAmount();
    std::string getSubject(){return _payReason;}
    User& getCreditor(){return _creditor;}
    Group& getDebtor(){return _debtor;}

    virtual ~Transaction() = default;
};

#endif // TRANSACTION_H