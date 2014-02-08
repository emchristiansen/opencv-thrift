#include "OpenCV/Core/MatUtilHandler.hpp"

#include <opencv2/core/core.hpp>

#include "OpenCV/Core/MatUtil.h"

using namespace std;

/**
 * Converts a Thrift type to its OpenCV macro-definition equivalent.
 */
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

/**
 * Returns the Thrift type representing `numChannels` doubles.
 */
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

MatUtilHandler::MatUtilHandler() {
  // Your initialization goes here
}

void MatUtilHandler::pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked) {
  // Your implementation goes here
  printf("pack\n");

  // The syntax is a bit easier if we have a non-const version of this.
  MatUnpacked matUnpackedCopy(matUnpacked);

  // Copy the Thrift type into an OpenCV type.
  cv::Mat cvMatUnpacked(
    matUnpacked.rows, 
    matUnpacked.cols, 
    cvTypeToCVMacro(doubleTypeToCVType(matUnpacked.channels)),
    &matUnpackedCopy.data[0]);

  // Use OpenCV to convert to the target type.
  cv::Mat cvMat;
  cvMatUnpacked.convertTo(cvMat, cvTypeToCVMacro(type));

  // We're assuming the type transformation doesn't 
  // change the number of channels.
  assert(cvMat.rows == matUnpacked.rows);
  assert(cvMat.cols == matUnpacked.cols);
  assert(cvMat.channels() == matUnpacked.channels);

  // Copy the converted Mat back into a Thrift type.
  _return.rows = cvMatUnpacked.rows;
  _return.cols = cvMatUnpacked.cols;
  _return.channels = cvMatUnpacked.channels();
  _return.type = type;
  _return.data.assign(
     cvMat.begin<uchar>(),
     cvMat.end<uchar>());
}

void MatUtilHandler::unpack( ::MatUnpacked& _return, const  ::Mat& mat) {
  // Your implementation goes here
  printf("unpack\n");

  // The syntax is easier if we make a copy.
  Mat matCopy(mat);

  // Copy the Thrift type into an OpenCV type.
  cv::Mat cvMat(
    mat.rows,
    mat.cols,
    cvTypeToCVMacro(mat.type),
    &matCopy.data[0]);

  // Unpack the OpenCV type (convert its elements to doubles).
  cv::Mat cvMatUnpacked;
  cvMat.convertTo(
    cvMatUnpacked,
    cvTypeToCVMacro(doubleTypeToCVType(mat.channels)));

  _return.rows = mat.rows;
  _return.cols = mat.cols;
  _return.channels = mat.channels;
  _return.data.assign(
    cvMatUnpacked.begin<double>(),
    cvMatUnpacked.end<double>());
}

