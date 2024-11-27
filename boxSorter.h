#include <vector>
#include <algorithm>
#include <cmath>
#include "baseStruct.h"  // Contains the definitions of TextBox and TextLine

class BoxSorter {
public:
    std::vector<TextBox> data;    // data stores the bounding boxes

    std::vector<TextBox> sortByCoordinates(int threshold = 10) {
        std::vector<double> avgYCoordinates;   // Average coordinates of the bounding boxes
        for (const auto& box : data) {
            int topLeftY = box.boxPoint[0].y;
            int topRightY = box.boxPoint[1].y;
            int bottomRightY = box.boxPoint[2].y;
            int bottomLeftY = box.boxPoint[3].y;
            double avgY = (topLeftY + topRightY + bottomRightY + bottomLeftY) / 4.0;
            avgYCoordinates.push_back(avgY);
        }

        std::vector<TextBox> sortedData;   // The reordered bounding boxes
        std::vector<std::pair<int, double>> currentRow;

        for (size_t i = 0; i < data.size(); ++i) {
            if (currentRow.empty()) {
                currentRow.push_back({ static_cast<int>(i), avgYCoordinates[i] });
            }
            else {
                if (std::abs(avgYCoordinates[i] - currentRow[0].second) <= threshold) {
                    currentRow.push_back({ static_cast<int>(i), avgYCoordinates[i] });
                }
                else {
                    std::sort(currentRow.begin(), currentRow.end(), [this](const std::pair<int, double>& a, const std::pair<int, double>& b) {
                        int aLeft = this->data[a.first].boxPoint[0].x;
                        int bLeft = this->data[b.first].boxPoint[0].x;
                        return aLeft < bLeft;
                        });

                    for (const auto& item : currentRow) {
                        sortedData.push_back(this->data[item.first]);
                    }

                    currentRow = { {static_cast<int>(i), avgYCoordinates[i]} };
                }
            }
        }

        if (!currentRow.empty()) {
            std::sort(currentRow.begin(), currentRow.end(), [this](const std::pair<int, double>& a, const std::pair<int, double>& b) {
                int aLeft = this->data[a.first].boxPoint[0].x;
                int bLeft = this->data[b.first].boxPoint[0].x;
                return aLeft < bLeft;
                });

            for (const auto& item : currentRow) {
                sortedData.push_back(this->data[item.first]);
            }
        }

        return sortedData;
    }
};
