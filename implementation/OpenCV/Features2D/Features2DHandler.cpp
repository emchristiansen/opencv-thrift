#include "OpenCV/Features2D/Features2DHandler.hpp"

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

#include "OpenCV/Features2D/Features2D.h"
#include "Util/Conversion.hpp"

using namespace std;

Features2DHandler::Features2DHandler() {
  // Your initialization goes here
}

void Features2DHandler::detect(std::vector<KeyPoint> & _return, const std::string& detectorType, const  ::Mat& image) {
  // Your implementation goes here
  printf("detect\n");

  const cv::Ptr<cv::FeatureDetector> detector = cv::FeatureDetector::create(detectorType);
  
  vector<cv::KeyPoint> keyPoints;
  detector->detect(matToCVMat(image), keyPoints);
}

