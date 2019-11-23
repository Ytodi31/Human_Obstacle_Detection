add_executable(human_detect main.cpp
HumanDetection.cpp  ImageProcessingHelper.cpp ImageReaderHelper.cpp Testing.cpp
Training.cpp Classifier.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})

target_link_libraries (human_detect ${OpenCV_LIBS})
