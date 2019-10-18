add_executable(shell-app HelloWorldOpenCV.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
# Link your application with OpenCV libraries
target_link_libraries(shell-app LINK_PRIVATE ${OpenCV_LIBS})

