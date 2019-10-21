cmake_minimum_required(VERSION 3.2.1)
project (scratch)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

option(COVERAGE "Generate Coverage Data" ON)

if (COVERAGE)
    include(CodeCoverage)
	set(LCOV_REMOVE_EXTRA "'vendor/*'")
    setup_target_for_coverage(code_coverage test/cpp-test coverage)
    set(COVERAGE_SRCS app/main.cpp app/ImageProcessingHelper.cpp
    app/ImageReaderHelper.cpp app/Classifier.cpp app/Training.cpp
    app/Testing.cpp app/HumanDetection.cpp
    include/ImageReaderHelper.h include/ImageProcessingHelper.h
    include/Training.h include/Classifier.h include/Testing.h include/HumanDetection.h)


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

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(vendor/googletest/googletest)
