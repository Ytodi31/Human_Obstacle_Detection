/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file Classifier.h
 * @brief Classifier class header file
 *
 * It contains the function defintions and members for classifying and detecting human
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-20-2019
 */

#ifndef APP_TRAINING_HPP_
#define APP_TRAINING_HPP_

#include <string>
#include <vector>
#include <../include/opencv2/core/core.hpp>
#include <../include/opencv2/opencv.hpp>
#include <../include/opencv2/highgui/highgui.hpp>
#include <../include/opencv2/ml.hpp>
#include <Classifier.h>

class Training: public Classifier {
public:

  /**
    * @brief Initializes the svm parameters
    * @param none
    * @return none
    */
  void getTrainClassifier();

};

#endif /* APP_TRAINING_HPP_ */
