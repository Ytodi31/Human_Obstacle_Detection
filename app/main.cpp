#include <iostream>
#include <string>
#include <vector>
#include </usr/local/include/opencv2/core/core.hpp>
#include </usr/local/include/opencv2/opencv.hpp>
#include </usr/local/include/opencv2/highgui/highgui.hpp>

#include "../include/ImageReaderHelper.h"
int main()
{
    std::cout << "Hi! Lets detect humans" << std::endl;
    ImageReaderHelper test1;
    test1.ReadTrainingImgs();
    test1.ReadCameraImg();

    return 0;
}

