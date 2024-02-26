#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "Account.h"
#include "User.h"
#include "Transaction.h"

class User;
class Transaction;

class Group
{
private:
    const std::string _name;

    // The members who will join the group
    std::vector<std::shared_ptr<User>> _members;

    //Vector of Accounts of all members, which accounts belongs to who? -> we use a map for this!
    std::vector<std::shared_ptr<Account>> _accountList;
    std::map<std::shared_ptr<User>, std::shared_ptr<Account>> _accountMap;

    //Vector of Transactions of the group
    std::vector<Transaction> _transactions;

    //friend class User;

public:
    Group() = default;

    Group(std::string name);

    std::string getName() const;

    std::vector<std::shared_ptr<User>> getMembers();

    std::map<std::shared_ptr<User>, std::shared_ptr<Account>>& getMap();

    std::vector<Transaction> getTransactions(){return _transactions;}

    Account& requestGroupAcc(User & user);

    //Who pays for the group -> creditor, What purpose -> payReason, How much was spent -> amount
    void addTransaction(User & creditor, Group & debtor, std::string payReason, double amount);

    void modifyGroupAccBalance(User & user);

    void printTransactions();

    void printAccBalances();

    void settleDebts();

    void addMember(const User & user);

    virtual ~Group() = default;
};
