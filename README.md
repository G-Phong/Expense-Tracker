# Introduction: Expense Tracker 
## What is this project about?
This is a bonus project from Gia-Phong Tran <giaphong.tran@tum.de> and Peter Riske <peter.riske@tum.de> for the course Advanced Programming WS22/23 from TUM. We came up with our own project idea and this repository contains our solution. Please read `ProjectDescription.md` for further details about the project. Also have a look into `sprint2_report.md` for details about what we did in Sprint 2.

## How do I use this repository and how do I build this project?
To compile the Expense Tracker you need [CMake](https://cmake.org/). Please install CMake on your platform. Then fork this repository to your Linux machine.

### Compilation with CMake
From this repository that you forked, create a `build` folder and switch into it:

`mkdir build && cd build`

In the `build` directory run the following command to create a Makefile from the CMakeLists.txt:

`cmake ..`

and then run

`make`

to compile from the new Makefile which CMake placed into the `build` directory.

Have a look into CMakeLists.txt and then into the Makefile to check if everything went well. If `make` finished without errors, then you have successfully compiled the Expense Tracker. Congratulations!

### Alternative: Compilation with the Makefile given

Alternatively you can use the Makefile in the `/src` directory. Just run `make` in the directory to compile the project.

After compiling, you can run the program:

 `./ExpenseTracker` 
