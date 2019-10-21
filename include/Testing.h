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

#ifndef APP_TESTING_HPP_
#define APP_TESTING_HPP_

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

#endif /* APP_TESTING_HPP_ */
