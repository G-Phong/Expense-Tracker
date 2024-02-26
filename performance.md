# What did we do in order to increase the performance?

## Code optimizations
We changed different code sections and refactored some parts of our program to make it more efficient. Mostly we refactored loops to make less computations, made some variables and functions `const` and checked the memory allignment. 

We also made some bigger changes:

<details><summary>Group.cpp</summary>

- In line 136, inside the settleDebts()-method, we removed an unneccesary for-loop. 
</details>

<details><summary>MenuFunctions.cpp</summary>
- In Line 196 we replaced `std::endl` with `\n` in streams which consist of multiple parts which are appended. Example:

Instead of 

`std::cout << "Line1" << std::endl << "Line2" << std::endl;`

we replaced the `std::endl` in the middle by `\n`:

`std::cout << "Line1\n" << "Line2" << std::endl;`

**What is the difference?**

`\n` is a newline character that represents a line break in a text file or terminal output. It is used to separate lines of text.

`std::endl`, on the other hand, is a stream manipulator defined in the `<iostream>` library in C++. It not only inserts a newline character, **but it also flushes the output stream buffer**. This means that any pending output in the buffer is immediately written to the output device (e.g. the console or a file).

So, in terms of function, `\n` and `std::endl` are equivalent in that they both insert a line break, but `std::endl` has the added effect of flushing the stream buffer. **This can affect performance, as frequent flushing can slow down output.**

So this is the reason why we only use `std::endl` if really needed!
</details>

## Using gprof

Also we used **gprof** to analyze our program. Brief reminder of what gprof is: 
<details><summary>Explanation of gprof and how we used it</summary>

GNU gprof is a performance analysis tool for that provides information on the performance of C and C++ programs. It can help identify which parts of a program are taking the most time, which functions are being called the most frequently, and how the program is spending its time. This information can be used to optimize the performance of the program.

gprof works by using the binary executable generated from the source code and profiling it **as it runs**, i.e. you have to run the executable file first. Gprof records information about function calls, such as when a function starts and ends, and how many times it is called. This information is stored in a file called gmon.out which is created automatically if you add the `-pg`flag into your CMakeLists.txt. Read more about how to bind this flag into your CMake configuration [here](https://stackoverflow.com/questions/26491948/how-to-use-gprof-with-cmake).

We used the command `gprof ExpenseTracker gmon.out > profile-data.txt` to store the information of gmon.out into a human-readable format.
</details>

Find our profiling text file (`profile_data.txt`) in the ``/src`` folder of our repository.

**What did we observe using the results of gprof?**

We wanted to find out about which function is called very often. The first column of the flat profile displays 0.00% everywhere. We interpreted that there is no specific function which is using all the computation power or runtime. If we would find a function which uses like 40% of the runtime we would have a closer look on that specific function in order to find bottlenecks and optimization potentials. But this was not the case, so we decided to go through all the code to optimize what we can optimize.
