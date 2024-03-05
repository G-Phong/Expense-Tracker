#include "Transaction.h"

Transaction::Transaction(User & creditor, Group& debtor, double amount, std::string payReason):_creditor(creditor),_debtor(debtor),_amount(amount)
{
    std::cout << "Constructing a Transaction...." << std::endl;

    //give information about purpose of payment
    _payReason = payReason;

    //we should save user and group information into a transaction object -> use INITIALIZER LIST
    //_creditor = creditor;
    //_debtor = debtor;

    //Amount spent divided by number of members
    //double share = amount/(sizeof(debtor.getMembers())/sizeof(long));
    double share = amount/debtor.getMembers().size();

    std::cout << "DEBUG: Share is " << share << ", amount is " << amount << std::endl;
    std::cout << "#Members: " << debtor.getMembers().size() << ". Printing: " << std::endl;
    //std::cout << "#Members: " << sizeof(debtor.getMembers().size)/sizeof(long) << ". Printing: " << std::endl;

    for(auto & member : debtor.getMembers())
    {
        std::cout << member->getName() << std::endl;
    }
    
    //Add amount on creditors personal account
    creditor.getAccount().transfer(amount-share);

    std::cout << "DEBUG" << std::endl;

    //Add amount spent on creditors group account
    //debtor.requestGroupAcc(creditor).transfer(amount);
    //auto x = debtor.getMap();

    std::cout << "DEBUG" << std::endl;

    //Subtract share to all personal debtor accounts
    for( auto & dbtr : debtor.getMembers())
    {
          dbtr->getAccount().transfer(share*(-1.0));
    }

    //Subtract share to all debtors group account
    for( auto & mp : debtor.getMap())
    {
        //Subtract share to personal accounts
        mp.first->getAccount().transfer(share*(-1));
            
        //Subtract share to group-specific accounts
        mp.second->transfer(share*(-1));

        if(mp.first->getName() == creditor.getName())
        {
            mp.second->transfer(amount);
        }
    }
    
}

double Transaction::getAmount()
{
    return _amount;
}

void Transaction::printTransaction()
{
    //Printing all transaction details to terminal
    std::cout << "Printing transaction details..." << std::endl;

    std::cout << "User " << _creditor.getName() << " paid " << _amount 
    << " for the following purpose: " << _payReason << std::endl;
    
}