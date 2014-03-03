#include "OpenCVThrift/OpenCV/Core/Conversion.hpp"

#include <opencv2/core.hpp>

#include "OpenCVThrift/OpenCV/Core/Mat_types.h"

using namespace std;

int cvTypeToCVMacro(const CVType::type cvType) {
  switch(cvType) {
    case CVType::type::T8UC1:
      return CV_8UC1;
    case CVType::type::T8UC2:
      return CV_8UC2;
    case CVType::type::T8UC3:
      return CV_8UC3;
    case CVType::type::T8UC4:
      return CV_8UC4;

    case CVType::type::T8SC1:
      return CV_8SC1;
    case CVType::type::T8SC2:
      return CV_8SC2;
    case CVType::type::T8SC3:
      return CV_8SC3;
    case CVType::type::T8SC4:
      return CV_8SC4;

    case CVType::type::T16UC1:
      return CV_16UC1;
    case CVType::type::T16UC2:
      return CV_16UC2;
    case CVType::type::T16UC3:
      return CV_16UC3;
    case CVType::type::T16UC4:
      return CV_16UC4;

    case CVType::type::T16SC1:
      return CV_16SC1;
    case CVType::type::T16SC2:
      return CV_16SC2;
    case CVType::type::T16SC3:
      return CV_16SC3;
    case CVType::type::T16SC4:
      return CV_16SC4;

    case CVType::type::T32SC1:
      return CV_32SC1;
    case CVType::type::T32SC2:
      return CV_32SC2;
    case CVType::type::T32SC3:
      return CV_32SC3;
    case CVType::type::T32SC4:
      return CV_32SC4;

    case CVType::type::T32FC1:
      return CV_32FC1;
    case CVType::type::T32FC2:
      return CV_32FC2;
    case CVType::type::T32FC3:
      return CV_32FC3;
    case CVType::type::T32FC4:
      return CV_32FC4;

    case CVType::type::T64FC1:
      return CV_64FC1;
    case CVType::type::T64FC2:
      return CV_64FC2;
    case CVType::type::T64FC3:
      return CV_64FC3;
    case CVType::type::T64FC4:
      return CV_64FC4;
  }
}

CVType::type cvMacroToCVType(const int cvMacro) {
  switch(cvMacro) {
    case CV_8UC1:
      return CVType::type::T8UC1;
    case CV_8UC2:
      return CVType::type::T8UC2;
    case CV_8UC3:
      return CVType::type::T8UC3;
    case CV_8UC4:
      return CVType::type::T8UC4;

    case CV_8SC1:
      return CVType::type::T8SC1;
    case CV_8SC2:
      return CVType::type::T8SC2;
    case CV_8SC3:
      return CVType::type::T8SC3;
    case CV_8SC4:
      return CVType::type::T8SC4;

    case CV_16UC1:
      return CVType::type::T16UC1;
    case CV_16UC2:
      return CVType::type::T16UC2;
    case CV_16UC3:
      return CVType::type::T16UC3;
    case CV_16UC4:
      return CVType::type::T16UC4;

    case CV_16SC1:
      return CVType::type::T16SC1;
    case CV_16SC2:
      return CVType::type::T16SC2;
    case CV_16SC3:
      return CVType::type::T16SC3;
    case CV_16SC4:
      return CVType::type::T16SC4;

    case CV_32SC1:
      return CVType::type::T32SC1;
    case CV_32SC2:
      return CVType::type::T32SC2;
    case CV_32SC3:
      return CVType::type::T32SC3;
    case CV_32SC4:
      return CVType::type::T32SC4;

    case CV_32FC1:
      return CVType::type::T32FC1;
    case CV_32FC2:
      return CVType::type::T32FC2;
    case CV_32FC3:
      return CVType::type::T32FC3;
    case CV_32FC4:
      return CVType::type::T32FC4;

    case CV_64FC1:
      return CVType::type::T64FC1;
    case CV_64FC2:
      return CVType::type::T64FC2;
    case CV_64FC3:
      return CVType::type::T64FC3;
    case CV_64FC4:
      return CVType::type::T64FC4;

    default:
      assert(false);
  }
}

CVType::type doubleTypeToCVType(const int numChannels) {
  switch(numChannels) {
    case 1: 
      return CVType::type::T64FC1;
    case 2: 
      return CVType::type::T64FC2;
    case 3: 
      return CVType::type::T64FC3;
    case 4: 
      return CVType::type::T64FC4;
    default: 
      assert(false);
  }
}

cv::Mat matToCVMat(const Mat& mat) {
  cv::Mat cvMat(
    mat.rows,
    mat.cols,
    cvTypeToCVMacro(mat.type));

  memcpy(
    cvMat.data,
    mat.data.data(),
    mat.data.size() * sizeof(char));  
  //std::copy(mat.data.begin(), mat.data.end(), cvMat.begin<char>());

  return cvMat;
}

Mat cvMatToMat(const cv::Mat& cvMat) {
  Mat mat;
  mat.rows = cvMat.rows;
  mat.cols = cvMat.cols;
  mat.channels = cvMat.channels();
  mat.type = cvMacroToCVType(cvMat.type());
  //mat.data.assign(cvMat.begin<char>(), cvMat.end<char>());
  //mat.data.assign(cvMat.datastart, cvMat.dataend);
  mat.data.assign(
    reinterpret_cast<char*>(cvMat.datastart),
    reinterpret_cast<char*>(cvMat.dataend));

  return mat;
}

KeyPoint cvKeyPointToKeyPoint(const cv::KeyPoint& cvKeyPoint) {
  Point2d point2d;
  point2d.x = cvKeyPoint.pt.x;
  point2d.y = cvKeyPoint.pt.y;

  KeyPoint keyPoint;
  keyPoint.pt = point2d;
  keyPoint.size = cvKeyPoint.size;
  keyPoint.angle = cvKeyPoint.angle;
  keyPoint.response = cvKeyPoint.response;
  keyPoint.octave = cvKeyPoint.octave;
  keyPoint.class_id = cvKeyPoint.class_id;

  return keyPoint;
}

cv::KeyPoint keyPointToCVKeyPoint(const KeyPoint& keyPoint) {
  return cv::KeyPoint(
    keyPoint.pt.x,
    keyPoint.pt.y,
    keyPoint.size,
    keyPoint.angle,
    keyPoint.response,
    keyPoint.octave,
    keyPoint.class_id);
}

