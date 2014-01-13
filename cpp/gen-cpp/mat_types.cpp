/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "mat_types.h"

#include <algorithm>

namespace opencv {

const char* Mat::ascii_fingerprint = "4A712C500E54918CFBA57A70D875BC7B";
const uint8_t Mat::binary_fingerprint[16] = {0x4A,0x71,0x2C,0x50,0x0E,0x54,0x91,0x8C,0xFB,0xA5,0x7A,0x70,0xD8,0x75,0xBC,0x7B};

uint32_t Mat::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->rows);
          this->__isset.rows = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->cols);
          this->__isset.cols = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->type);
          this->__isset.type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->data);
          this->__isset.data = true;
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

  return xfer;
}

uint32_t Mat::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Mat");

  xfer += oprot->writeFieldBegin("rows", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->rows);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cols", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->cols);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeBinary(this->data);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Mat &a, Mat &b) {
  using ::std::swap;
  swap(a.rows, b.rows);
  swap(a.cols, b.cols);
  swap(a.type, b.type);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

} // namespace
