set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    testTestingClass.cpp
    testImageProcessingHelper.cpp
	  testImageReaderHelper.cpp
	testTrainingClass.cpp
    ../app/ImageProcessingHelper.cpp
    ../app/ImageReaderHelper.cpp
	../app/Classifier.cpp
	../app/Training.cpp
	../app/Testing.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include
                           ${CMAKE_SOURCE_DIR}/include  ${OpenCV_INCLUDE_DIRS})

target_link_libraries(cpp-test PUBLIC gtest  ${OpenCV_LIBS} )
