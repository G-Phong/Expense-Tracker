### THIS CMAKELISTS FILE WAS CREATED BY GIA-PHONG TRAN ###

cmake_minimum_required(VERSION 3.1)
project(ExpenseTracker VERSION 0.1.0 LANGUAGES CXX)

#Uncomment following line if MenuFunctions is implemented
#add_executable(ExpenseTracker src/main.cpp src/Account.cpp src/Group.cpp src/MenuFunctions.cpp src/User.cpp)

#For gprof usage
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

#Debug purpose: Use this line if MenuFunctions is not ready yet!
add_executable(ExpenseTracker src/main.cpp src/Account.cpp src/Group.cpp src/User.cpp src/Transaction.cpp src/MenuFunctions.cpp)
