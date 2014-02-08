#include "OpenCV/Core/MatUtilHandler.hpp"

#include <opencv2/core/core.hpp>

#include "OpenCV/Core/MatUtil.h"

int cvTypeToCVMacro(const CVType::type cvType) {
}

CVType::type cvMacroToCVType(const int cvMacro) {
}

MatUtilHandler::MatUtilHandler() {
  // Your initialization goes here
}

void MatUtilHandler::pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked) {
  // Your implementation goes here
  printf("pack\n");

  CVType::type unpackedType;
  switch(matUnpacked.channels) {
    case 1: 
      unpackedType = CVType::type::T64FC1;
      break;
    case 2: 
      unpackedType = CVType::type::T64FC2;
      break;
    case 3: 
      unpackedType = CVType::type::T64FC2;
      break;
    case 4: 
      unpackedType = CVType::type::T64FC4;
      break;
    default: 
      assert(false);
  }

  cv::Mat cvUnpacked(matUnpacked.rows, matUnpacked.cols, cvTypeToCVMacro(unpackedType));
}

void MatUtilHandler::unpack( ::MatUnpacked& _return, const  ::Mat& mat) {
  // Your implementation goes here
  printf("unpack\n");
}

