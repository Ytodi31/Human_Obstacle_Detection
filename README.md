# C++ Boilerplate
[![Build Status](https://travis-ci.org/Ytodi31/Human_Obstacle_Detection.svg?branch=iteration2)](https://travis-ci.org/Ytodi31/Human_Obstacle_Detection)
[![Coverage Status](https://coveralls.io/repos/github/Ytodi31/Human_Obstacle_Detection/badge.svg?branch=iteration2)](https://coveralls.io/github/Ytodi31/Human_Obstacle_Detection?branch=iteration2)
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

## Installing Dependencies

You can install any version of OpenCV using these dependencies. For this project we are using OpenCV version 3.3.0

```
sudo apt-get install build-essential checkinstall cmake pkg-config yasm gfortran git
sudo apt-get install libjpeg8-dev libjasper-dev libpng12-dev

# For Ubuntu 16.04
sudo apt-get install libtiff5-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev
sudo apt-get install libxine2-dev libv4l-dev
sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
sudo apt-get install libqt4-dev libgtk2.0-dev libtbb-dev
sudo apt-get install libatlas-base-dev
sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev
sudo apt-get install libvorbis-dev libxvidcore-dev
sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev
sudo apt-get install x264 v4l-utils
```

## Downloading and Installing OpenCV

```
git clone https://github.com/opencv/opencv.git
cd opencv

# Depending on the version you want of OpeCV do git checkout version

git checkout 3.3.0
cd ..
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 3.3.0
cd ..

cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D INSTALL_C_EXAMPLES=ON \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D WITH_QT=ON \
      -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      -D BUILD_EXAMPLES=ON ..

# find out number of CPU cores in your machine
nproc

# substitute 4 by output of nproc
make -j4
sudo make install
sudo sh -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
```
## Building for code coverage
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
