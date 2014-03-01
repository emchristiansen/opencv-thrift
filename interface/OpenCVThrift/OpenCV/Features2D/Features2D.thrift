include "OpenCVThrift/OpenCV/Core/Mat.thrift"
include "OpenCVThrift/OpenCV/Core/Types.thrift"

/**
 * The output of a call to an OpenCV descriptor extractor.
 * The descriptors are returned as a Mat, where each row is its own
 * descriptor.
 * If descriptor extraction fails, such as if the keypoint is at the edge
 * of an image, that row will not be added to the Mat, and the keypoint
 * mask for that keypoint will be marked as `false`.
 */
struct ExtractorResponse {
  required Mat.Mat descriptors
  required list<bool> keyPointMask
}

service Features2D {
  list<Types.KeyPoint> detect(string detectorType, Mat.Mat image)

  ExtractorResponse extract(
    string descriptorExtractorType, 
    Mat.Mat image, 
    list<Types.KeyPoint> keyPoints)

  list<Types.DMatch> match(
    string descriptorMatcherType, 
    Mat.Mat queryDescriptors, 
    Mat.Mat trainDescriptors)
}

