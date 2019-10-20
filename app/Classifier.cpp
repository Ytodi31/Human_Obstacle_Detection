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

using std::cout;
using std::endl;

void Classifier::setClassifier() {
  classifier = cv::ml::SVM::create();
  classifier->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 1000, 0.001));
  classifier->setKernel(cv::ml::SVM::LINEAR);
  classifier->setC(10);
  classifier->setType(cv::ml::SVM::C_SVC);
  cout << "Class Train has been Initialized" << endl;

}

void Classifier::getHogFeatures() {
  hog.winSize = cv::Size(64, 128);
  hog.cellSize = cv::Size(8, 8);
}
