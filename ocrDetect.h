#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <cstdlib>
// #include "opencv2/freetype.hpp"
#include "crnnNet.h"
#include "dbNet.h"
#include "tools.h"
#include "boxSorter.h"

class ocrDetect
{
public:
    ocrDetect();  // Constructor for network initialization
    bool dataVerify(const std::vector<TextLine>& recResult);   // Perform data verification
    int getDetectResult(cv::Mat& image);

private:
    dbNet detectNet;
    crnnNet recNet;
    std::vector<TextBox> boxResult;
    std::vector<TextLine> recResult;

private:
    std::string detNetParam = "C:/QTDemo/modbusCamera/weights/det.param";
    std::string detNetBin = "C:/QTDemo/modbusCamera/weights/det.bin";
    std::string recNetParam = "C:/QTDemo/modbusCamera/weights/ch_PP_OCRv4_rec_infer.ncnn.param";
    std::string recNetBin = "C:/QTDemo/modbusCamera/weights/ch_PP_OCRv4_rec_infer.ncnn.bin";
    std::string initKeys = "C:/QTDemo/modbusCamera/weights/dict_chi_sim.txt";
};
