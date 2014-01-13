include "modules/core/mat.thrift"

struct KeyPoint {
}

service Features2D {
  list<KeyPoint> detect(string detector, mat.Mat image)
}
