/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file Training.cpp
 * @brief Training class implementation file
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

  std::vector <cv::Mat> Training::features;

  std::vector <float> Training::descriptors;

  std::vector < int > Training::labels;

void Training::getTrainClassifier() {
  // Creating an object for the ImageProcessingHelper class
  ImageProcessingHelper imgProc;
  // Creating an object for the ImageReaHelper class
  ImageReaderHelper imgReader;
  // Setting the SVM parameters
  setClassifier();
  // Creating a HOGDescriptor variable to use in this method
  cv::HOGDescriptor hog;
  // Assigning the default window size
  hog.winSize = cv::Size(64, 128);
  // Assigning the default cell size
  hog.cellSize = cv::Size(8, 8);

  // creating a variable to hold the Gray scale Image
  cv::Mat gray;
  // Specifying the path for Training positive images
  cv::String posPath = "/home/ytodi31/INRIAPerson/Train/pos/*.png";
  // Giving the path to RegionInterest which is a part of
  // the ImageProcessingHelper class
  imgProc.RegionInterest(posPath);
  // Running a loop over all the positive images in the folder
  for (auto img : imgProc.roiTraining) {
    // converting to gray scale
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    // extracting the HOG features
    hog.compute(gray, descriptors);
    // Normalizing the HOG features
    cv::normalize(descriptors, descriptors);
    // storing it in features
    features.push_back(cv::Mat(descriptors).clone());
    // Adding a label of "1" to the positive images
    labels.push_back(1);
  }
  // Specifying the path for Training negative images
  cv::String negPath = "/home/ytodi31/INRIAPerson/Train/neg/*";
  imgReader.ReadImages(negPath);
  std::vector <cv::Mat> tempNegImages = imgReader.classifierImages;
  std::vector <cv::Mat> negImages;
  cv::Rect box;
  for (auto img : tempNegImages) {
    int imageHeight = img.rows;
    int imageWidth = img.cols;
    box = cv::Rect(static_cast<int>(imageWidth/4),
     static_cast<int>(imageHeight/4), static_cast<int>(imageHeight/2),
     static_cast<int>(imageHeight/2));
    cv::Mat croppedImage = img(box);
    croppedImage = imgProc.ReSizeImg(croppedImage);
    negImages.push_back(croppedImage);
  }

  for (auto img : negImages) {
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    hog.compute(gray, descriptors);
    cv::normalize(descriptors, descriptors);
    features.push_back(cv::Mat(descriptors).clone());
    labels.push_back(0);
  }

  // Creating row variable to make sure the format for ML algorithm is followed
  const int rows = static_cast<int>(features.size());
  // Creating col variable to make sure the format for ML algorithm is followed
  const int cols = static_cast<int>(std::max(features[0].cols,
    features[0].rows));
  // Creating a temporary matrix which will be used if the format isn't
  // satisfied and it has to be of type CV_32FC1
  cv::Mat temp(1, cols, CV_32FC1);
  // Creating the Train matrix which will have all the HOG features of positive
  // images
  cv::Mat trainMat(rows, cols, CV_32FC1);

  // Looping over features which holds the features
  unsigned int i = 0;
  for (auto j : features) {
    // Checking if column of features is 1
    if (features[i].cols == 1) {
      // Taking the transpose
      transpose(features[i], temp);
      // Adding it to Train matrix
      temp.copyTo(trainMat.row(static_cast<int>(i)));
    }
    // If it is in the right format the directly add to Train matrix
    else if (features[i].rows == 1) {
      features[i].copyTo(trainMat.row(static_cast<int>(i)));
    }
    // Used to acces the index of features vector
    i = i + 1;
  }


  std::cout << "Training SVM Classifier" << std::endl;
  // SVM function to train the classifier
  classifier->train(trainMat, cv::ml::ROW_SAMPLE, cv::Mat(labels));
  std::cout << "Training Finshed" << std::endl;

}
