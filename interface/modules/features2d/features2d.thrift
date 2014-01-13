include "modules/core/mat.thrift"

namespace cpp cv

struct KeyPoint {
}

service Features2D {
  list<KeyPoint> detect(string detector, Mat image)
}
