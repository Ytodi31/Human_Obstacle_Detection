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

#ifndef APP_CLASSIFIER_HPP_
#define APP_CLASSIFIER_HPP_

#include <string>
#include <vector>
#include <../include/opencv2/core/core.hpp>
#include <../include/opencv2/opencv.hpp>
#include <../include/opencv2/highgui/highgui.hpp>
#include <../include/opencv2/ml.hpp>
#include <ImageReaderHelper.h>
#include <ImageProcessingHelper.h>
/**
 * @brief Classifier class tarins the classifier for prediction
 */

class Classifier {
 public:

  static cv::Ptr<cv::ml::SVM> classifier;

  static std::vector <float> hogDetector;

  /**
    * @brief Initializes the svm parameters
    * @param none
    * @return none
    */
  void setClassifier();

  /**
    * @brief Gets the HOG descriptors needed for detection
    * @param none
    * @return a vector of type float which holds the hog descriptors
    */
  std::vector <float> getHogDescriptors();

};

#endif /*  APP_CLASSIFIER_HPP_ */
