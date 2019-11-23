/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file HumanDetection.h
 * @brief HumanDetection class header file
 *
 * It contains the function defintions for Human Detection
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-18-2019
 */
#ifndef HUMAN_OBSTACLE_DETECTION_INCLUDE_HUMANDETECTION_H_
#define HUMAN_OBSTACLE_DETECTION_INCLUDE_HUMANDETECTION_H_

#include <Classifier.h>
#include <Training.h>
#include <Testing.h>
#include <ImageReaderHelper.h>
#include <ImageProcessingHelper.h>

 /**
  * @brief HumanDetect class calls ImageProcessingHelper and ImageReaderHelper
           class for Human Detection
  */
  class HumanDetect {
   public:
    /**
      * @brief calls the ImageReaderHelper class
      * @param none
      * @return none
      */
    void callAllClass();
  };
#endif  // HUMAN_OBSTACLE_DETECTION_INCLUDE_HUMANDETECTION_H_
