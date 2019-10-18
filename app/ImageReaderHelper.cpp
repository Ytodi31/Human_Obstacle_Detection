/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file ImageReaderHelper.cpp
 * @brief ImageReaderHelper class implementation file
 *
 * It contains the function declarations to read and store images
 *
 * @author Yashaarth Todi
 * @author Chinmay Joshi
 * @author Sandra Tinta
 *
 * @date 10-15-2019
 */

#include "../include/ImageReaderHelper.h"

std::string ImageReaderHelper::cameraImgPath = "/home/ytodi31/INRIAPerson/"
    "crop001012.png";
cv::String ImageReaderHelper::trainingImgsDir = "/home/ytodi31/INRIAPerson/"
    "train_64x128_H96/pos/*.png";
/**
 * @brief ReadCameraImg,
 * @param
 * @return
 */
cv::Mat ImageReaderHelper::ReadCameraImg() {
  cv::Mat image;
  image = cv::imread(cameraImgPath);
  cv::imshow("Test image for pipeline", image);
  cv::waitKey(0);
  return image;
}

/**
 * @brief ReadTrainingImgs,
 * @param
 * @return
 */
std::vector< cv::Mat>  ImageReaderHelper::ReadTrainingImgs() {
  std::vector <cv::Mat> trainingImages;
  std::vector <cv::String> imageNames;
  cv::glob(trainingImgsDir, imageNames);
  for (size_t i = 0; i< imageNames.size(); i++ ) {
      cv::Mat image = cv::imread(imageNames[i]);
      trainingImages.push_back(image);
    }
  std::cout << trainingImages.size() << std::endl;
  return trainingImages;
}

