#include "OpenCV/Features2D/Features2DHandler.hpp"

#include "OpenCV/Features2D/Features2D.h"

Features2DHandler::Features2DHandler() {
  // Your initialization goes here
}

void Features2DHandler::detect(std::vector<KeyPoint> & _return, const std::string& detector, const  ::Mat& image) {
  // Your implementation goes here
  printf("detect\n");
}

