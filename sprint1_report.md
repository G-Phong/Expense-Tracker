# Sprint 1 - Report
## Explanation of our code

In the first sprint the main functionality shall be implemented. 

What we did so far:
- User can create a user account, containing the name of the user and its personal money account.
- User can create a group. The group has a group name and the number of members should not be fixed.
- User balance can be displayed (e.g. printed in terminal). The user should see if they owe money or if they get money.

What **doesn't** work yet:
1. **User can join a group** -> There is some issue with references/pointers... we are not able to append the user.groups vector with the group in which the user should join -> joinGroup() functions does not work properly...
2. **User can add expenses to its group(s)** -> User can not add expenses as the user can not join the group (yet).

These issues are to be resolved in Sprint 2! We will invest more time then.

Also see "state_diagram_expTr.jpg" to see how our menu(s) work!
