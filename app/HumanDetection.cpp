/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file HumanDetection.cpp
 * @brief HumanDetection class implementation file
 *
 * It contains the function defintions and members to run the HumanDetection class
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-18-2019
 */

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <ImageProcessingHelper.h>
#include <ImageReaderHelper.h>
#include <HumanDetection.h>

/**
 * @brief function to call the ImageProcessingHelper class,
 * @param none
 * @return none
 */
  void HumanDetect::ImageProcessingHelperClass() {
  ImageProcessingHelper imgProcHelp;
  ImageReaderHelper imgReadHelp;
  cv::Mat image = imgReadHelp.ReadCameraImg();
  image = imgProcHelp.ResizeImg(image);
  image = imgProcHelp.ProcessImg(image);
  cv::imshow("image", image);
  cv::waitKey(0);
  cv::destroyAllWindows();
 }
