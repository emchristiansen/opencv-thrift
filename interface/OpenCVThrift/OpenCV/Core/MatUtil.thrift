include "OpenCVThrift/OpenCV/Core/CVDef.thrift"
include "OpenCVThrift/OpenCV/Core/Mat.thrift"

service MatUtil {
  Mat.Mat pack(required CVDef.CVType type, required Mat.MatUnpacked matUnpacked)
  Mat.MatUnpacked unpack(required Mat.Mat mat)
}
