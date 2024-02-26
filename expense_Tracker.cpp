/*Authors: Gia-Phong Tran and Peter Riske
 *Topic: All functionality for the expense tracker project
 */

/*Information for reviewers:

We propose a structure for our project, containing all the relevant variables and functions.
Later on we will adjust the program by using object-orientation in C++.
We tried to comment on everything we implemented but this program code may still be a little confusing, sorry!
Some functions do not work properly right now and we plan to fix everything until Sprint 2/3.
This program is derived from the state machine diagram, which is appended in this repository.
See sprint1_log.md for more information.
There are surely better structures for this task but it is just the beginning, so please take it
with a grain of salt :-)


*/


#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// defining transactions
struct transaction
{
    std::string date;
    std::string recipient;
    std::string subject;
    double amount;
};

// defining user attributes
struct user
{
    std::string name;
    int age;
    std::vector<transaction> account; // includes transaction history
    double balance;                   // balance of all transactions
    std::vector<std::string> groups;  // list of groups the user is a part of
};

//user functions
void mainMenu();                 //displays login page
user getUser(std::string name);  //returns the user by its name
void userMenu(std::string name); //displaying and navigating through user functions
void userCreate();               //creating a new user
void display(std::string disp, user *userToBeDisplayed);  //display 

// defining groups
struct group
{
    std::string name;
    std::vector<user> participants;
    std::vector<transaction> account;
    std::map<user, double> balance;
};

//group functions
void groupMenu(std::string name);
void groupMenu(group group);
group getGroup(std::string name);
void createGroup();
void joinGroup(user *user, std::string groupName);
void g_editUsers(group);
void display(std::string disp, group group);

//global variables -> to be replaced in object-orientation part
std::vector<user> users;   // needs to be singular in all the project
std::vector<user> print;   // List for printing
std::vector<group> groups; // may be unnecessary

std::string currentUser; //needed?

//more functions
void displayBalance(group group);
void spendAmount(double amountSpent, user &creditor, std::vector<user> userList);
void calcGroupBalance(std::string groupName);
void write_to_csv(std::vector<user> &userList, std::string filename = "./ET_user_balances.csv");

// generating Login/sign up functions with main menu
void mainMenu()
{
    std::string uinput;

    // display menu in console
    std::cout << "********* Main Menu *********" << std::endl
              << "Please Press:" << std::endl
              << "(a) to log in" << std::endl
              << "(b) to sign up a new user" << std::endl;

    std::cin >> uinput; // read user input from console

    if (uinput == "a")
    {
        std::cout << "Login initialized. Please enter your username:" << std::endl;
        std::cin >> uinput;

        currentUser = uinput;

        userMenu(currentUser);
    }
    else if (uinput == "b")
    {
        std::cout << "Creating new user now. Please follow the instructions and enter your information" << std::endl;
        userCreate();
    }
    else
    {
        std::cout << "We detected a false input. Please make sure to answer with \"a\", \"b\" ";
        mainMenu();
    }
}

//Creates new user, prompts user for name and age
void userCreate()
{

    std::string uinput;
    int age;
    user user;

    std::cout << "Enter your name: ";

    std::cin >> uinput;
    user.name = uinput;

    std::cout << "Enter your age: ";

    std::cin >> age;

    user.age = age;
    user.balance = 0.0;

    users.push_back(user);

    std::cout << std::endl
              << "The user " << user.name << " has been created. Welcome to expense_tracker!" << std::endl
              << "To edit your account, sign up to a group or make transactions please log in to your account." << std::endl
              << "you are now being redirected to the main menu." << std::endl
              << std::endl;

    mainMenu();
}

