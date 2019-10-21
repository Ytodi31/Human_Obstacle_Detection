/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file ImageProcessingrHelper.cpp
 * @brief ImageProcessingHelper class implementation file
 *
 * It contains the function declarations to pre-process images
 *
 * @author Yashaarth Todi
 * @author Chinmay Joshi
 * @author Sandra Tinta
 *
 * @date 10-15-2019
 */

#include <gtest/gtest.h>
#include <../include/Training.h>
#include <../include/Classifier.h>
#include <../include/ImageReaderHelper.h>
#include <../include/ImageProcessingHelper.h>
#include <../include/Testing.h>
#include <vector>

TEST(TestingClass, testTestingClass) {
  // Check if the images were read
  Training trainTest;
  trainTest.getTrainClassifier();
  Classifier svm;
  std::vector <float> hog;
  hog = svm.getHogDescriptors();
  float i = 0.0;
  ASSERT_GT(hog.size(), i);
}
