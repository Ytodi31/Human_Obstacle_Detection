/**
 * BSD 3-Clause License
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file MockImageReaderHelper.h
 * @brief Mock interafce for mocking ImageReaderHelper class
 *
 * It contains the function definitions of mock class MockImageReaderHelper
 *
 * @author Yashaarth Todi
 *
 * @date 11-22-2019
 */
#ifndef INCLUDE_MOCKIMAGEREADERHELPER_HPP_
#define INCLUDE_MOCKIMAGEREADERHELPER_HPP_

#include "ImageReaderHelper.h"
#include <gmock/gmock.h>

/*
 * @brief Mock class derived from mock interface
 */
class MockImageReaderHelper: public ImageReaderHelper {
public:
  // Mock method for reading images 
  MOCK_METHOD(void,ReadImages,(cv::String), (override));
};
#endif // INCLUDE_MOCKIMAGEREADERHELPER_HPP_
