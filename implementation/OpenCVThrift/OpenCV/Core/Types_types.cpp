/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "OpenCVThrift/OpenCV/Core/Types_types.h"

#include <algorithm>



const char* Point2d::ascii_fingerprint = "2D83AECC1446E2C25633117ADABE5995";
const uint8_t Point2d::binary_fingerprint[16] = {0x2D,0x83,0xAE,0xCC,0x14,0x46,0xE2,0xC2,0x56,0x33,0x11,0x7A,0xDA,0xBE,0x59,0x95};

uint32_t Point2d::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_x = false;
  bool isset_y = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case -1:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->x);
          isset_x = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->y);
          isset_y = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_x)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_y)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Point2d::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Point2d");

  xfer += oprot->writeFieldBegin("y", ::apache::thrift::protocol::T_DOUBLE, -2);
  xfer += oprot->writeDouble(this->y);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("x", ::apache::thrift::protocol::T_DOUBLE, -1);
  xfer += oprot->writeDouble(this->x);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Point2d &a, Point2d &b) {
  using ::std::swap;
  swap(a.x, b.x);
  swap(a.y, b.y);
}

const char* KeyPoint::ascii_fingerprint = "F18CFD6EA9146B31D026A0673D45A451";
const uint8_t KeyPoint::binary_fingerprint[16] = {0xF1,0x8C,0xFD,0x6E,0xA9,0x14,0x6B,0x31,0xD0,0x26,0xA0,0x67,0x3D,0x45,0xA4,0x51};

uint32_t KeyPoint::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_pt = false;
  bool isset_size = false;
  bool isset_angle = false;
  bool isset_response = false;
  bool isset_octave = false;
  bool isset_class_id = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case -1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->pt.read(iprot);
          isset_pt = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->size);
          isset_size = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -3:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->angle);
          isset_angle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -4:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->response);
          isset_response = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->octave);
          isset_octave = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->class_id);
          isset_class_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_pt)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_size)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_angle)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_response)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_octave)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_class_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t KeyPoint::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("KeyPoint");

  xfer += oprot->writeFieldBegin("class_id", ::apache::thrift::protocol::T_I64, -6);
  xfer += oprot->writeI64(this->class_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("octave", ::apache::thrift::protocol::T_I64, -5);
  xfer += oprot->writeI64(this->octave);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("response", ::apache::thrift::protocol::T_DOUBLE, -4);
  xfer += oprot->writeDouble(this->response);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("angle", ::apache::thrift::protocol::T_DOUBLE, -3);
  xfer += oprot->writeDouble(this->angle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("size", ::apache::thrift::protocol::T_DOUBLE, -2);
  xfer += oprot->writeDouble(this->size);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pt", ::apache::thrift::protocol::T_STRUCT, -1);
  xfer += this->pt.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(KeyPoint &a, KeyPoint &b) {
  using ::std::swap;
  swap(a.pt, b.pt);
  swap(a.size, b.size);
  swap(a.angle, b.angle);
  swap(a.response, b.response);
  swap(a.octave, b.octave);
  swap(a.class_id, b.class_id);
}

const char* DMatch::ascii_fingerprint = "99C6A2DB7B76682794F5CE24E004CB5A";
const uint8_t DMatch::binary_fingerprint[16] = {0x99,0xC6,0xA2,0xDB,0x7B,0x76,0x68,0x27,0x94,0xF5,0xCE,0x24,0xE0,0x04,0xCB,0x5A};

uint32_t DMatch::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_queryIndex = false;
  bool isset_trainIndex = false;
  bool isset_imageIndex = false;
  bool isset_distance = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case -1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->queryIndex);
          isset_queryIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->trainIndex);
          isset_trainIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->imageIndex);
          isset_imageIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -4:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->distance);
          isset_distance = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_queryIndex)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_trainIndex)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_imageIndex)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_distance)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t DMatch::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("DMatch");

  xfer += oprot->writeFieldBegin("distance", ::apache::thrift::protocol::T_DOUBLE, -4);
  xfer += oprot->writeDouble(this->distance);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("imageIndex", ::apache::thrift::protocol::T_I64, -3);
  xfer += oprot->writeI64(this->imageIndex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("trainIndex", ::apache::thrift::protocol::T_I64, -2);
  xfer += oprot->writeI64(this->trainIndex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("queryIndex", ::apache::thrift::protocol::T_I64, -1);
  xfer += oprot->writeI64(this->queryIndex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DMatch &a, DMatch &b) {
  using ::std::swap;
  swap(a.queryIndex, b.queryIndex);
  swap(a.trainIndex, b.trainIndex);
  swap(a.imageIndex, b.imageIndex);
  swap(a.distance, b.distance);
}


