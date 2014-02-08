#ifndef _OpenCVThrift_OpenCV_Core_MatUtilHandler_
#define _OpenCVThrift_OpenCV_Core_MatUtilHandler_

#include "OpenCVThrift/OpenCV/Core/MatUtil.h"

class MatUtilHandler : virtual public MatUtilIf {
 public:
  MatUtilHandler();

  void pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked);

  void unpack( ::MatUnpacked& _return, const  ::Mat& mat);
};


#endif // _OpenCVThrift_OpenCV_Core_MatUtilHandler_
