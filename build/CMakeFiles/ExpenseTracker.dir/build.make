# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/riskypete/Projects/expenses/expense_tracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/riskypete/Projects/expenses/expense_tracker/build

# Include any dependencies generated for this target.
include CMakeFiles/ExpenseTracker.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ExpenseTracker.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ExpenseTracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ExpenseTracker.dir/flags.make

CMakeFiles/ExpenseTracker.dir/src/main.cpp.o: CMakeFiles/ExpenseTracker.dir/flags.make
CMakeFiles/ExpenseTracker.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/ExpenseTracker.dir/src/main.cpp.o: CMakeFiles/ExpenseTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ExpenseTracker.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExpenseTracker.dir/src/main.cpp.o -MF CMakeFiles/ExpenseTracker.dir/src/main.cpp.o.d -o CMakeFiles/ExpenseTracker.dir/src/main.cpp.o -c /home/riskypete/Projects/expenses/expense_tracker/src/main.cpp

CMakeFiles/ExpenseTracker.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExpenseTracker.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riskypete/Projects/expenses/expense_tracker/src/main.cpp > CMakeFiles/ExpenseTracker.dir/src/main.cpp.i

CMakeFiles/ExpenseTracker.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExpenseTracker.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riskypete/Projects/expenses/expense_tracker/src/main.cpp -o CMakeFiles/ExpenseTracker.dir/src/main.cpp.s

CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o: CMakeFiles/ExpenseTracker.dir/flags.make
CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o: ../src/Account.cpp
CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o: CMakeFiles/ExpenseTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o -MF CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o.d -o CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o -c /home/riskypete/Projects/expenses/expense_tracker/src/Account.cpp

CMakeFiles/ExpenseTracker.dir/src/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExpenseTracker.dir/src/Account.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riskypete/Projects/expenses/expense_tracker/src/Account.cpp > CMakeFiles/ExpenseTracker.dir/src/Account.cpp.i

CMakeFiles/ExpenseTracker.dir/src/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExpenseTracker.dir/src/Account.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riskypete/Projects/expenses/expense_tracker/src/Account.cpp -o CMakeFiles/ExpenseTracker.dir/src/Account.cpp.s

CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o: CMakeFiles/ExpenseTracker.dir/flags.make
CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o: ../src/Group.cpp
CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o: CMakeFiles/ExpenseTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o -MF CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o.d -o CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o -c /home/riskypete/Projects/expenses/expense_tracker/src/Group.cpp

CMakeFiles/ExpenseTracker.dir/src/Group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExpenseTracker.dir/src/Group.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riskypete/Projects/expenses/expense_tracker/src/Group.cpp > CMakeFiles/ExpenseTracker.dir/src/Group.cpp.i

CMakeFiles/ExpenseTracker.dir/src/Group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExpenseTracker.dir/src/Group.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riskypete/Projects/expenses/expense_tracker/src/Group.cpp -o CMakeFiles/ExpenseTracker.dir/src/Group.cpp.s

CMakeFiles/ExpenseTracker.dir/src/User.cpp.o: CMakeFiles/ExpenseTracker.dir/flags.make
CMakeFiles/ExpenseTracker.dir/src/User.cpp.o: ../src/User.cpp
CMakeFiles/ExpenseTracker.dir/src/User.cpp.o: CMakeFiles/ExpenseTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ExpenseTracker.dir/src/User.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExpenseTracker.dir/src/User.cpp.o -MF CMakeFiles/ExpenseTracker.dir/src/User.cpp.o.d -o CMakeFiles/ExpenseTracker.dir/src/User.cpp.o -c /home/riskypete/Projects/expenses/expense_tracker/src/User.cpp

CMakeFiles/ExpenseTracker.dir/src/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExpenseTracker.dir/src/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riskypete/Projects/expenses/expense_tracker/src/User.cpp > CMakeFiles/ExpenseTracker.dir/src/User.cpp.i

CMakeFiles/ExpenseTracker.dir/src/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExpenseTracker.dir/src/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riskypete/Projects/expenses/expense_tracker/src/User.cpp -o CMakeFiles/ExpenseTracker.dir/src/User.cpp.s

CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o: CMakeFiles/ExpenseTracker.dir/flags.make
CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o: ../src/Transaction.cpp
CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o: CMakeFiles/ExpenseTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o -MF CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o.d -o CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o -c /home/riskypete/Projects/expenses/expense_tracker/src/Transaction.cpp

CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riskypete/Projects/expenses/expense_tracker/src/Transaction.cpp > CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.i

CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riskypete/Projects/expenses/expense_tracker/src/Transaction.cpp -o CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.s

CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o: CMakeFiles/ExpenseTracker.dir/flags.make
CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o: ../src/MenuFunctions.cpp
CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o: CMakeFiles/ExpenseTracker.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o -MF CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o.d -o CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o -c /home/riskypete/Projects/expenses/expense_tracker/src/MenuFunctions.cpp

CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riskypete/Projects/expenses/expense_tracker/src/MenuFunctions.cpp > CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.i

CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riskypete/Projects/expenses/expense_tracker/src/MenuFunctions.cpp -o CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.s

# Object files for target ExpenseTracker
ExpenseTracker_OBJECTS = \
"CMakeFiles/ExpenseTracker.dir/src/main.cpp.o" \
"CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o" \
"CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o" \
"CMakeFiles/ExpenseTracker.dir/src/User.cpp.o" \
"CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o" \
"CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o"

# External object files for target ExpenseTracker
ExpenseTracker_EXTERNAL_OBJECTS =

ExpenseTracker: CMakeFiles/ExpenseTracker.dir/src/main.cpp.o
ExpenseTracker: CMakeFiles/ExpenseTracker.dir/src/Account.cpp.o
ExpenseTracker: CMakeFiles/ExpenseTracker.dir/src/Group.cpp.o
ExpenseTracker: CMakeFiles/ExpenseTracker.dir/src/User.cpp.o
ExpenseTracker: CMakeFiles/ExpenseTracker.dir/src/Transaction.cpp.o
ExpenseTracker: CMakeFiles/ExpenseTracker.dir/src/MenuFunctions.cpp.o
ExpenseTracker: CMakeFiles/ExpenseTracker.dir/build.make
ExpenseTracker: CMakeFiles/ExpenseTracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ExpenseTracker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ExpenseTracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ExpenseTracker.dir/build: ExpenseTracker
.PHONY : CMakeFiles/ExpenseTracker.dir/build

CMakeFiles/ExpenseTracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExpenseTracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExpenseTracker.dir/clean

CMakeFiles/ExpenseTracker.dir/depend:
	cd /home/riskypete/Projects/expenses/expense_tracker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/riskypete/Projects/expenses/expense_tracker /home/riskypete/Projects/expenses/expense_tracker /home/riskypete/Projects/expenses/expense_tracker/build /home/riskypete/Projects/expenses/expense_tracker/build /home/riskypete/Projects/expenses/expense_tracker/build/CMakeFiles/ExpenseTracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ExpenseTracker.dir/depend

