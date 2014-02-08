#ifndef _OpenCV_Core_Conversion_
#define _OpenCV_Core_Conversion_

#include <opencv2/core.hpp>

#include "OpenCV/Core/Mat_types.h"
#include "OpenCV/Core/Types_types.h"

/**
 * Converts a Thrift type to its OpenCV macro-definition equivalent.
 */
int cvTypeToCVMacro(const CVType::type cvType);

/**
 * Converts an OpenCV macro-defintion representation of a type into
 * its Thrift equivalent.
 */
CVType::type cvMacroToCVType(const int cvMacro);

/**
 * Returns the Thrift type representing `numChannels` doubles.
 */
CVType::type doubleTypeToCVType(const int numChannels);

/**
 * Converts a Thrift Mat into a cv::Mat.
 */
cv::Mat matToCVMat(const Mat& mat);

/**
 * Converts a cv::Mat into a Thrift Mat.
 */
Mat cvMatToMat(const cv::Mat& cvMat);

KeyPoint cvKeyPointToKeyPoint(const cv::KeyPoint cvKeyPoint);

#endif
