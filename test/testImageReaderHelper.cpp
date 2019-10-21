#include <gtest/gtest.h>
#include <../include/ImageReaderHelper.h>



// Unit test of class ImageReaderHelper

TEST(ReadImages, ReadImagesTest) {
  // Check if the images were read
  ImageReaderHelper test;
  test.ReadImages("/home/ytodi31/INRIAPerson/Train/pos/*.png");
  unsigned int i = 0;

  ASSERT_GT(test.classifierImages.size(), i);
}

TEST(LoadImages, LoadImagesTest) {
  // Check if all the images have been loaded
  ImageReaderHelper test;
  unsigned int i = 1218;
  test.ReadImages("/home/ytodi31/INRIAPerson/Train/neg/*");
  ASSERT_EQ(test.classifierImages.size(), i);
}
