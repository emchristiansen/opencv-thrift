#ifndef _OpenCVThrift_OpenCV_Features2D_Features2DHandler_
#define _OpenCVThrift_OpenCV_Features2D_Features2DHandler_

#include "OpenCVThrift/OpenCV/Features2D/Features2D.h"

class Features2DHandler : virtual public Features2DIf {
 public:
  Features2DHandler();

  void detect(std::vector< ::KeyPoint> & _return, const std::string& detectorType, const  ::Mat& image);
};


#endif // _OpenCVThrift_OpenCV_Features2D_Features2DHandler_
