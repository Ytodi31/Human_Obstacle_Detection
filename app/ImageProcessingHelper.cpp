/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file ImageProcessingrHelper.cpp
 * @brief ImageProcessingHelper class implementation file
 *
 * It contains the function declarations to pre-process images
 *
 * @author Yashaarth Todi
 * @author Chinmay Joshi
 * @author Sandra Tinta
 *
 * @date 10-15-2019
 */

#include "../include/ImageProcessingHelper.h"
#include <ImageReaderHelper.h>

ImageReaderHelper imgReadHelp;

// Instantitating member of class
cv::Mat ImageProcessingHelper::localImage;
std::vector<cv::Mat> ImageProcessingHelper::roiTraining;
std::vector <int> ImageProcessingHelper::roi;
/**
 * @brief ResizeImg,resizes the image using opencv function
 * @param Matrix, the image to be cropped
 * @return Matrix, cropped image
 */
  cv::Mat ImageProcessingHelper::ReSizeImg(cv::Mat image) {
  cv::resize(image, image, cv::Size(64, 128));
  return image;
}

/**
 * @brief Extracts region of interest by extracting annotations from textFile
 * creating a bounding box for cropping and resizing
 * @param String, containing the path of images
 * @return none
 */
void ImageProcessingHelper::RegionInterest(cv::String path) {
  imgReadHelp.ReadImages(path);
  std::vector< cv::Mat>trainingImages = imgReadHelp.classifierImages;
  std::string name = "Center point on object";
  // Setting unwanted characters to be deleted from text file
  std::array <char, 5> text = {"(),"};
  // Deleting unwanted text from textfile to access annotations for ROI
  std::vector <std::string> deleteline{"Bounding", "box", "for", "object", "1",
  "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15",
  "(Xmin,", "Ymin)", "-", "(Xmax," , "Ymax)", ",",
  ":", "\"PASperson\""};
  // variable to access address to modify values, accomodation for using
  // range-based loop
  int a = 0;
  for (auto b : trainingImages) {
  // Local variable containing cooridnates for region of interest
  cv::Rect box;
  std::stringstream out;
  // Variable to hold the desired lines from textfile
  std::string word;
  // Variable to hold the desired lines from Varible word after unwanted lines
  // are removed
  std::string word1;
  // Holds the coordinates from the text file
  std::vector <int> coordinates;
  localImage = trainingImages[a];
  // Opening textfile to access annotations
  std::ifstream file(imgReadHelp.textFile[a]);
  if (file.is_open()) {
    while (std::getline(file, word)) {
      // Checks for the word "Bounding Box" at every line and saves that line
      // in the word string if found
      if (word.find("Bounding box") != std::string::npos) {
        out << word << std::endl;
      }
    }
    while (out >> word1) {
      int j = 0;
      // Checks for characters that need to be deleted in the string word1
      for (auto i : deleteline) {
        if (word1 == deleteline[j])
          break;
        // Checks if all the characters in variable deleteline are checked,
        // saves coordinates
        if (j == 26) {
          std::string str = word1;
          for (auto a : text)
            str.erase(std::remove(str.begin(), str.end(), a), str.end());
          // Converting string to integer
          int num = std::stoi(str);
          coordinates.push_back(num);
        }
        j = j + 1;
      }
    }
    out.flush();
    // Finding the number of humans in each image since some frames have more
    // than one region of interst
    auto numObjects = coordinates.size()/4;
    // Creating a 2-D vector depending on number of region of interests, storing
    // coordinates of ROI
    std::vector <std::vector<int>> boxCoordinates(numObjects,
    std::vector<int>(4));
    int index = 0;
    cv::Mat croppedImage;
    // Reading the values of coordinares from the values extracted from textFile
    for (unsigned int i = 0; i < numObjects; i++) {
      for (int j = 0; j < 4; j++) {
        boxCoordinates.at(i).at(j) = coordinates.at(index);
        index +=1;
        roi.push_back(boxCoordinates.at(i).at(j));
      }
      boxCoordinates.at(i).at(2) = boxCoordinates.at(i).at(2)-
      boxCoordinates.at(i).at(0);
      boxCoordinates.at(i).at(3) = boxCoordinates.at(i).at(3)-
      boxCoordinates.at(i).at(1);
      // Defining a rectangular box with opencv  using extracted coordinates
      box = cv::Rect(boxCoordinates.at(i).at(0), boxCoordinates.at(i).at(1),
                      boxCoordinates.at(i).at(2), boxCoordinates.at(i).at(3));
      // Crooping the region of interest in the TRaining image
      croppedImage = localImage(box);
      // Normalising image for contrast normalisation of pixel to neutralize
      // lighting conditions
      cv::normalize(croppedImage, croppedImage, 0, 1, cv::NORM_MINMAX);
      // Creating a vector of images (resized with ROI extracted) for training
      roiTraining.push_back(ReSizeImg(croppedImage));
    }
    file.close();
  }
  a = a + 1;
}
}
