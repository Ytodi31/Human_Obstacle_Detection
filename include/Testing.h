/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file Testing.h
 * @brief Testing class header file
 *
 * It contains the function defintions and members for Testing human detection
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-20-2019
 */

#ifndef HUMAN_OBSTACLE_DETECTION_INCLUDE_TESTING_H_
#define HUMAN_OBSTACLE_DETECTION_INCLUDE_TESTING_H_

#include <string>
#include <vector>
#include <iostream>
#include <../include/opencv2/core/core.hpp>
#include <../include/opencv2/opencv.hpp>
#include <../include/opencv2/highgui/highgui.hpp>
#include <../include/opencv2/ml.hpp>
#include <Classifier.h>
#include <opencv2/objdetect.hpp>

class Testing: public Classifier {
 public:
  /**
    * @brief Initializes the testing of the classifier
    * @param none
    * @return none
    */
  void prediction();
};

#endif  // HUMAN_OBSTACLE_DETECTION_INCLUDE_TESTING_H_
