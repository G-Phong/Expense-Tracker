# Sprint 3 - Report
## What did we change?

In this Sprint we focused on performance optimization. Goal of this sprint was to analyze the performance of our code and to find and implement better code.

Therefore we did two things:
1. **Analyze the performance using GNU gprof**

We explained how we used gprof in `performance.md`. We found out that there is no function which has a significantly high amount of calls. The function called most frequently is std::forward() as the gprof flat profile says that the function `User const& std::forward<User const&>(std::remove_reference<User const&>::type&)` has the highest amount of calls (71) in our program execution (see `profile_data.txt` in `/src`).

2. **Improve our code by using optimizations which were presented in the lecture.**

Knowing from the gprof profile, that there is no specific function which is called a lot we decided to just go through all of our code and check if there is something we can optimize.
In the end, we mainly made some variables `const`, checked the memory allignment and refactored for-loops to save some computation. There is not a lot to optimize but we still optimized little things.


## What did we not do (unfortunately)?

Due to our side-jobs and other academical duties we did not have a lot of time for Sprint 3 (we guess you guys can relate as the exam period is very soon). So we decided to drop certain points:

- **Read in CSV file to restore data**: Of course this function is important because it provides us with _saved states_, i.e. we do not have to restore our history manually every time we start our program, instead we just load the history from a CSV file. This function has a lot to do with reading and writing onto streams. To load an existing saved state (=history) we have to read out the CSV carefully, also the CSV file should not contain any error. After hours of debugging we received some errors (e.g. Segmentation fault) and couldn't help ourselves. So we decided not to implement this function anymore. Maybe some other student of the next semesters can solve that problem, we would love to hear from you or from your pull requests!
- **Auto-generated CSV file with test data**: Our initial idea was to create (or let create) a huge CSV-file with many users and groups and expenses. Purpose of that is to test our program and to analyze the performance of our program for large data sets. As we didn't finish our CSV-functions it does not make sense to create this CSV-file, so we decided to drop that point.
- **Understanding the error in main()**: We created a test data set in main() consisting of multiple users who join a group. Somehow after calling mainMenu() the users created are not part of the group they joined. We spent hours of thinking about that but we could not resolve that. So we did not spent further time on that.
- **Editing users**: We thought about introducing a functionality to edit users and groups (e.g. changing names and removing users). In the end we decided to not implement this because it is not part of the main functionality of the ExpenseTracker, it is more of an extra-function which would be nice to have. Also this functionality would create overhead as we would have to check if names have changed, if the user list changed... and so on. As this program is just for educational purposes we wanted to keep efforts low on aspects which do not provide further learning effect.

