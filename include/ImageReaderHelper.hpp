/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file ImageReaderHelper.h
 * @brief ImageReaderHelper class header file
 *
 * It contains the function definitions and members to read and store images
 *
 * @author Yashaarth Todi
 * @author Chinmay Joshi
 * @author Sandra Tinta
 *
 * @date 10-15-2019
 */

#ifndef INCLUDE_IMAGEREADERHELPER_HPP_
#define INCLUDE_IMAGEREADERHELPER_HPP_

#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

/**
 * @brief ImageReaderHelper class reading of images from source directory
 */
class ImageReaderHelper {
 public:
  ImageReaderHelper();
  ~ImageReaderHelper();

  /**
   * @brief cameraImgPath, variable stores the directory of source of an image
   */
  std::string cameraImgPath;

  /**
   * @brief trainingImgsDir,variable stores the directory of source of training
   *   image
   */
  std::string trainingImgsDir;

  /**
    * @brief ReadCameraImg, reads an image
    * @param none
    * @return Matrix data type, containing an image
    */
  cv::Mat ReadCameraImg();

  /**
    * @brief ReadTrainingImgs, reads the training set of images
    * @param none
    * @return vector of Matrices, containing images
    */
  std::vector<cv::Mat> ReadTrainingImgs();

};

#endif /* INCLUDE_IMAGEREADERHELPER_HPP_ */
