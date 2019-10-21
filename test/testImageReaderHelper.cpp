/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file testImageReaderHelper.cpp
 * @brief Test file for ImageReaderHelper.cpp
 *
 * It contains the tests for methods of ImageReaderHelper class
 *
 * @author Yashaarth Todi
 * @author Chinmay Joshi
 * @author Sandra Tinta
 *
 * @date 10-20-2019
 */
#include <gtest/gtest.h>
#include <../include/ImageReaderHelper.h>

TEST(ReadImages, ReadImagesTest) {
  // Check if the images were read
  ImageReaderHelper test;
  test.ReadImages("/home/ytodi31/INRIAPerson/Train/pos/*.png");
  unsigned int i = 0;

  ASSERT_GT(test.classifierImages.size(), i);
}

TEST(LoadImages, LoadImagesTest) {
  // Check if all the images have been loaded
  ImageReaderHelper test;
  unsigned int i = 1218;
  test.ReadImages("/home/ytodi31/INRIAPerson/Train/neg/*");
  ASSERT_EQ(test.classifierImages.size(), i);
}
