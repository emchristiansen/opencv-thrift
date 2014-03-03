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
  printf("detect\n");

  printf("Creating feature detector: %s\n", detectorType.c_str());
  const cv::Ptr<cv::FeatureDetector> detector =
    cv::FeatureDetector::create(detectorType);
  if (detector.empty()) {
    printf(
      "Failed to create feature detector: %s. Perhaps you are using the wrong name.\n",
      detectorType.c_str());
    assert(!detector.empty());
  }

  vector<cv::KeyPoint> cvKeyPoints;
  detector->detect(matToCVMat(image), cvKeyPoints);

  _return.resize(cvKeyPoints.size());
  transform(
    cvKeyPoints.begin(), 
    cvKeyPoints.end(), 
    _return.begin(), 
    cvKeyPointToKeyPoint);
}

void Features2DHandler::extract(ExtractorResponse& _return, const std::string& descriptorExtractorType, const  ::Mat& image, const std::vector< ::KeyPoint> & keyPoints) {
  printf("Creating descriptor extractor: %s\n", descriptorExtractorType.c_str());
  const cv::Ptr<cv::DescriptorExtractor> extractor =
    cv::DescriptorExtractor::create(descriptorExtractorType);
  if (extractor.empty()) {
    printf(
      "Failed to create descriptor extractor: %s. Perhaps you are using the wrong name.\n",
      descriptorExtractorType.c_str());
    assert(!extractor.empty());
  }

  vector<cv::KeyPoint> cvKeyPoints;
  cvKeyPoints.resize(keyPoints.size());
  transform(
    keyPoints.begin(),
    keyPoints.end(),
    cvKeyPoints.begin(),
    keyPointToCVKeyPoint);
  // We are assuming `class_id` isn't used for anything, and we're clobbering it
  // here.
  for (size_t i = 0; i < cvKeyPoints.size(); ++i) {
    cvKeyPoints.at(i).class_id = i;
  }

  cv::Mat cvDescriptors;
  extractor->compute(matToCVMat(image), cvKeyPoints, cvDescriptors);

  // The ith keyPoint was computed iff a keyPoint with class_id == i is in the
  // returned keyPoints.
  std::vector<bool> keyPointMask;
  keyPointMask.assign(keyPoints.size(), false);
  for (auto cvKeyPoint : cvKeyPoints) {
    keyPointMask.at(cvKeyPoint.class_id) = true;
  }

  ExtractorResponse extractorResponse;
  extractorResponse.descriptors = cvMatToMat(cvDescriptors);
  extractorResponse.keyPointMask = keyPointMask;

  _return = extractorResponse;
}


void Features2DHandler::match(std::vector< ::DMatch> & _return, const std::string& descriptorMatcherType, const  ::Mat& queryDescriptors, const  ::Mat& trainDescriptors) {
  // TODO
}
