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
#include <fstream>
#include <../include/opencv2/core/core.hpp>
#include <../include/opencv2/opencv.hpp>
#include <../include/opencv2/highgui/highgui.hpp>

/**
 * @brief ImageReaderHelper class reading of images from source directory
 */
class ImageReaderHelper {
 public:
  /**
   * @brief
   */
  std::vector <cv::Mat> classifierImages;

  /**
   * @brief
   */
  std::vector <cv::String> imageLabels;

  /**
   * @brief
   */
  std::vector <cv::String> textFile;

  /**
    * @brief ReadTrainingImgs, reads the training set of images
    * @param none
    * @return vector of Matrices, containing images
    */
  std::vector< cv::Mat>  ReadImages(cv::String);
};

#endif /* INCLUDE_IMAGEREADERHELPER_HPP_ */
