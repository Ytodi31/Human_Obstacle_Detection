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
#ifndef HUMAN_OBSTACLE_DETECTION_INCLUDE_IMAGEREADERHELPER_H_
#define HUMAN_OBSTACLE_DETECTION_INCLUDE_IMAGEREADERHELPER_H_

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
  ImageReaderHelper();
  virtual ~ImageReaderHelper();
  /**
   * @brief vector of images, holding region of interest of training images
   */
  std::vector <cv::Mat> classifierImages;

  /**
   * @brief String, containing the images directory loction
   */
  cv::String ImgsDir;

  /**
   * @brief vector of strings, holding labels of trainig images
   */
  std::vector <cv::String> imageLabels;

  /**
   * @brief vector of strings, holding name of text file containing annotations
   * for images
   */
  std::vector <cv::String> textFile;

  /**
    * @brief ReadImages, reads the training set of images
    * @param none
    * @return none
    */
  virtual void ReadImages();
};

#endif  // HUMAN_OBSTACLE_DETECTION_INCLUDE_IMAGEREADERHELPER_H_
