struct Point2d {
  required double x
  required double y
}

struct KeyPoint {
  // Thrift doesn't have 32-bit floats, so we use Point2d, not Point2f.
  required Point2d pt
  required double size
  required double angle
  required double response
  required i64 octave
  required i64 class_id
}
  
