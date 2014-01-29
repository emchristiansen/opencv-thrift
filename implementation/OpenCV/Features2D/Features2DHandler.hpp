#ifndef _OpenCV_Features2D_Features2DHandler_
#define _OpenCV_Features2D_Features2DHandler_

#include "OpenCV/Features2D/Features2D.h"

class Features2DHandler : virtual public Features2DIf {
 public:
  Features2DHandler();

  void detect(std::vector<KeyPoint> & _return, const std::string& detector, const  ::Mat& image);
};


#endif // _OpenCV_Features2D_Features2DHandler_
