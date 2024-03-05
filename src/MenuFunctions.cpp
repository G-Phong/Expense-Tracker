#include "MenuFunctions.h"
#include "User.h"
#include "Group.h"
#include <fstream>

Group &MenuFunctions::requestGroup(std::string groupName)
{
    for (auto &group : groups)
    {
        if (group.getName() == groupName)
        {
            return group;
        }
    }
}

User &MenuFunctions::requestUser(std::string userName)
{
    for (User &user : users)
    {
        if (user.getName() == userName)
        {
            return user;
        }
    }
}

MenuFunctions::MenuFunctions() {}

// generating Login/sign up functions with main menu
void MenuFunctions::mainMenu()
{
    std::string uinput;

    // display menu in console
    std::cout << "********* Main Menu *********\n"
              << "Please Press:\n"
              << "(a) to log in\n"
              << "(b) to sign up a new user\n"
              << "(c) to display all users (we don't care about data privacy) \n" 
              << "(d) to load tracking data from csv file \n"
              << "(e) to save tracking data to a csv file \n"
              << "(x) to exit the program." << std::endl;

    std::cin >> uinput; // read user input from console

    if (uinput == "a")
    {
        std::cout << "Login initialized. Please enter your username:" << std::endl;
        std::cin >> uinput;

        for (User &user : users)
        {
            if (user.getName() == uinput)
            {
                userMenu(user);
            }
        }

        std::cout << "User not found. Please retry!" << std::endl;
        mainMenu();
    }
    else if (uinput == "b")
    {
        std::cout << "Creating new user now. Please follow the instructions and enter your information" << std::endl;
        userCreate();
    }
    else if (uinput == "c")
    {
        std::cout << "Displaying all users: " << std::endl;
        for (int i = 0; i < users.size(); i++)
        {
            std::cout << users[i].getName() << std::endl;
        }

        mainMenu();
    }
    else if(uinput == "d")
    {
        std::string fname, path;
        
        std::cout << "Please enter the name of the file: \n"; //to be "xyz.csv"
        std::cin >> fname;

        path = "../saveStates/" + fname;
        std::fstream openSys;
        openSys.open(path);

        //TODO: Open parse csv and build system. (Best from transactions...for every new user and group create new)
        std::vector<std::vector<std::string>> content;
        std::vector<std::string> row;
        std::string line, word;

        //reading in data from csv
        while(getline(openSys, line)){
            row.clear();
            std::stringstream str(line);
            
            while(getline(str, word, ',')){
                row.push_back(word);
            }
            content.push_back(row);
        }

        //setting up the system from the data
        //create users
        int i = 0;
        while(content[i].size() == 3){
            User tmp(std::stoi(content[i][1]), content[i][0]);
            tmp.getAccount().transfer(std::stof(content[i][2]));
            users.push_back(tmp);
            i++;
        }

        //create groups
        for(int j = i; j < content.size(); j++){
            if(content[j].size() == 1){
                //iterate over content[i+1] and content[i+2] to create map
                Group tmp(content[j][0]);
                for(int k = 0; k < content[j+1].size(); k++){
                    tmp.addMember(requestUser(content[j+1][k]));
                    //tmp.getMap()[k].second.transfer(std::stof(content[j+2][k])); //should probably be a reference of the map
                }
            }
            else if(content[j].size() == 4){

            }
        }

        openSys.close();
    }
    else if(uinput == "e")
    {
        std::string fname, path;
        
        std::cout << "Please enter the desired file name: \n";
        std::cin >> fname;

        fname += ".csv";
        path = "../savedStates/" + fname;

        std::ofstream saveSys;
        saveSys.open(path);

        //display list of users
        for(auto usr : users){
            saveSys << usr.getName() << "," << usr.getAge() << "," << usr.getBalance() << usr.getAccount().getBalance() << "\n";
        }
        saveSys << "\n";

        //save Group infos
        for(auto grp : groups){
            saveSys << grp.getName() << "\n";
            //save member:account pairs
            for(auto & mbr : grp.getMap()){
                saveSys << mbr.first->getName();
            }
            for(auto & mp : grp.getMap()){
                saveSys << mp.second->getBalance();
            }
            saveSys << "\n";
            //save all groups transactions
            for(auto tra : grp.getTransactions()){
                saveSys << tra.getCreditor().getName() << ","
                        << tra.getDebtor().getName() << ","
                        << tra.getSubject() << ","
                        << tra.getAmount() << "\n";
            }
        }
        saveSys.close();
    } else if(uinput == "x"){
        return;
    }
    else
    {
        std::cout << "We detected a false input. Please make sure to answer with \"a\", \"b\", \"c\" ";
        mainMenu();
    }
}

