include "OpenCV/Core/Mat.thrift"

struct KeyPoint {
}

service Features2D {
  list<KeyPoint> detect(string detector, Mat.Mat image)
}
