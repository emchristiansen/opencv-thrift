include "OpenCV/Core/Mat.thrift"
include "OpenCV/Core/Types.thrift"

service Features2D {
  list<Types.KeyPoint> detect(string detectorType, Mat.Mat image)
}
