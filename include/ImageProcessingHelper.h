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
#include <../include/opencv2/core/core.hpp>
#include <../include/opencv2/opencv.hpp>
#include <../include/opencv2/highgui/highgui.hpp>

/**
 * @brief ImageProcessingHelper class pre-processes images for training
 */
class ImageProcessingHelper {
 public:

  /**
   * @brief frameSize,variable storing the image size in coordinates
   */
  cv::Rect frameSize;

  /**
   * @brief localImage,variable storing the image in matrix
   */
  cv::Mat localImage;

  /**
    * @brief ResizeImg, resizing image to a set size
    * @param Matrix, containing input image
    * @return Matrix, containing output resized image
    */
  cv::Mat ResizeImg();

  /**
    * @brief DenoiseImg, denoising image using camera calibration parameters
    * @param none
    * @return Matrix, containing output denoised image
    */
  cv::Mat DenoiseImg();

  /**
    * @brief ProcessImg,process image for training
    * @param none
    * @return Matrix, containing output processed image
    */
  cv::Mat ProcessImg();

};

#endif /* APP_IMAGEPROCESSINGHELPER_HPP_ */
