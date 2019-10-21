/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file testImageProcessingHelper.cpp
 * @brief Test file for ImageProcessingHelper.cpp
 *
 * It contains the tests for methods of ImageProcessingHelper class
 *
 * @author Yashaarth Todi
 * @author Chinmay Joshi
 * @author Sandra Tinta
 *
 * @date 10-20-2019
 */
#include <gtest/gtest.h>
#include <../include/Training.h>
#include <../include/Classifier.h>
#include <../include/ImageReaderHelper.h>
#include <../include/ImageProcessingHelper.h>


TEST(Training, LabelsTrainingTest) {
  // Check if the images were read
  Training trainTest;
  trainTest.getTrainClassifier();
  unsigned int i = 0;

  ASSERT_GT(trainTest.labels.size(), i);
}

TEST(Training, FeaturesTrainingTest) {
  // Check if the images were read
  Training trainTest;
  trainTest.getTrainClassifier();
  unsigned int i = 0;

  ASSERT_GT(trainTest.features.size(), i);
}
