/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file Classifier.cpp
 * @brief Classifier class implementation file
 *
 * It contains the function and member implementation for classifying and detecting human
 *
 * @author Chinmay Joshi
 * @author Yashaarth Todi
 * @author Sandra Tinta
 *
 * @date 10-20-2019
 */

#include <Classifier.h>
#include <Training.h>

using std::cout;
using std::endl;

void Training::getTrainClassifier() {
  ImageProcessingHelper imgProc;
  ImageReaderHelper imgReader;
  getHogFeatures();
  setClassifier();
  std::vector <cv::Mat> gradientList;
  std::vector <float> descriptors;
  std::vector <cv::Point> locations;
    std::vector < int > labels;
  cv::Mat gray;
  cv::String posPath = "/home/ytodi31/INRIAPerson/Train/pos/*.png";
  imgProc.RegionInterest(posPath);
  for (auto img: imgProc.roiTraining) {
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    hog.compute(gray, descriptors, cv::Size(0, 0), cv::Size(0, 0), locations);
    gradientList.push_back(cv::Mat(descriptors).clone());
    labels.push_back(1);
  }

  cv::String negPath = "/home/ytodi31/INRIAPerson/Test/neg/*";
  imgReader.ReadImages(negPath);
  std::vector <cv::Mat> tempNegImages = imgReader.classifierImages;
  std::vector <cv::Mat> negImages;
  cv::Rect box;
  for (auto img:tempNegImages) {
    int imageHeight = img.rows;
    int imageWidth = img.cols;
    box = cv::Rect(int(imageWidth/4), int(imageHeight/4), int(imageHeight/2), int(imageHeight/2));
    cv::Mat croppedImage = img(box);
    croppedImage = imgProc.ReSizeImg(croppedImage);
    negImages.push_back(croppedImage);
  }
  std::cout << negImages.size() << std::endl;
  for (auto img: negImages) {
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    hog.compute(gray, descriptors, cv::Size(0, 0), cv::Size(0, 0), locations);
    gradientList.push_back(cv::Mat(descriptors).clone());
    labels.push_back(0);
  }
  std::cout << labels.size() << std::endl;

//CHANGE GRADIENTLIST VAR

  const int rows = (int)(gradientList.size());
  const int cols = (int)(std::max(gradientList[0].cols, gradientList[0].rows));
  cv::Mat temp(1, cols, CV_32FC1), trainData(rows, cols, CV_32FC1);
  for (unsigned int index = 0; index < gradientList.size(); index++) {
      if (gradientList[index].cols == 1) {
          transpose(gradientList[index], temp);
          temp.copyTo(trainData.row(int(index)));
      } else if (gradientList[index].rows == 1) {
          gradientList[index].copyTo(trainData.row(int(index)));
      }
  }
  // Training Starts
  std::cout << "Training SVM Classifier" << std::endl;
  classifier->train(trainData, cv::ml::ROW_SAMPLE, cv::Mat(labels));
  std::cout << "Training Finshed" << std::endl;
}
