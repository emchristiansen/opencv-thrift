enum CVType {
  T8UC1
  T8UC2
  T8UC3
  T8UC4

  T8SC1
  T8SC2
  T8SC3
  T8SC4

  T16UC1
  T16UC2
  T16UC3
  T16UC4

  T16SC1
  T16SC2
  T16SC3
  T16SC4

  T32SC1
  T32SC2
  T32SC3
  T32SC4

  T32FC1
  T32FC2
  T32FC3
  T32FC4

  T64FC1
  T64FC2
  T64FC3
  T64FC4
}

struct Mat {
  required i64 rows
  required i64 cols
  required i64 channels
  required CVType type
  required binary data
}

struct MatUnpacked {
  required i64 rows
  required i64 cols
  required i64 channels
  required list<double> data
}

