set(GTEST_SHUFFLE 1)

add_executable(
    humanDetection-test
    main.cpp
    testImageProcessingHelper.cpp
	  testImageReaderHelper.cpp
    ../app/ImageProcessingHelper.cpp
    ../app/ImageReaderHelper.cpp
)

target_include_directories(humanDetection-test PUBLIC ../vendor/googletest/googletest/include
                           ${CMAKE_SOURCE_DIR}/include  ${OpenCV_INCLUDE_DIRS})

target_link_libraries(humanDetection-test PUBLIC gtest  ${OpenCV_LIBS} )
