#include "OpenCVThrift/OpenCV/Core/CVDef_constants.h"
#include "OpenCVThrift/OpenCV/Core/CVDef_types.h"
#include "OpenCVThrift/OpenCV/Core/Types_constants.h"
#include "OpenCVThrift/OpenCV/Core/Types_types.h"
#include "OpenCVThrift/OpenCV/Core/Mat_constants.h"
#include "OpenCVThrift/OpenCV/Core/Mat_types.h"

#include "OpenCVLocalhost.hpp"

using namespace std;

void printMatUnpacked(const MatUnpacked& matUnpacked) {
  cout << "printMatUnpacked" << endl;
  cout << matUnpacked.rows << endl;
  cout << matUnpacked.cols << endl;
  cout << matUnpacked.channels << endl;
  for (auto e : matUnpacked.data) std::cout << e << ", ";
  cout << endl;
  cout << endl;
}

void printMat(const Mat& mat) {
  cout << "printMat" << endl;
  cout << mat.rows << endl;
  cout << mat.cols << endl;
  cout << mat.channels << endl;
  cout << mat.type << endl;
  cout << mat.data << endl;
  cout << endl;
}

// Create a MatUnpacked, convert it to a Mat via a server call, then
// convert it back with another call.
int main() {
  OpenCV openCV; 

  MatUnpacked matUnpacked;

  printMatUnpacked(matUnpacked);

  matUnpacked.rows = 2;
  matUnpacked.cols = 3;
  matUnpacked.channels = 1;
  matUnpacked.data = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };

  printMatUnpacked(matUnpacked);

  Mat mat;
  openCV.core.matUtil.pack(mat, CVType::type::T8UC1, matUnpacked);

  printMat(mat);

  MatUnpacked matUnpackedCopy;
  openCV.core.matUtil.unpack(matUnpackedCopy, mat);

  // This should be the same as matUnpacked.
  printMatUnpacked(matUnpackedCopy);
}
