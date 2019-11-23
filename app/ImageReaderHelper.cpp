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

#include <../include/ImageReaderHelper.h>
    std::vector <cv::Mat> classifierImages;
    std::vector <cv::String> imageLabels;
    std::vector <cv::String> textFile;
    cv::String ImgsDir;

 ImageReaderHelper::ImageReaderHelper() {}
 ImageReaderHelper::~ImageReaderHelper() {}

 /**
  * @brief ReadTrainingImgs,reads images from a directory using opencv function
  * @param String variable, containing path of directory
  * @return none
  */
void ImageReaderHelper::ReadImages() {
  // Generate a list of all files that match the globbing pattern
  classifierImages.clear();
  cv::glob(ImageReaderHelper::ImgsDir, imageLabels);
  for (size_t i = 0; i < imageLabels.size(); i++) {
      cv::Mat image = cv::imread(imageLabels[i]);
      classifierImages.push_back(image);
      // Creating string of textfile name using image name from imageLabels var
      cv::String newfilename = imageLabels[i].substr(0,
        imageLabels[i].find_last_of('.'))+ ".txt";
      textFile.push_back(newfilename);
    }
}