// fetches a user by name, return type of struct 'user'
user getUser(std::string name)
{

    std::string uinput;
    std::string newName;

    for (auto usr : users)
    {
        if (usr.name == name)
        {
            return usr;
        }
    }

    std::cout << "User not found. Do you want to retry (r) or create a new user (n)?" << std::endl;

    std::cin >> uinput;

    if (uinput == "r")
    {

        std::cout << "Please retype user name: " << std::endl;

        std::cin >> newName;

        for (auto usr : users)
        {
            if (usr.name == newName)
            {
                return usr;
            }
        }
    }
    else if (uinput == "n")
    {
        std::cout << "Creating new user..." << std::endl;
        userCreate(); // create new user
    }
    else
    {

        std::cout << "We detected a false input. Please make sure to answer with \"r\", \"n\" " << std::endl;
    }

    user defaultUser;
    return defaultUser; // user is then empty but would probably still work.
}

// generating user menu to navigate the functionality
void userMenu(std::string name)
{ // argument could be a UserObject later on -> menu is specific for a user (e.g. Mario's menu)
    user user = getUser(name);
    std::string uinput;

    std::cout << std::endl << "******** " << user.name << "\'s menu ********" << std::endl
              << "******** Your balance is: " << user.balance << " ********" << std::endl
              << "Please Press:" << std::endl
              << "(a) to create a group" << std::endl
              << "(b) to join a group" << std::endl
              << "(c) to display the group(s) you joined" << std::endl
              << "(d) to see the history of your transactions" << std::endl
              << "(e) to print all information to a .csv file" << std::endl
              << "(f) to log out" << std::endl;

    std::cin >> uinput;

    if (uinput == "a")
    {
        createGroup(); // creating a group
    }
    else if (uinput == "b")
    {
        std::string groupToJoin;

        std::cout << "Please enter the name of the group you want to join: " << std::endl;

        std::cin >> groupToJoin;

        joinGroup(&user, groupToJoin); // joinGroup with user name as input (TODO: could be userObject)
    }
    else if (uinput == "c")
    {
        // displays balance and enables user to choose friends and pay their debt
        display("groups", &user);
    }
    else if (uinput == "d")
    {
        // history of transactions
    }
    else if (uinput == "e")
    {
        print.clear();
        print.push_back(user);
        write_to_csv(print); // prints all user related info to a .csv file
    }
    else if (uinput == "f")
    {
        mainMenu();  //opens main menu and thus logs out the user
    }
    else
    {
        std::cout << "We detected a false input. Please make sure to answer with \"a\", \"b\", \"c\", \"d\" ";
        userMenu(currentUser);
    }
}

//Creates a new group, prompts user for a name
void createGroup()
{

    std::string uinput;
    group newGroup;

    std::cout << "Enter your group name: ";

    std::cin >> uinput;
    newGroup.name = uinput;

    std::string name;

    while (name != "d")
    {
        name = "";
        std::cout << std::endl
                  << "Enter a participant or \"d\" if you are done adding users: ";
        //std::string name;
        std::cin >> name;
        if(name != "d"){
            newGroup.participants.push_back(getUser(name));
            user user = getUser(name);
            user.groups.push_back(newGroup.name);
        }
        
    }

    groups.push_back(newGroup); // doesn't work!

    std::cout << std::endl
              << "The group " << newGroup.name << " has been created for you." << std::endl
              << "You can now switch to your new group." << std::endl;

    userMenu(currentUser);
}

// adds an entry into user.groups vector and into groups.participants vector.
// Here we unfortunately still have issues with appending to the correct user.group vector! TODO: FIX!
// Maybe some reviewer knows why this function does not add a group to the user.groups vector?
void joinGroup(user *user, std::string groupName)
{ //Something wrong with this pointer? I'm sure here's some problem with references/pointer

    //getUser(userName).groups.push_back(groupName);

    //auser->groups.push_back(groupName);
    
    //std::cout << getUser(userName).name << std::endl;
    

    for (auto group : groups)
    {
        if (group.name == groupName)
        {
            group.participants.push_back(*user); // add user to participants-vector -> add user to group
            user->groups.push_back(groupName);

            std::cout << "User " << user->name << " successsfully joined the group: " << group.name << ", #participants: " << group.participants.size() << std::endl;
        }
    }

    for(auto group : user->groups){
        std::cout << "Groups of user " << user->name << ": " << group << std::endl;
    }

    userMenu(currentUser);
}

