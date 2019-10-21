#include <gtest/gtest.h>
#include <../include/Training.h>
#include <../include/Classifier.h>
#include <../include/ImageReaderHelper.h>
#include <../include/ImageProcessingHelper.h>




// Unit test of class ImageReaderHelper

TEST(Training, LabelsTrainingTest) {
  // Check if the images were read
  Training trainTest;
  trainTest.getTrainClassifier();
  unsigned int i = 0;

  ASSERT_GT(trainTest.labels.size(), i);
}

TEST(Training, FeaturesTrainingTest) {
  // Check if the images were read
  Training trainTest;
  trainTest.getTrainClassifier();
  unsigned int i = 0;

  ASSERT_GT(trainTest.features.size(), i);
}

// TEST(Training, DescriptorsTrainingTest) {
//   // Check if the images were read
//   Training trainTest;
//   trainTest.getTrainClassifier();
//   unsigned int i = 0;
//
//   ASSERT_GT(trainTest.descriptors.size(), i);
// }
