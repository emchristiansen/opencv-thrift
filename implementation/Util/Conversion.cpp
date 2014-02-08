#include "Util/Conversion.hpp"

#include <opencv2/core.hpp>

#include "OpenCV/Core/Mat_types.h"

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
  }
}

CVType::type doubleTypeToCVType(const int numChannels) {
  switch(numChannels) {
    case 1: 
      return CVType::type::T64FC1;
    case 2: 
      return CVType::type::T64FC2;
    case 3: 
      return CVType::type::T64FC2;
    case 4: 
      return CVType::type::T64FC4;
    default: 
      assert(false);
  }
}

cv::Mat matToCVMat(const Mat& mat) {
  // The syntax is easier with this copy.
  Mat matCopy(mat);

  cv::Mat cvMat(
    mat.rows,
    mat.cols,
    cvTypeToCVMacro(mat.type),
    &matCopy.data[0]);

  return cvMat;
}

Mat cvMatToMat(const cv::Mat& cvMat) {
  Mat mat;
  mat.rows = cvMat.rows;
  mat.cols = cvMat.cols;
  mat.channels = cvMat.channels();
  mat.type = cvMacroToCVType(cvMat.type());
  mat.data.assign(cvMat.begin<uchar>(), cvMat.end<uchar>());

  return mat;
}
