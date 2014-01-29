#include "OpenCV/Core/MatUtilHandler.hpp"

#include "OpenCV/Core/MatUtil.h"

MatUtilHandler::MatUtilHandler() {
  // Your initialization goes here
}

void MatUtilHandler::pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked) {
  // Your implementation goes here
  printf("pack\n");
}

void MatUtilHandler::unpack( ::MatUnpacked& _return, const  ::Mat& mat) {
  // Your implementation goes here
  printf("unpack\n");
}

