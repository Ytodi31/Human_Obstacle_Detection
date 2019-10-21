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
#include <ImageProcessingHelper.h>
#include <ImageReaderHelper.h>

TEST(ImageProcResize, testImageFrameSize) {
  ImageProcessingHelper imgProc;
  cv::Mat image = cv::imread("/home/ytodi31/INRIAPerson/Train/pos/crop001717.png");
  cv::Mat resizedImg = imgProc.ReSizeImg(image);
  ASSERT_EQ(resizedImg.rows, 128);
  ASSERT_EQ(resizedImg.cols, 64);
}

TEST(ImageProcROI, testROICoord) {
  ImageProcessingHelper imgProc;
  cv::String path = "/home/ytodi31/INRIAPerson/Train/pos/crop001241.png";
  imgProc.RegionInterest(path);
  ASSERT_EQ(imgProc.roi[0], 216);
  ASSERT_EQ(imgProc.roi[1], 157);
  ASSERT_EQ(imgProc.roi[2]-imgProc.roi[0], 127);
  ASSERT_EQ(imgProc.roi[3]-imgProc.roi[1], 322);
}
