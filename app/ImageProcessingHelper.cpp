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

cv::Mat ImageProcessingHelper::localImage;
std::vector<cv::Mat> ImageProcessingHelper::roiTraining;

cv::Mat ImageProcessingHelper::ReSizeImg(cv::Mat image) {
  cv::resize(image, image, cv::Size(64,128));
  return image;
}

/**
 * @brief ResizeImg,
 * @param
 * @return
 */
void ImageProcessingHelper::RegionInterest(cv::String path) {
  std::vector< cv::Mat>trainingImages = imgReadHelp.ReadImages(path);
  std::string name = "Center point on object";
  std::array <char, 5> text = {"(),"};
  std::vector <std::string> deleteline{"Bounding", "box", "for", "object", "1",
   "2", "3", "4", "5", "6", "7","8", "9", "10","11", "12", "13", "14", "15",
    "(Xmin,", "Ymin)", "-", "(Xmax,", "Ymax)", ",",
   ":", "\"PASperson\""};
   int a = 0;
  // for (size_t i =0; i< training.size(); i++)
    for (auto b: trainingImages) {
    cv::Rect box;
    std::stringstream out;
    std::string word;
    std::string word1;
    std::vector <int> line;
    localImage = trainingImages[a];
    std::ifstream file(imgReadHelp.textFile[a]);
    if (file.is_open()) {
      while (std::getline(file, word)) {
        if (word.find("Bounding box") != std::string::npos) {
            out << word << std::endl;
        }
      }
      while (out >> word1) {
        int j = 0;
        for (auto i: deleteline) {
          if (word1 == deleteline[j])
            break;
          if (j == 26) {
            std::string str = word1;
            for(auto a: text)
              str.erase(std::remove(str.begin(), str.end(), a), str.end());
            int num = std::stoi(str);
            line.push_back(num);
          }
          j = j + 1;
        }
      }
      out.flush();
      auto numObjects = line.size()/4;
    	std::vector <std::vector<int>> boxCoordinates(numObjects,
      std::vector<int>(4));
    	int index = 0;
      cv::Mat croppedImage;
    	for (unsigned int i = 0; i < numObjects; i++) {
    		for (int j = 0; j < 4; j++) {
    			boxCoordinates.at(i).at(j) = line.at(index);
    			index +=1;
    		}
    	 boxCoordinates.at(i).at(2) = boxCoordinates.at(i).at(2)-
       boxCoordinates.at(i).at(0);
       boxCoordinates.at(i).at(3) = boxCoordinates.at(i).at(3)-boxCoordinates.at(i).at(1);
       box = cv::Rect(boxCoordinates.at(i).at(0), boxCoordinates.at(i).at(1),
                      boxCoordinates.at(i).at(2),boxCoordinates.at(i).at(3));
       croppedImage = localImage(box);
       roiTraining.push_back(ReSizeImg(croppedImage));
    	}
      file.close();
    }
    a = a + 1;
  }
}


/**
 * @brief DenoiseImg,
 * @param
 * @return
 */
cv::Mat ImageProcessingHelper::DenoiseImg() {
  cv:: Mat image = cv::Mat::zeros(480, 640, CV_8UC1);
  return image;
}

/**
 * @brief ProcessImg,
 * @param
 * @return
 */
cv::Mat ImageProcessingHelper::ProcessImg() {
  cv:: Mat image = cv::Mat::zeros(480, 640, CV_8UC1);
  return image;
}
