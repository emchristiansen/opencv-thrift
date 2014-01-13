enum CVType {
  CV_8UC1
  CV_8UC2
  CV_8UC3
  CV_8UC4

  CV_8SC1
  CV_8SC2
  CV_8SC3
  CV_8SC4

  CV_16UC1
  CV_16UC2
  CV_16UC3
  CV_16UC4

  CV_16SC1
  CV_16SC2
  CV_16SC3
  CV_16SC4

  CV_32SC1
  CV_32SC2
  CV_32SC3
  CV_32SC4

  CV_32FC1
  CV_32FC2
  CV_32FC3
  CV_32FC4

  CV_64FC1
  CV_64FC2
  CV_64FC3
  CV_64FC4
}

struct Mat {
  i64 rows
  i64 cols
  i64 channels
  i64 type
  binary data
}

struct MatUnpacked {
  i64 rows
  i64 cols
  i64 channels
  list<double> data
}

service MatUtil {
  Mat pack(CVType type, MatUnpacked matUnpacked)
  MatUnpacked unpack(Mat mat)
}