//First argument takes "groups" or "transactions". Second argument takes user-struct.
void display(std::string disp, user *userToBeDisplayed)
{
    //user userToBeDisplayed = getUser(userName);

    if (disp == "groups")
    {
        std::string uinput;
        std::cout << "Your groups: " << std::endl;

        for (std::string grp : userToBeDisplayed->groups)
        {
            std::cout << grp << std::endl;
        }

        if(userToBeDisplayed->groups.size()== 0){
            std::cout << "User " << userToBeDisplayed->name << " didn't join any group yet! Size: " << userToBeDisplayed->groups.size() << std::endl;
            userMenu(currentUser);
        }

        std::cout << "Please select a group by typing its name." << std::endl;
        std::cin >> uinput;

        groupMenu(uinput);
    }
    else if (disp == "transactions")
    {
        std::string uinput;
        std::cout << "Your Transactions" << std::endl
                  << "Date        Subject        Recipient        Amount" << std::endl;

        for (auto trac : userToBeDisplayed->account)
        {
            std::cout << trac.date << "   " << trac.subject << "   " << trac.recipient << "   " << trac.amount << std::endl;
        }

        std::cout << "Your current balance:" << userToBeDisplayed->balance << std::endl;
    }
}

//helper function, you can pass the name of a group here
void groupMenu(std::string name)
{
    group group = getGroup(name);
    groupMenu(group);
}

//This function takes a group-struct as input (later on it will be an object) and opens the group menu
void groupMenu(group group)
{
    std::string uinput;

    std::cout << "******** " << group.name << " group menu ********" << std::endl
              //<< "******** Your balance is: " << group.balance << " ********" << std::endl
              << "Please Press:" << std::endl
              << "(a) to display, add or delete members" << std::endl
              << "(b) to see the history of the groups transactions" << std::endl
              << "(c) to add a transaction" << std::endl
              << "(d) to pay of debt to your friends" << std::endl
              << "(e) to print all information to a .csv file" << std::endl
              << "(f) to go to the main menu" << std::endl;

    std::cin >> uinput;

    if (uinput == "a")
    {
        g_editUsers(group);
    }
    else if (uinput == "b")
    {
        display("transactions", group); // displaying all transactions where the user participated
    }
    else if (uinput == "c")
    {
        // newTransaction(); navigates to transaction menu
    }
    else if (uinput == "d")
    {
        // displays balance and enables user to choose friends and pay their debt
    }
    else if (uinput == "e")
    {
        write_to_csv(group.participants); // prints all user related info to a .csv file
    }
    else if (uinput == "f")
    {
        // openMenu();  //opens main menu and thus logs out the user
    }
    else
    {
        std::cout << "We detected a false input. Please make sure to answer with \"a\", \"b\", \"c\", \"d\", \"e\" or \"f\" ";
        groupMenu(group.name);
    }
}

//returns group struct
group getGroup(std::string name)
{
    for (auto grp : groups)
    {
        if (grp.name == name)
        {
            return grp;
        }
    }
    std::cout << "Group not found. Please create a new group." << std::endl;

    createGroup();

    group group;
    return group; // empty group
}

//Allows to edit users in a certain group.
void g_editUsers(group group)
{
    std::string uinput;

    display("users", group); // displaying groups and ability to navigate to one of them

    std::cout << "Please press: " << std::endl
              << "(a) to add a user " << std::endl
              << "(b) to delete a user " << std::endl
              << "(c) to go back to the menu" << std::endl;

    std::cin >> uinput;

    if (uinput == "a")
    {
        std::cout << "Enter the name of the new user: " << std::endl;
        std::cin >> uinput;
        user user = getUser(uinput);
        group.participants.push_back(user);
    }
    else if (uinput == "b")
    {
        std::cout << "Enter the name of the user that should be deleted: " << std::endl;
        std::cin >> uinput;
        user user = getUser(uinput);
        //        int index = std::find(group.participants, user);
        //        group.participants.remove(index);
    }
    else if (uinput == "c")
    {
        // groupMenu();
    }
    else
    {
        std::cout << "We detected a false input. Please make sure to answer with \"a\", \"b\" or \"c\" " << std::endl;
        g_editUsers(group);
    }
}

