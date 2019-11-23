/**
 * @copyright Copyright (c) Fall 2019 ENPM808X
 *            This project is released under the BSD 3-Clause License
 *
 * @file MockImageReaderHelper.h
 * @brief Mock interafce for mocking ImageReaderHelper class
 *
 * It contains the declaration of mocking class MockImageReaderHelper
 *
 * @author Yashaarth Todi
 *
 * @date 11-22-2019
 */
 #include <gtest/gtest.h>
 #include <gmock/gmock.h>
 #include <../include/opencv2/opencv.hpp>

 #include "MockImageReaderHelper.h"
 #include "ImageProcessingHelper.h"
 #include "ImageReaderHelper.h"

 TEST(MockReaderTest, ReaderImagesMockTest) {
   MockImageReaderHelper reader;
   //ImageReaderHelper imgRead;
   ImageProcessingHelper processor;
   reader.ImgsDir = "../INRIAPerson/Train/pos/crop001001.png";
   EXPECT_CALL(reader,ReadImages()).Times(1);
   processor.RegionInterest(reader);
 }
