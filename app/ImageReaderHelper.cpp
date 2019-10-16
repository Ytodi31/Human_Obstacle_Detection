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

#include <ImageReaderHelper.hpp>

/**
 * @brief ReadCameraImg,
 * @param
 * @return
 */
cv::Mat ImageReaderHelper::ReadCameraImg() {
  cv::Mat image;
  image = cv::imread(ImageReaderHeper::cameraImgPath, CV_LOAD_IMAGE_COLOR);
  cv::imshow("test", image);
  cv::waitKey(0);
}

/**
 * @brief ReadTrainingImgs,
 * @param
 * @return
 */
std::vector<cv::Mat>  ImageReaderHelper::ReadTrainingImgs() {

}
