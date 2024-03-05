/*Authors: Gia-Phong Tran and Peter Riske
 *Topic: All functionality for the expense tracker project
 */

#include <fstream>
#include <map>
#include <algorithm>

#include "Group.h"
#include "User.h"
#include "Account.h"
#include "MenuFunctions.h"

// Define global variables
std::vector<User> users;
std::vector<Group> groups;

int main()
{
    // DEBUGGING:
    // Creating test users -> take care of how you call the constructor!

    std::cout << "Creating test data..." << std::endl;

    User Mario(50, "Mario");
    users.push_back(Mario);
    //std::cout << "New User: " << Mario.getName() << " (" << Mario.getAge() << ")" << std::endl;

    User Phong(24, "Phong");
    users.push_back(Phong);
    //std::cout << "New User: " << Phong.getName() << " (" << Phong.getAge() << ")" << std::endl;

    User Peter(26, "Peter");
    users.push_back(Peter);
    //std::cout << "New User: " << Peter.getName() << " (" << Peter.getAge() << ")" << std::endl;

    User A(50, "A");
    users.push_back(A);
    User B(50, "B");
    users.push_back(B);
    User C(50, "C");
    users.push_back(C);

    Group Urlaub("Urlaub");
    groups.push_back(Urlaub);
    Mario.joinGroup(Urlaub);
    Phong.joinGroup(Urlaub);
    Peter.joinGroup(Urlaub);
    //Urlaub.addMember(Mario);
    //Urlaub.addMember(Phong);
    //Urlaub.addMember(Peter);
    Urlaub.printAccBalances();
    Phong.printGroups();
    
    std::cout << "__________END OF TEST DATA__________" << std::endl;
    std::cout << "Entering main menu now: " << std::endl;

    // Init MenuFunctions
    MenuFunctions Controller = MenuFunctions();

    // here the state machine starts
    Controller.mainMenu();

    return 0;
}
