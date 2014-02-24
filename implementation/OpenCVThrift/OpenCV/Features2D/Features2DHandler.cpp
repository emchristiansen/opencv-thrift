#include "OpenCVThrift/OpenCV/Features2D/Features2DHandler.hpp"

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

#include "OpenCVThrift/OpenCV/Features2D/Features2D.h"
#include "OpenCVThrift/OpenCV/Core/Conversion.hpp"

using namespace std;

Features2DHandler::Features2DHandler() {
  // Your initialization goes here
}

void Features2DHandler::detect(std::vector<KeyPoint> & _return, const std::string& detectorType, const  ::Mat& image) {
  // Your implementation goes here
  printf("detect\n");

  const cv::Ptr<cv::FeatureDetector> detector = cv::FeatureDetector::create(detectorType);
  
  vector<cv::KeyPoint> cvKeyPoints;
  detector->detect(matToCVMat(image), cvKeyPoints);

  transform(
    cvKeyPoints.begin(), 
    cvKeyPoints.end(), 
    _return.begin(), 
    cvKeyPointToKeyPoint);
}

void Features2DHandler::extract(std::vector<ExtractorResponse> & _return, const std::string& descriptorExtractorType, const  ::Mat& image, const std::vector< ::KeyPoint> & keyPoints) {
  // TODO
}


void Features2DHandler::match(std::vector< ::DMatch> & _return, const std::string& descriptorMatcherType, const  ::Mat& queryDescriptors, const  ::Mat& trainDescriptors) {
  // TODO
}