// Creates new user, prompts user for name and age
void MenuFunctions::userCreate()
{

    std::string name;
    int age;

    std::cout << "Enter your name: ";

    std::cin >> name;

    std::cout << "Enter your age: ";

    std::cin >> age;

    // Add user to the global users vector
    users.push_back(User(age, name));

    std::cout << "\n"
              << "The user " << name << " has been created. Welcome to expense_tracker!\n"
              << "To edit your account, sign up to a group or make transactions please log in to your account.\n"
              << "you are now being redirected to the main menu.\n"
              << std::endl;

    mainMenu();
}

// generating user menu to navigate the functionality
void MenuFunctions::userMenu(User &user)
{
    std::string uinput;

    std::cout << "\n"
              << "******** " << user.getName() << "\'s menu ********\n"
              << "******** Your balance is: " << user.getBalance() << " ********\n"
              << "Please Press:\n"
              << "(a) to create a group\n"
              << "(b) to join a group\n"
              << "(c) to display the group(s) you joined\n"
              << "(c*) to display all existing groups\n"
              << "(d) to switch to one of your groups\n"
              << "(e) to see the history of your transactions\n"
              << "(f) to print all information to a .csv file\n"
              << "(g) to log out and go back to the main menu" << std::endl;

    std::cin >> uinput;

    if (uinput == "a")
    {
        createGroup(user); // creating a group
    }
    else if (uinput == "b")
    {
        std::string groupToJoin;

        std::cout << "Please enter the name of the group you want to join: " << std::endl;

        std::cin >> groupToJoin;

        Group &groupJoin = requestGroup(groupToJoin);

        user.joinGroup(groupJoin);
    }
    else if (uinput == "c")
    {
        // displays groups the user joined
        user.printGroups();
    }
    else if (uinput == "c*")
    {
        // displays all groups
        std::cout << "Displaying all groups in ExpenseTracker: " << std::endl;

        for (auto &group : groups)
        {
            std::cout << group.getName() << std::endl;
        }
    }
    else if (uinput == "d")
    {
        // switch to a group
        std::cout << "Here are the groups you joined: " << std::endl;
        user.printGroups();

        std::cout << "Type the group name you want to switch to: " << std::endl;

        std::string uinput;
        std::cin >> uinput;
        Group &groupToSwitch = requestGroup(uinput);

        //Instead of using a bool flag we directly switch to groupMenu if the group was found.
        //This allows us to save some if-evaluations, it only helps if the group is not the last element in the group-vector
        for (int i = 0; i < user.getGroups().size(); i++)
        {
            if (groupToSwitch.getName() == user.getGroups()[i]->getName())
            {
                std::cout << "Switching to group " << groupToSwitch.getName() << " ..." << std::endl;
            groupMenu(groupToSwitch, user);
            }
        }
            std::cout << user.getName() << " is not member of the group " << groupToSwitch.getName() << std::endl;
            std::cout << "Returning back to user menu. Please try again!" << std::endl;
            userMenu(user);
        
    }
    else if (uinput == "e")
    {
        // history of transactions
    }
    else if (uinput == "f")
    {
        user.writeUserCsv();
    }
    else if (uinput == "g")
    {
        mainMenu(); // opens main menu and thus logs out the user
    }
    else
    {
        std::cout << "We detected a false input. Please make sure to answer with \"a\", \"b\", \"c\", \"d\" ";
        userMenu(user);
    }
    // State machine
    userMenu(user);
}

// Creates a new group, prompts user for a name
void MenuFunctions::createGroup(User &user)
{

    std::string uinput;

    std::cout << "Enter your group name: ";

    std::cin >> uinput;

    std::string groupName = uinput;

    Group newGroup(groupName);

    while (uinput != "d")
    {
        uinput = "";
        std::cout << std::endl
                  << "Enter a participant or \"d\" if you are done adding users: ";

        std::cin >> uinput;
        if (uinput != "d")
        {
            //newGroup.addMember(requestUser(uinput)); //not needed because joinGroup() will already do it
            requestUser(uinput).joinGroup(newGroup);
        }
    }

    groups.push_back(newGroup); // does this work?

    std::cout << "\n"
              << "The group " << newGroup.getName() << " has been created for you.\n"
              << "You can now switch to your new group." << std::endl;

    userMenu(user);
}

