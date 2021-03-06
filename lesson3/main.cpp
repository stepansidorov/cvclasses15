///@File: main.cpp
///@Brief: Contains interface of console application for testing background
///        subtraction algorithms
///@Author: Vitaliy Baldeev
///@Date: 01 October 2015

#include <iostream>
#include <memory>
#include <list>

#include "SegmentMotionDiff.h"
#include "SegmentMotionBU.h"
#include "SegmentMotionGMM.h"
#include "SegmentMotion1G.h"

int main()
{
    std::cout << "Select the algorithm: \n"
        << "Diff  - Basic difference \n"
        << "BU    - Basic difference with background updating \n"
        << "GMM   - Gaussian mixture model algorithm \n"
        << "MM    - MinMax algoruthm \n"
        << "1G    - One Gaussian \n";

    std::string algorithmName;
    std::cin >> algorithmName;

    std::unique_ptr<SegmentMotionBase> ptr(SegmentMotionBase::CreateAlgorithm(algorithmName));

    if (ptr)
    {
        ptr->Run();
    }
    else
    {
        std::cerr << "Algorithm not chosen !" << std::endl;
    }

    return 0;
}
