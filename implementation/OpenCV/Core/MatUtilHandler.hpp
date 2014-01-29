#ifndef _OpenCV_Core_MatUtilHandler_
#define _OpenCV_Core_MatUtilHandler_

#include "OpenCV/Core/MatUtil.h"

class MatUtilHandler : virtual public MatUtilIf {
 public:
  MatUtilHandler();

  void pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked);

  void unpack( ::MatUnpacked& _return, const  ::Mat& mat);
};


#endif // _OpenCV_Core_MatUtilHandler_