// This function takes a group-struct as input (later on it will be an object) and opens the group menu
void MenuFunctions::groupMenu(Group &group, User &user)
{
    std::string uinput;

    std::cout << "******** " << group.getName() << " group menu ********\n"
              << "******** Logged in user: " << user.getName() << " ********\n"
              << "Please Press:\n"
              << "(a) to display, add or delete members\n"
              << "(b) to see the history of the groups transactions\n"
              << "(c) to add a transaction\n"
              << "(d) to see all member account balances\n"
              << "(d*) to settle all debts of this group\n"
              << "(e) to print all information to a .csv file\n"
              << "(f) to go back to the user menu\n"
              << "(g) to log out and go back to the main menu" << std::endl;

    std::cin >> uinput;

    if (uinput == "a")
    {
        //we decided not to implement this because we don't have a so much time and it's just an extra function...
    }
    else if (uinput == "b")
    {
        display("transactions", group); // displaying all transactions where the user participated
        groupMenu(group, user);
    }
    else if (uinput == "c")
    {
        //add a transaction
        std::cout << "What did you pay for the group " << group.getName() << "? \n Please type the purpose of your spending: " << std::endl;

        std::string uinput_payReason;
        std::cin >> uinput_payReason;

        std::cout << "How much did you spent? (it will be spent for the whole group) \n Please type: " << std::endl;

        double uinput_amount;
        std::cin >> uinput_amount;

        group.addTransaction(user, group, uinput_payReason, uinput_amount);

        std::cout << "Transaction was made. Returning to group menu now." << std::endl;

        groupMenu(group,user);
    }
    else if (uinput == "d")
    {
        //Show all member account balances
        group.printAccBalances();

        //printing the debts -> resolve who pays what to who!
        //group.settleDebts();

        groupMenu(group, user);
    }
    else if (uinput == "d*")
    {
        //settle Debts
        group.settleDebts();

        groupMenu(group, user);
    }
    else if (uinput == "e")
    {
        // write_to_csv(group.getMembers()); // prints all user related info to a .csv file
    }
    else if (uinput == "f")
    {
        // returning to user menu
        std::cout << "Switching back to " << user.getName() << " user menu..." << std::endl;
        userMenu(user);
    }
    else if (uinput == "g")
    {
        // returning to main menu
        std::cout << "Switching back to main menu..." << std::endl;
        mainMenu();
    }
    else
    {
        std::cout << "We detected a false input. Please make sure to answer with \"a\", \"b\", \"c\", \"d\", \"e\" or \"f\" ";
        groupMenu(group, user);
    }
}

// Allows to edit users in a certain group.
/* void g_editUsers(group group)
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
} */

// First argument takes "users" or "transactions" or "balance". Second argument takes group-struct (resp. group-object later on).
void MenuFunctions::display(std::string disp, Group &group)
{
    if (disp == "users")
    {
        std::string uinput;
        std::cout << "Group users" << std::endl;

        for (auto &usr : group.getMembers())
        {
            std::cout << usr->getName() << std::endl;
        }
    }
    else if (disp == "transactions")
    {
        group.printTransactions();
    }
    else if (disp == "balance")
    {
        /*  std::cout << "Name : Deviation from what they should have paid" << std::endl;
         for (auto deb : group.balance)
         {
             std::cout << deb.first.name << " : " << deb.second << std::endl;
         } */
    }
};

// Generates a CSV file of all users and their balances in the current folder. <fstream> header is used.
/* void write_to_csv(std::vector<User> &userList,
                  std::string filename)
{
    // Copy&Paste from exercise

    // open file stream for output
    std::ofstream csv_file(filename);

    // csv column headers
    csv_file << "user,balance\n";

    for (auto & usr : userList)
    {

        //  We can write to a file in the same way as we write to std::cout.
        //  This is because both are implemented as "streams"
        //
         // We do not need to pass the "countries" array to our
        //  "function" since it is global. Avoid doing this,
        //  we will learn better ways to organize our code later.


        csv_file << usr.name << "," << usr.balance << "\n";
    }

    csv_file.close();
} */
