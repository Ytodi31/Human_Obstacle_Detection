/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file ImageProcessingrHelper.h
 * @brief ImageProcessingHelper class header file
 *
 * It contains the function defintions and members to pre-process images
 *
 * @author Yashaarth Todi
 * @author Chinmay Joshi
 * @author Sandra Tinta
 *
 * @date 10-15-2019
 */

#ifndef APP_IMAGEPROCESSINGHELPER_HPP_
#define APP_IMAGEPROCESSINGHELPER_HPP_

#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>
#include <array>
#include <sstream>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <../include/opencv2/core/core.hpp>
#include <../include/opencv2/opencv.hpp>
#include <../include/opencv2/highgui/highgui.hpp>

/**
 * @brief ImageProcessingHelper class pre-processes images for training
 */
class ImageProcessingHelper {
 public:

  static std::vector<cv::Mat> roiTraining;

  /**
   * @brief localImage,variable storing the image in matrix
   */
  static cv::Mat localImage;
  static std::vector <int> roi;

  void  RegionInterest(cv::String);

  cv::Mat ReSizeImg(cv::Mat image);

};

#endif /* APP_IMAGEPROCESSINGHELPER_HPP_ */
