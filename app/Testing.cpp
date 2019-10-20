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

#include <Testing.h>

void Testing::prediction() {
  ImageProcessingHelper imgProc;
  ImageReaderHelper imgReader;
  std::vector <cv::Mat> gradientList;
  std::vector <float> descriptors;
  std::vector <cv::Point> locations;
  cv::Mat gray;
  std::vector <cv::Mat> testImages;
  cv::String path = "/home/ytodi31/INRIAPerson/Test/pos/*.png";
  imgProc.RegionInterest(path);
  for (auto img: imgProc.roiTraining) {
    cv::Mat croppedImage = imgProc.ReSizeImg(img);
    testImages.push_back(croppedImage);
  }
  for (auto img: testImages) {
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    hog.compute(gray, descriptors, cv::Size(0, 0), cv::Size(0, 0), locations);
    gradientList.push_back(cv::Mat(descriptors).clone());
  }

  const int rows = (int)(gradientList.size());
  const int cols = (int)(std::max(gradientList[0].cols, gradientList[0].rows));
  cv::Mat temp(1, cols, CV_32FC1), testData(rows, cols, CV_32FC1);
  for (unsigned int index = 0; index < gradientList.size(); index++) {
      if (gradientList[index].cols == 1) {
          transpose(gradientList[index], temp);
          temp.copyTo(testData.row(int(index)));
      } else if (gradientList[index].rows == 1) {
          gradientList[index].copyTo(testData.row(int(index)));
      }
  }
std::cout << gradientList.size() << std::endl;
std::cout << testData.size() << std::endl;
classifier->predict(testData, response);
std::cout << response.size() << std::endl;
}
