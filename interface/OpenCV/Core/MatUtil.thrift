include "OpenCV/Core/Mat.thrift"

service MatUtil {
  Mat pack(required CVType type, required MatUnpacked matUnpacked)
  MatUnpacked unpack(required Mat mat)
}
