/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file HumanDetection.cpp
 * @brief HumanDetection class implementation file
 *
 * It contains the function defintions and members to run the HumanDetection class
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-18-2019
 */

#include <HumanDetection.h>

/**
 * @brief function to call the ImageProcessingHelper class,
 * @param none
 * @return none
 */
void HumanDetect::callAllClass() {
  Training SVMClassifier;
  Testing tester;
  SVMClassifier.getTrainClassifier();
  tester.prediction();
}