//First argument takes "users" or "transactions" or "balance". Second argument takes group-struct (resp. group-object later on).
void display(std::string disp, group group)
{
    if (disp == "users")
    {
        std::string uinput;
        std::cout << "Group users" << std::endl;

        for (auto usr : group.participants)
        {
            std::cout << usr.name << std::endl;
        }
    }
    else if (disp == "transactions")
    {
        std::string uinput;
        std::cout << "Your Transactions" << std::endl
                  << "Date        Subject        Recipient        Amount" << std::endl;

        for (auto trac : group.account)
        {
            std::cout << trac.date << "   " << trac.subject << "   " << trac.recipient << "   " << trac.amount << std::endl;
        }
    }
    else if (disp == "balance")
    {
        std::cout << "Name : Deviation from what they should have paid" << std::endl;
        for (auto deb : group.balance)
        {
            std::cout << deb.first.name << " : " << deb.second << std::endl;
        }
    }
}

// creditor spends an amount of money for one or multiple debtors
//TODO: invoke this spendAmout() function into program flow and test functionality.
void spendAmount(double amountSpent, user &creditor, std::vector<user> userList)
{ // return type boolean?
    if (amountSpent <= 0)
    { // amount to be spent must be a positive amount of money!
        std::cout << "The amount you typed in is: " << amountSpent << ", but should be greater than 0! Returning to main menu."
                  << std::endl;
    }
    else
    {
        creditor.balance += amountSpent; // increment the balance of the creditor

        for (auto debtor : userList)
        {
            debtor.balance -= amountSpent / userList.size(); // equal debt for every debtor (inequal debts not available yet..)
        }
    }
}

// Displays the Balance -> may be obsolete
void displayBalance(group group)
{
    std::cout << "******** Balance of Group " << group.name << " ********* " << std::endl;
}

// Calculates the group balance
void calcGroupBalance(std::string groupName)
{
    // TODO: Output should be printed to terminal in a structured way. One should see who owes how much to whom.
}

// Generates a CSV file of all users and their balances in the current folder. <fstream> header is used.
void write_to_csv(std::vector<user> &userList,
                  std::string filename)
{
    // Copy&Paste from exercise

    // open file stream for output
    std::ofstream csv_file(filename);

    // csv column headers
    csv_file << "user,balance\n";

    for (auto usr : userList)
    {

        /* We can write to a file in the same way as we write to std::cout.
         * This is because both are implemented as "streams"
         *
         * We do not need to pass the "countries" array to our
         * "function" since it is global. Avoid doing this,
         * we will learn better ways to organize our code later.
         */
        csv_file << usr.name << "," << usr.balance << "\n";
    }

    csv_file.close();
}

int main()
{
    //Test data
    user userMario;
    userMario.age = 50;
    userMario.balance = 3000.7;
    userMario.name = "Mario";

    currentUser = userMario.name;

    users.push_back(userMario);

    group urlaub;
    urlaub.name = "urlaub";

    groups.push_back(urlaub);
    userMario.groups.push_back(urlaub.name);

    //joinGroup(userMario, urlaub.name); //hereafter the state machine starts already

    //only for debugging
    for(auto group : userMario.groups){
        std::cout << group << std::endl;
    }

    //display("groups", userMario.name);
    
    std::cout << "Entering Main menu now: " << std::endl;

    //here the state machine starts
    mainMenu();

    return 0;
}
