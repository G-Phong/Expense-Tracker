#include "User.h"

User::User(int age, std::string name) : _name(name)
{
    _age = age;
    std::cout << "Constructing a user: " << name << " (" << age << ")" << std::endl;

}

int User::getAge() const
{
    return _age;
}

std::string User::getName() const
{
    return _name;
}

double User::getBalance() const
{
    return User::_account.getBalance();
}

void User::printGroups()
{
    std::cout << "User " << _name << " is member in the following groups:" << std::endl;

    // Use const because there's no reason not to use it
    // use * operator because we do not need to copy because we only print
    for (auto & group : _groups)
    {
        std::cout << group->getName() << std::endl;
    }
}

void User::joinGroup(Group & group)
{
    std::cout << "User " << this->getName() << " joining group " << group.getName() << std::endl;
    //Smart pointer!
    _groups.push_back(std::make_shared<Group>(group));
    group.addMember(*this); //User should be added...
    
}

Account & User::getAccount()
{
    return _account;
}

std::vector<std::shared_ptr<Group>> & User::getGroups()  
{
    return _groups;
}

void User::writeUserCsv()
{
    //ToDo write to File
    std::string fname = _name + "_info.csv";
    std::ofstream userinfo; 
    userinfo.open(fname);

    userinfo << "This file contains all information on" << _name << "'s activities in the expense tracker. \n";
    userinfo << "Balance," << getBalance() << "\n";

    //write Group information to csv file
    for(auto grp : _groups){
        userinfo << grp->getName() << "\n";

        //write list of members and their balances
        userinfo << "member, balance: \n";
        for(auto mbr : grp->getMap()){
            userinfo << mbr.first->getName() << "," << mbr.second->getBalance() << "\n";
        }

        //write list of transactions
        userinfo << "creditor, debtor, subject, amount \n";
        for(auto trac: grp->getTransactions()){
            userinfo << trac.getCreditor().getName() << "," 
                    <<trac.getDebtor().getName() << ","
                    <<trac.getSubject() << ","
                    <<trac.getAmount() << "\n";
        }

    }

    userinfo.close(); 
}