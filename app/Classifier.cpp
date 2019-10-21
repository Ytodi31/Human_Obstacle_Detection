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

/**
 * @brief classifier variable which will be used by Training and Testing class
 */
cv::Ptr<cv::ml::SVM> Classifier::classifier = cv::ml::SVM::create();

/**
 * @brief Sets the Parameters of the SVM classifier,
 * @param none
 * @return none
 */
void Classifier::setClassifier() {
  // Sets the SVM parameters
  classifier->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 1000, 1e-3));
  classifier->setKernel(cv::ml::SVM::POLY);
  classifier->setNu( 0.5 );
  classifier->setC( 0.01 );
  classifier->setType(cv::ml::SVM::ONE_CLASS);
  cout << "Class Train has been Initialized" << endl;
}

/**
 * @brief Gets the HOG descriptors which are used for Human Detection
 * @param none
 * @return a vector of type floar which has the descriptors
 */
std::vector <float> Classifier::getHogDescriptors() {
  // Gets the support vectors of the classifier which are need for detection
  cv::Mat svm = classifier->getSupportVectors();
  cv::Mat alpha, svidx;
  double rho = classifier->getDecisionFunction(0, alpha, svidx);

  // vector to store the hog descriptors
  std::vector <float> hogFeatures(svm.cols + 1);
  memcpy(&hogFeatures[0], svm.ptr(), svm.cols*sizeof(hogFeatures[0]));
  hogFeatures[svm.cols] = (float)-rho;
  return hogFeatures;
}
