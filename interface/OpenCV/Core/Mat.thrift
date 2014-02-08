include "OpenCV/Core/CVDef.thrift"

/**
 * A direct copy of a cv::Mat.
 * Data is stored as a binary blob, just like it is in OpenCV.
 */
struct Mat {
  required i64 rows
  required i64 cols
  required i64 channels
  required CVDef.CVType type
  required binary data
}

/**
 * Like a `Mat`, but each element of the 3D array is represented as a double.
 * This enables easy client-side manipulation of the data, at the cost of
 * increased memory usage.
 * Functions are provided to convert between a `MatUnpacked` and a `Mat`. 
 */
struct MatUnpacked {
  required i64 rows
  required i64 cols
  required i64 channels
  required list<double> data
}

