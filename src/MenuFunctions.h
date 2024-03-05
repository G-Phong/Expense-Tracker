#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "User.h"
#include "Group.h"

//define as extern because it will then look for the declaration in main.cpp
extern std::vector<User> users;
extern std::vector<Group> groups;

class MenuFunctions
{

public:
    MenuFunctions();

    // generating Login/sign up functions with main menu
    void mainMenu();

    // generating User menu to navigate the functionality
    void userMenu(User & user);

    // Creates new user, prompts User for name and age
    void userCreate();

    // Creates a new group, prompts User for a name
    void createGroup(User & user);

    // helper function, you can pass the name of a Group here
    void groupMenu(Group &group, User & User);

    // This function takes a group-struct as input (later on it will be an object) and opens the Group menu
    //void groupMenu(Group group);

    // Allows to edit users in a certain group.
    void g_editUsers(Group group);

    // First argument takes "users" or "transactions" or "balance". Second argument takes group-struct (resp. group-object later on).
    void display(std::string disp, Group & group);

    // creditor spends an amount of money for one or multiple debtors
    // TODO: invoke this spendAmout() function into program flow and test functionality.
    void spendAmount(double amountSpent, User &creditor, std::vector<User> userList);

    // Displays the Balance -> may be obsolete
    void displayBalance(Group group);

    // Calculates the Group balance
    void calcGroupBalance(std::string groupName);

    // Generates a CSV file of all users and their balances in the current folder. <fstream> header is used.
    void write_to_csv(std::vector<User> &userList,
                        std::string filename);

    Group& requestGroup(std::string groupName);

    User& requestUser(std::string userName);
};

#endif // MENUFUNCTIONS_H