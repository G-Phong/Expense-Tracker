#ifndef USER_H
#define USER_H

#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include "Group.h"
#include "Account.h"

//Avoid circular dependencies: 
//https://stackoverflow.com/questions/4964482/how-to-create-two-classes-in-c-which-use-each-other-as-data
class Group;

class User
{
private:
    
    const std::string _name; // const because name should not be changed
    // A vector of shared pointers to Group objects. We use shared pointers because multiple users will use this pointer.
    std::vector<std::shared_ptr<Group>> _groups;
    Account _account;
    int _age;                // age can be changed -> not "const"

    friend class Group;

public:
    User() = default;
    User(int age, std::string name);

    //const get functions
    int getAge() const;
    std::string getName() const;
    double getBalance() const;
    
    //get functions
    Account & getAccount();
    std::vector<std::shared_ptr<Group>> & getGroups();

    //user joins a desired group
    void joinGroup(Group & group);

    void printGroups();

    void writeUserCsv();

    virtual ~User() = default;
};

#endif // USER_H