struct Point2f {
  required float x
  required float y
}

struct KeyPoint {
  required Point2f pt
  required float size
  required float angle
  required float response
  required int octave
  required int class_id
}
  
