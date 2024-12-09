#include "ocrDetect.h"


// Constructor for network initialization
ocrDetect::ocrDetect()
{
    detectNet.initParam(detNetParam);
    detectNet.initBin(detNetBin);
    recNet.initParam(recNetParam);
    recNet.initBin(recNetBin);
    recNet.initKeys(initKeys);
}


bool ocrDetect::dataVerify(const std::vector<TextLine>& recResult)
{
    if (recResult.size() != 2)
        return false;

    std::string text1 = recResult[0].text;   // text1
    std::string text2 = recResult[1].text;   // text2

    // Check the length of the strings
    if (text1.size() == 8 && text2.size() == 5)
    {
        if (text1[0] == 'H')  // If the first character is not "H", it does not meet the requirement
        {
            try
            {
                int year = std::stoi(text1.substr(1, 2));  // The 2nd and 3rd characters represent the year
                int month = std::stoi(text1.substr(3, 2)); // The 4th and 5th characters represent the month
                int value = std::stoi(text2);              // The number in the second line

                if (year >= 20 && (month >= 1 && month <= 12) && (value >= 1 && value <= 10000))
                {
                    return true;
                }
            }
            catch (const std::invalid_argument& e)
            {
                // Catch and handle invalid argument exception
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                // Catch and handle out-of-range exception
                std::cerr << "Out of range: " << e.what() << std::endl;
            }
        }
    }

    // If conditions are not met, return false
    return false;
}


int ocrDetect::getDetectResult(cv::Mat& image)
{
    boxResult.clear();
    recResult.clear();

    // Call detectNet for object detection
    detectNet.forward(image, boxResult);
    std::cout << "boxResult size: " << boxResult.size() << std::endl;

    int ret_code = 0;

    // 样品瓶在旋转，可能会存在一行、两行的情形
    if (boxResult.size() > 0)
    {
        recResult.resize(boxResult.size());

        // Sort the boxes
        BoxSorter sorter;
        sorter.data = boxResult;
        std::vector<TextBox> sortedBoxResult = sorter.sortByCoordinates();
        // Process ocr results
        if (sortedBoxResult.size() > 0)
        {
            for (size_t i = 0; i < sortedBoxResult.size(); i++)
            {
                // Get the rotated cropped image
                cv::Mat partImg = getRotateCropImage(image, sortedBoxResult[i].boxPoint);
                // Use recNet for character recognition
                recNet.forward(partImg, recResult[i]);

                // Draw the bounding box and text
                cv::polylines(image, sortedBoxResult[i].boxPoint, true, cv::Scalar(0, 255, 0));

                // Draw the recognized text on the image
                std::cout << "boxResult boxPoint: " << sortedBoxResult[i].boxPoint << std::endl;
                std::cout << "recResult text: " << recResult[i].text << std::endl;

                cv::putText(image, recResult[i].text, sortedBoxResult[i].boxPoint[0],
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 1);
            }
        }

        // Verify the recognition result
        bool isReal = dataVerify(recResult);

        // Draw "OK" or "NG" at the top-left corner of the image
        std::string statusText = isReal ? "OK" : "NG";
        cv::Scalar statusColor = isReal ? cv::Scalar(0, 255, 0) : cv::Scalar(0, 0, 255);

        cv::putText(image, statusText, cv::Point(10, 30), // Position
            cv::FONT_HERSHEY_SIMPLEX, 1, // Font type and size
            statusColor, // Font color
            5); // Font thickness

        if (isReal)
        {
            ret_code = 1;  // Indicates the detection is OK
        }
        else
        {
            ret_code = 2;  // Indicates the detection is NG
        }
        return ret_code;
    }

    return ret_code;
}
