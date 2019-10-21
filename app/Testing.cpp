/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file Testing.cpp
 * @brief Testing class implementation file
 *
 * It contains the function and members implementation for Testing human detection
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-20-2019
 */
#include <Classifier.h>
#include <Testing.h>

using namespace cv;

void Testing::prediction() {
  // Creating a HOG descriptor variable
  cv::HOGDescriptor hogtest;
  // Assigning the default window size
  hogtest.winSize = cv::Size(64, 128);
  // Assigning the default cell size
  hogtest.cellSize = cv::Size(8, 8);
  // Setting the SVMDetector part of cv::HOGDescriptor class used for detection
  hogtest.setSVMDetector(getHogDescriptors());
  cv::Mat image = cv::imread("../INRIAPerson/Test/pos/crop001504.png");

  // Creating a vector which will hold the region where the Human is if a Human
  // is detected
  std::vector< cv::Rect > detections;

  // This function checks for Human
  hogtest.detectMultiScale(image, detections);

  // Here a bounding box is being created around the Detected human
  for (auto j : detections) {
    rectangle(image, j, Scalar(0, 255, 0), 2);
  }
  imshow( "testing trained detector on negative images", image);
  waitKey(0);
  destroyAllWindows();
}
