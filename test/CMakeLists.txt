set(GTEST_SHUFFLE 1)

add_executable(
  humanDetection-test
  main.cpp
  testImageProcessingHelper.cpp
	testImageReaderHelper.cpp
  ../app/ImageProcessingHelper.cpp
  ../app/ImageReaderHelper.cpp
  testTrainingClass.cpp
  ../app/Training.cpp
  ../app/Classifier.cpp
)

target_include_directories(humanDetection-test PUBLIC ../vendor/googletest/googletest/include
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(humanDetection-test PUBLIC gtest ${OpenCV_LIBS})
