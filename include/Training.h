/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file Training.h
 * @brief Training class implementation file
 *
 * It contains the function defintions for Training the classifier
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-20-2019
 */

#ifndef HUMAN_OBSTACLE_DETECTION_INCLUDE_TRAINING_H_
#define HUMAN_OBSTACLE_DETECTION_INCLUDE_TRAINING_H_

#include <string>
#include <vector>
#include <../include/opencv2/core/core.hpp>
#include <../include/opencv2/opencv.hpp>
#include <../include/opencv2/highgui/highgui.hpp>
#include <../include/opencv2/ml.hpp>
#include <Classifier.h>
#include <ImageReaderHelper.h>
#include <ImageProcessingHelper.h>

class Training: public Classifier {
 public:
  /**
    * @brief Initializes the training of the classifier
    * @param none
    * @return none
    */
  void getTrainClassifier();

  /**
    * @brief A vector variable of type cv::Mat which will be used for creating
	* the Training Data
	*/
  static std::vector <cv::Mat> features;

  /**
    * @brief Vector variable of type float which holds the HOG features extracted from
	* images
	*/
  static std::vector <float> descriptors;

  /**
    * @brief vector of type integer to hold the labels of the data
	*/
  static std::vector < int > labels;
};

#endif  // HUMAN_OBSTACLE_DETECTION_INCLUDE_TRAINING_H_
