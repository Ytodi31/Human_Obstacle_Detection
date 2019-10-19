add_executable(shell-app main.cpp ImageReaderHelper.cpp ImageProcessingHelper.cpp)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(shell-app LINK_PRIVATE ${OpenCV_LIBS})
