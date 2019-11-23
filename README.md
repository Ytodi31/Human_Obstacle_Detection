# Human Obstacle Detection
[![Build Status](https://travis-ci.org/Ytodi31/Human_Obstacle_Detection.svg?branch=master)](https://travis-ci.org/Ytodi31/Human_Obstacle_Detection)
[![Coverage Status](https://coveralls.io/repos/github/Ytodi31/Human_Obstacle_Detection/badge.svg?branch=master)](https://coveralls.io/github/Ytodi31/Human_Obstacle_Detection?branch=master)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---

## Overview/Purpose
Robots can travel through populated environments like curbs and streets for last mile delivery. One of the most frequently encountered obstacles would be humans while travelling. For this purpose, this perception software component can be used to detect human obstacles in an outdoor environment images from a camera mounted on the robot.

The perception module comprises of following sub-modules: <br/>
•	Human Detection Module: Main module that drives the dectection algorithm Classifiers <br/>
•	Image-processing module:  In this module we load all the images of for training the classifier and get it in the appropriate size we also perform grey-scale conversion. <br/>
•	Feature extraction module: Extraction of features using HOG features algorithm implemented using OpenCV Library <br/>
•	Training module: Training the data using Support Vector Machines to build a classifier <br/>
•	Testing module: The trained classifier will be validated using n-fold cross validation


## AIP Development Team
* Yashaarth Todi is a Robotics graduate student
* Chinmay Joshi is a Robotics Graduate student with a passion for Robotics, Computer Vision, Machine Learning, Embedded Systems. Loves DIY projects.
* Sandra Tinta is new to the Robotics field.  She currenlty holds an M.S. in Computer Science and most of her professional career has been centered  on development, design, testing, performance assesment of non-commercial wireless communications protocols.

## AIP worksheet

The detailed work flow is given in the following [link](https://docs.google.com/spreadsheets/d/13WXzRSTHV0jlsC4YitLOjkog6HfLg3e6ruhls8xQrKQ/edit?ts=5d9dbd68#gid=1748360951)

## AIP Planning and Review notes

The detailed notes of each sprint can be found in this [link](https://docs.google.com/document/d/1rkuHtKKTvhV5eiwX7T5SonaRDGOlHK2LOWWfs0eCQ4s/edit?ts=5da23ca7)

## Results
- cppcheck, cplint output text file can be found resource folder

## License


```
BSD 3-Clause License
Copyright (c) 2019, Yashaarth Todi
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```


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

## Known Issues/Bugs

- While installing OpenCV libraries there can be a conflict of certain libraries being already installed because of the same
- The module heaviliy relies on OpenCV libraries.
- The module currently doesn't use calibration data


## Running the code
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

##Doxygen Documentation
Installing doxygen:
```
sudo apt-get install doxygen
```
Run doxygen inside doc/:
Installing doxygen:
```
doxygen Human_Obstacle_Detection.doxyfile
```

## GMock
The class being mocked is ImageReaderHelper class. The implementation has been slightly modified from the main branch,to make the class a viable candidate for GMock Testing. Class ImageProcessingHelper ia tested, which consumes the ImageReaderClass. The test checks if the mocked class functions are called by the dependent class.  
To run GMock test :\
`Run tests: ./test/cpp-test`\
