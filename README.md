# C++ Boilerplate
[![Build Status](https://travis-ci.org/Ytodi31/Human_Obstacle_Detection.svg?branch=master)](https://travis-ci.org/Ytodi31/Human_Obstacle_Detection)
[![Coverage Status](https://coveralls.io/repos/github/Ytodi31/Human_Obstacle_Detection/badge.svg?branch=master)](https://coveralls.io/github/Ytodi31/Human_Obstacle_Detection?branch=master)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---

## Overview
Robots can travel through populated environments like curbs and streets for last mile delivery. One of the most frequently encountered obstacles would be humans while travelling. For this purpose, this perception software component can be used to detect human obstacles in an outdoor environment images from a camera mounted on the robot.

## Standard install via command-line
```
git clone --recursive https://github.com/Ytodi31/Human_Obstacle_Detection
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## AIP worksheet

The detailed work flow is given in the following [link](https://docs.google.com/spreadsheets/d/13WXzRSTHV0jlsC4YitLOjkog6HfLg3e6ruhls8xQrKQ/edit?ts=5d9dbd68#gid=1748360951) 

## Planning and review notes

The detailed notes of each sprint can be found in this [link](https://docs.google.com/document/d/1rkuHtKKTvhV5eiwX7T5SonaRDGOlHK2LOWWfs0eCQ4s/edit?ts=5da23ca7)

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```


# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As ->
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++
perspetive view (or Windows->Perspective->Open Perspective->C/C++).

