# Sprint 2 -  Report
## What did we change in the program?
In this sprint we splitted our code from version1 into multiple classes:

| C++ File | Functionality |
| ------ | ------ |
|    Account.cpp / Account.h    |    An account contains a balance. You can read the balance of an account.    |
|    Group.h / Group.cpp    |    A group has a name and it contains members / users.    |
|    User.cpp / User.h    |    A user has an age, a name, a personal account and a vector of shared pointers to Group objects. The latter keeps track of the groups in which the user is a member.   |
|    MenuFunctions.cpp / MenuFunctions.h    |    The MenuFunctions class contains the guidance through the terminal menu (as the Expense Tracker is a command-line based program).    |
|    main.cpp    |    The `main.cpp` file initializes the menu and runs the whole program.    |

Furthermore we realized the functionality of **transactions**. A user can now make a transaction, i.e. spend a certain amount of money to one or multiple users. This transaction has impact on the balances which are affected by the transaction. Every transaction is stored into .... Users can now make transactions in every group they are part of.

A user can now print his/her personal balance and the group balance where he/she is into. 

We included the headers into `main.cpp` which is much shorter than before. For debugging and testing purposes we created a user in our main function to test some functionality. The program is now ready to use.

Please also have a look into the UML class diagram that we provided in order to understand our program better.

## Settle debts of a group
Main functionality of the Expense Tracker is the feature which allows you to print an overview of the debts. In the end the user of the Expense Tracker of course wants to know who he/she has to pay back resp. who owes him/her a certain amount of money. In our application it will be printed onto the terminal in a structured way, e.g.:

Status of the group accounts:
> Alice account: +150

> Bob account: +200

> Mallory account: -350

After using our algorithm to settle debts:
> Mallory pays 150€ to Alice.

> Mallory pays 200€ to Bob.


This functionality is implemented in the method `Group::settleDebts()`. This method analyzes the group accounts of all users (organized in a `std::map` container) and uses a very simple algorithm to settle the debts. Of course such algorithms can become more complex, if you're interested then read more about [Algorithm Behind Splitwise’s Debt Simplification Feature](https://medium.com/@mithunmk93/algorithm-behind-splitwises-debt-simplification-feature-8ac485e97688). Spoiler: This problem is NP-complete and can be modeled as a directed graph.

We implemented a very simple algorithm as follows:
- We split the group members into two different vectors: debtors and creditors
- debtors = members who owe money to the creditors
- creditors = members who get money from the debtors
- We iterate through both vectors and make transactions from a certain debtor to a certain creditor. There's no specific order, we just iterate through both vectors, we do not sort them before to keep it simple.
- Depending on the result of following expression (pseudo-code) we determine the amount of the money which is transacted: 

`If abs(debtor.balance) < abs(creditor.balance) then transactionAmount = debtor.balance else transactionAmount = creditor.balance.`

- After that operation at least one member will have a balance of 0.
- After each operation we print a reimbursement statement which could look like follows: 
> Alice pays 50 to Bob.
- We repeat this operation until all balances equal to 0 (they have to!)
- After using this algorithm we expect that all necessary reimbursements are shown on the terminal, so all members know how to pay back the other group members.

**But is this a good algorithm?** It depends.

A reasonable **optimization criterum** could be: **Minimize the amount of payments in the reimbursement process.**
You want to have as less reimbursement payments as possible to simplify the reimbursement process.

As we want to keep this program (and programming task) as simple as possible we decided to rather implement an easy algorithm which fulfills its function without having the expectation of always reaching an optimal solution. Our goal is to implement the C++ skills learned in the lecture instead of spending days and nights optimizing this algorithm (which indeed would be a very interesting exercise).

A reimbursement function can be added in further software updates, but is not part of our implementation. The group members should handle the reimbursement by themselves (e.g. paying back via a service payment provider and after reimbursing, one can close their group account for instance...).

For an example of our settleDebts-algorithm please check our `settleDebts.pdf`.

## What else did we do?
We added functionality to save User related information to a csv file. The function User::writeUserCsv() creates said .csv and saves it to /(&username)_info.csv. 
There is also a function to save all system information to a csv file. It first saves a list of Users and then saves all important data for every group. Functionality to read in this file to setup the system is planned and can be found in MenuFunctions::mainMenu() under the letter "d", but is not yet ready for usage.

The system csv file is set up like this: 
>Users list

>Group1_name

>  member1:account1 of Group1
>
>  ...
>
>  memberN:accountN of Group1

>  transaction1 of Group1
>
>  ...
>
>  transactionN of Group1

>...

>GroupN_name
>
>...





In addition, we added a CMakeLists.txt file in order to automatically create a Makefile which will compile the code.
As an alternative we also delivered a Makefile in the `/src` subdirectory.

Also, we added some more documentation concerning the build process and some information about the project itself  (`ProjectDescription.md` and `README.md`).



