include "OpenCV/Core/Mat.thrift"

service MatUtil {
  Mat.Mat pack(required Mat.CVType type, required Mat.MatUnpacked matUnpacked)
  Mat.MatUnpacked unpack(required Mat.Mat mat)
}
