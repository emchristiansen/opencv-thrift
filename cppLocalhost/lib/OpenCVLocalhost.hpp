#ifndef _OpenCV_Localhost_
#define _OpenCV_Localhost_

#include "OpenCVThrift/OpenCV/Core/MatUtil.h"
#include "OpenCVThrift/OpenCV/Features2D/Features2D.h"

/**
 * Instantiate one of these to connect to a running Thrift 
 * server implementing the OpenCV interface.
 *
 * You probably don't want to instantiate more than one.
 */
struct OpenCV {
  struct Core {
    MatUtilClient matUtil; 

    Core();
  };

  struct Features2D {
    Features2DClient features2D;

    Features2D();
  };

  Core core;
  Features2D features2D;
};

#endif
