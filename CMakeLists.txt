#cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Enable C++11
#set(CMAKE_CXX_STANDARD 11)

project(human_detect)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

option(COVERAGE "Generate Coverage Data" ON)

if (COVERAGE)
    include(CodeCoverage)
	  set(LCOV_REMOVE_EXTRA "'vendor/*'")
    setup_target_for_coverage(code_coverage test/cpp-test coverage)
    set(COVERAGE_SRCS app/main.cpp
    include/ImageReaderHelper.h include/ImageProcessingHelper.h
    include/Training.h include/Classifier.h include/Testing.h include/HumanDetection.h include/MockImageReaderHelper.h)


    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

find_package(OpenCV REQUIRED)

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
add_subdirectory(app)
add_subdirectory(test)
#add_subdirectory(vendor/googletest)
add_subdirectory(vendor/googletest/googlemock)



# Declare the executable target built from your sources
#add_executable(opencv_example HelloWorldOpenCV.cpp)

# Link your application with OpenCV libraries
#target_link_libraries(opencv_example LINK_PRIVATE ${OpenCV_LIBS})
