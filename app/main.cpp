#include <iostream>
#include <string>
#include <vector>
#include </usr/local/include/opencv2/core/core.hpp>
#include </usr/local/include/opencv2/opencv.hpp>
#include </usr/local/include/opencv2/highgui/highgui.hpp>

#include "../include/ImageProcessingHelper.h"
#include "../include/ImageReaderHelper.h"
int main()
{
    std::cout << "Hi! Lets detect humans" << std::endl;
    // ImageReaderHelper r1;
    // r1.ReadTrainingImgs();
    ImageProcessingHelper p1;
    p1.RegionInterest();

    return 0;
}
