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

#ifndef HUMAN_OBSTACLE_DETECTION_INCLUDE_IMAGEPROCESSINGHELPER_H_
#define HUMAN_OBSTACLE_DETECTION_INCLUDE_IMAGEPROCESSINGHELPER_H_

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

#include"ImageReaderHelper.h"

/**
 * @brief ImageProcessingHelper class pre-processes images for training
 */
class ImageProcessingHelper {
 public:
   /**
    * @brief vector, holding all the images for training after processing
    */
  static std::vector<cv::Mat> roiTraining;

  /**
   * @brief localImage,variable storing the image in matrix
   */
  static cv::Mat localImage;

  /**
   * @brief vector, holding temporary corrdinates of ROI
   */
  static std::vector <int> roi;

  /**
   * @brief Function, to extract the region on intrest for training
   * @param Address of class ImageReaderHelper
   * return none
   */
  void  RegionInterest(ImageReaderHelper &);

  /**
   * @brief Function, to resize the image
   * @param Image to be resized
   * return resized image
   */
  cv::Mat ReSizeImg(cv::Mat image);
};

#endif  // HUMAN_OBSTACLE_DETECTION_INCLUDE_IMAGEPROCESSINGHELPER_H_
