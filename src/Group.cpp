#include "Group.h"
#include "MenuFunctions.h"
#include <algorithm>


Group::Group(std::string name):_name(name){
    std::cout << "Constructing a group: " << name << std::endl;
}

std::string Group::getName() const{
    return _name;
}

void Group::addMember(const User & user)
{
    std::cout << "User " << user.getName() << " is being added to the group " << this->getName() << std::endl;
    //Add member to the _members vector
    _members.push_back(std::make_shared<User>(user));
    //Create a new account for each member and assign it to the member using a std::map
    _accountMap[std::make_shared<User>(user)] = std::make_shared<Account>(Account());
}

std::vector<std::shared_ptr<User>> Group::getMembers()
{
    return _members;
}

std::map<std::shared_ptr<User>, std::shared_ptr<Account>>& Group::getMap() 
{

    return _accountMap;
}

void Group::addTransaction(User & creditor, Group & debtor, std::string payReason, double amount)
{
    //creating a new Transaction for the debtor (group), made by the creditor (user)
    Transaction newTransaction(creditor, debtor, amount, payReason);

    //add the transaction to the group-intern transactions list
    _transactions.push_back(newTransaction);
}

void Group::printTransactions()
{
    //Printing all transactions
    std::cout << "Printing all group transactions: " << std::endl;
    for(auto & trans : _transactions)
    {
        trans.printTransaction();
    }
    
}

void Group::settleDebts()
{
    //Define an algorithm which defines who has to pay how much for who...
    //Inspiration: https://stackoverflow.com/questions/1163116/algorithm-to-determine-minimum-payments-amongst-a-group
    //https://www.youtube.com/watch?v=WaUlOC1T07c&ab_channel=TanishqChaudhary

    /* My settling algorithm:
    * 1) Separate into two lists: positive balances and negative balances (no need to use references)
    * 2) Optional: Sort both lists
    * 3) negative acc -> positive acc
    * 4) End algorithm if all accounts balance to 0
    */

    // Step 1) Use doubles, no need to use account references -> just copy the balance
    std::map<std::shared_ptr<User>, double> positives;
    std::map<std::shared_ptr<User>, double> negatives;

    for(auto & acc : _accountMap)
    {
        if( acc.second->getBalance() > 0.0)
        {
            positives[acc.first] = acc.second->getBalance();
        }

        if( acc.second->getBalance() < 0.0)
        {
            negatives[acc.first] = acc.second->getBalance();
        }

    }

    //Debug:
    std::cout << "Positives:" << std::endl;
    for(auto & pos : positives)
    {
        std::cout << pos.first->getName() << ", balance: " << pos.second << std::endl;
    }
    std::cout << "Negatives:" << std::endl;
    for(auto & neg : negatives)
    {
        std::cout << neg.first->getName() << ", balance: " << neg.second << std::endl;
    }
    
    // Step 3) Pay off iteratively
    std::cout << "Reimbursement scheme: " << std::endl;

    bool done = false;
    while(done != true)
    { done = true;

        //printAccBalances();

        for( auto & neg : negatives)
        {
            for( auto & pos : positives)
            {
                    if(neg.second != 0.0)
                {
                    if(pos.second != 0.0)
                    {
                        if(std::abs(neg.second) > std::abs(pos.second))
                        {
                            std::cout << "User " << neg.first->getName() << " has to pay " 
                            << std::abs(pos.second) << " to User " << pos.first->getName() << std::endl;

                            neg.second += std::abs(pos.second);
                            pos.second -= std::abs(pos.second);
                            
                        } else
                        {
                            std::cout << "User " << neg.first->getName() << " has to pay " 
                            << std::abs(neg.second) << " to User " << pos.first->getName() << std::endl;
                            pos.second -= std::abs(neg.second);
                            neg.second += std::abs(neg.second);
                            
                        }
                        //Debug
                        //std::cout << "After: " <<pos.first->getName() << ", balance: " << pos.second << std::endl;
                        //std::cout << "After: " <<neg.first->getName() << ", balance: " << neg.second << std::endl;
                    }
                }
                //Floating point arithmetic with doubles! Add some tolerance!
                    if(!(neg.second > -0.1 && neg.second < 0.1)  || !(pos.second > -0.1 && pos.second < 0.1))
                    {
                        done = false;
                    }

            }
            

        }
    }

}

Account& Group::requestGroupAcc(User& user)
{

    //auto object = *_accountMap[std::make_shared<User>(user)];

    //Return the group acc of the user, dereferencing with * operator
    return *_accountMap[std::make_shared<User>(user)];
}

void Group::printAccBalances()
{
    std::cout << "Printing all account balances of group " << this->getName() << ":" << std::endl;

    for(auto & acc : _accountMap)
    {
        std::cout << "User " << acc.first->getName() << "'s balance: " << acc.second->getBalance() << std::endl;        
    }
}