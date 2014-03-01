#include "OpenCVThrift/OpenCV/Core/MatUtilHandler.hpp"

#include <opencv2/core.hpp>

#include "OpenCVThrift/OpenCV/Core/MatUtil.h"
#include "OpenCVThrift/OpenCV/Core/Conversion.hpp"

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

  std::cout << cvMat << std::endl;
  std::cout << matToCVMat(cvMatToMat(cvMat)) << std::endl;

  // Copy the converted Mat back into a Thrift type.
  _return = cvMatToMat(cvMat);
}

void MatUtilHandler::unpack( ::MatUnpacked& _return, const  ::Mat& mat) {
  // Your implementation goes here
  printf("unpack\n");

  // Copy the Thrift type into an OpenCV type.
  cv::Mat cvMat = matToCVMat(mat);

  std::cout << cvMat << std::endl;

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

