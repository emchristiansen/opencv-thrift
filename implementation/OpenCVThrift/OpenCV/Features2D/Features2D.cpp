/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "OpenCVThrift/OpenCV/Features2D/Features2D.h"



uint32_t Features2D_detect_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case -1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->detectorType);
          this->__isset.detectorType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->image.read(iprot);
          this->__isset.image = true;
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

uint32_t Features2D_detect_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Features2D_detect_args");

  xfer += oprot->writeFieldBegin("image", ::apache::thrift::protocol::T_STRUCT, -2);
  xfer += this->image.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("detectorType", ::apache::thrift::protocol::T_STRING, -1);
  xfer += oprot->writeString(this->detectorType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_detect_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Features2D_detect_pargs");

  xfer += oprot->writeFieldBegin("image", ::apache::thrift::protocol::T_STRUCT, -2);
  xfer += (*(this->image)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("detectorType", ::apache::thrift::protocol::T_STRING, -1);
  xfer += oprot->writeString((*(this->detectorType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_detect_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->success.clear();
            uint32_t _size6;
            ::apache::thrift::protocol::TType _etype9;
            xfer += iprot->readListBegin(_etype9, _size6);
            this->success.resize(_size6);
            uint32_t _i10;
            for (_i10 = 0; _i10 < _size6; ++_i10)
            {
              xfer += this->success[_i10].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
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

uint32_t Features2D_detect_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("Features2D_detect_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector< ::KeyPoint> ::const_iterator _iter11;
      for (_iter11 = this->success.begin(); _iter11 != this->success.end(); ++_iter11)
      {
        xfer += (*_iter11).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_detect_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            (*(this->success)).clear();
            uint32_t _size12;
            ::apache::thrift::protocol::TType _etype15;
            xfer += iprot->readListBegin(_etype15, _size12);
            (*(this->success)).resize(_size12);
            uint32_t _i16;
            for (_i16 = 0; _i16 < _size12; ++_i16)
            {
              xfer += (*(this->success))[_i16].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
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

uint32_t Features2D_extract_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case -1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->descriptorExtractorType);
          this->__isset.descriptorExtractorType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->image.read(iprot);
          this->__isset.image = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->keyPoints.clear();
            uint32_t _size17;
            ::apache::thrift::protocol::TType _etype20;
            xfer += iprot->readListBegin(_etype20, _size17);
            this->keyPoints.resize(_size17);
            uint32_t _i21;
            for (_i21 = 0; _i21 < _size17; ++_i21)
            {
              xfer += this->keyPoints[_i21].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.keyPoints = true;
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

uint32_t Features2D_extract_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Features2D_extract_args");

  xfer += oprot->writeFieldBegin("keyPoints", ::apache::thrift::protocol::T_LIST, -3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->keyPoints.size()));
    std::vector< ::KeyPoint> ::const_iterator _iter22;
    for (_iter22 = this->keyPoints.begin(); _iter22 != this->keyPoints.end(); ++_iter22)
    {
      xfer += (*_iter22).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("image", ::apache::thrift::protocol::T_STRUCT, -2);
  xfer += this->image.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("descriptorExtractorType", ::apache::thrift::protocol::T_STRING, -1);
  xfer += oprot->writeString(this->descriptorExtractorType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_extract_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Features2D_extract_pargs");

  xfer += oprot->writeFieldBegin("keyPoints", ::apache::thrift::protocol::T_LIST, -3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>((*(this->keyPoints)).size()));
    std::vector< ::KeyPoint> ::const_iterator _iter23;
    for (_iter23 = (*(this->keyPoints)).begin(); _iter23 != (*(this->keyPoints)).end(); ++_iter23)
    {
      xfer += (*_iter23).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("image", ::apache::thrift::protocol::T_STRUCT, -2);
  xfer += (*(this->image)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("descriptorExtractorType", ::apache::thrift::protocol::T_STRING, -1);
  xfer += oprot->writeString((*(this->descriptorExtractorType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_extract_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->success.read(iprot);
          this->__isset.success = true;
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

uint32_t Features2D_extract_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("Features2D_extract_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_extract_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += (*(this->success)).read(iprot);
          this->__isset.success = true;
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

uint32_t Features2D_match_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case -1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->descriptorMatcherType);
          this->__isset.descriptorMatcherType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->queryDescriptors.read(iprot);
          this->__isset.queryDescriptors = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case -3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->trainDescriptors.read(iprot);
          this->__isset.trainDescriptors = true;
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

uint32_t Features2D_match_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Features2D_match_args");

  xfer += oprot->writeFieldBegin("trainDescriptors", ::apache::thrift::protocol::T_STRUCT, -3);
  xfer += this->trainDescriptors.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("queryDescriptors", ::apache::thrift::protocol::T_STRUCT, -2);
  xfer += this->queryDescriptors.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("descriptorMatcherType", ::apache::thrift::protocol::T_STRING, -1);
  xfer += oprot->writeString(this->descriptorMatcherType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_match_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Features2D_match_pargs");

  xfer += oprot->writeFieldBegin("trainDescriptors", ::apache::thrift::protocol::T_STRUCT, -3);
  xfer += (*(this->trainDescriptors)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("queryDescriptors", ::apache::thrift::protocol::T_STRUCT, -2);
  xfer += (*(this->queryDescriptors)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("descriptorMatcherType", ::apache::thrift::protocol::T_STRING, -1);
  xfer += oprot->writeString((*(this->descriptorMatcherType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_match_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->success.clear();
            uint32_t _size24;
            ::apache::thrift::protocol::TType _etype27;
            xfer += iprot->readListBegin(_etype27, _size24);
            this->success.resize(_size24);
            uint32_t _i28;
            for (_i28 = 0; _i28 < _size24; ++_i28)
            {
              xfer += this->success[_i28].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
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

uint32_t Features2D_match_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("Features2D_match_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector< ::DMatch> ::const_iterator _iter29;
      for (_iter29 = this->success.begin(); _iter29 != this->success.end(); ++_iter29)
      {
        xfer += (*_iter29).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

uint32_t Features2D_match_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            (*(this->success)).clear();
            uint32_t _size30;
            ::apache::thrift::protocol::TType _etype33;
            xfer += iprot->readListBegin(_etype33, _size30);
            (*(this->success)).resize(_size30);
            uint32_t _i34;
            for (_i34 = 0; _i34 < _size30; ++_i34)
            {
              xfer += (*(this->success))[_i34].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
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

void Features2DClient::detect(std::vector< ::KeyPoint> & _return, const std::string& detectorType, const  ::Mat& image)
{
  send_detect(detectorType, image);
  recv_detect(_return);
}

void Features2DClient::send_detect(const std::string& detectorType, const  ::Mat& image)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("detect", ::apache::thrift::protocol::T_CALL, cseqid);

  Features2D_detect_pargs args;
  args.detectorType = &detectorType;
  args.image = &image;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void Features2DClient::recv_detect(std::vector< ::KeyPoint> & _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("detect") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  Features2D_detect_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "detect failed: unknown result");
}

void Features2DClient::extract(ExtractorResponse& _return, const std::string& descriptorExtractorType, const  ::Mat& image, const std::vector< ::KeyPoint> & keyPoints)
{
  send_extract(descriptorExtractorType, image, keyPoints);
  recv_extract(_return);
}

void Features2DClient::send_extract(const std::string& descriptorExtractorType, const  ::Mat& image, const std::vector< ::KeyPoint> & keyPoints)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("extract", ::apache::thrift::protocol::T_CALL, cseqid);

  Features2D_extract_pargs args;
  args.descriptorExtractorType = &descriptorExtractorType;
  args.image = &image;
  args.keyPoints = &keyPoints;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void Features2DClient::recv_extract(ExtractorResponse& _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("extract") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  Features2D_extract_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "extract failed: unknown result");
}

void Features2DClient::match(std::vector< ::DMatch> & _return, const std::string& descriptorMatcherType, const  ::Mat& queryDescriptors, const  ::Mat& trainDescriptors)
{
  send_match(descriptorMatcherType, queryDescriptors, trainDescriptors);
  recv_match(_return);
}

void Features2DClient::send_match(const std::string& descriptorMatcherType, const  ::Mat& queryDescriptors, const  ::Mat& trainDescriptors)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("match", ::apache::thrift::protocol::T_CALL, cseqid);

  Features2D_match_pargs args;
  args.descriptorMatcherType = &descriptorMatcherType;
  args.queryDescriptors = &queryDescriptors;
  args.trainDescriptors = &trainDescriptors;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void Features2DClient::recv_match(std::vector< ::DMatch> & _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("match") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  Features2D_match_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "match failed: unknown result");
}

bool Features2DProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void Features2DProcessor::process_detect(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("Features2D.detect", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "Features2D.detect");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "Features2D.detect");
  }

  Features2D_detect_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "Features2D.detect", bytes);
  }

  Features2D_detect_result result;
  try {
    iface_->detect(result.success, args.detectorType, args.image);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "Features2D.detect");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("detect", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "Features2D.detect");
  }

  oprot->writeMessageBegin("detect", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "Features2D.detect", bytes);
  }
}

void Features2DProcessor::process_extract(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("Features2D.extract", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "Features2D.extract");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "Features2D.extract");
  }

  Features2D_extract_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "Features2D.extract", bytes);
  }

  Features2D_extract_result result;
  try {
    iface_->extract(result.success, args.descriptorExtractorType, args.image, args.keyPoints);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "Features2D.extract");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("extract", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "Features2D.extract");
  }

  oprot->writeMessageBegin("extract", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "Features2D.extract", bytes);
  }
}

void Features2DProcessor::process_match(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("Features2D.match", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "Features2D.match");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "Features2D.match");
  }

  Features2D_match_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "Features2D.match", bytes);
  }

  Features2D_match_result result;
  try {
    iface_->match(result.success, args.descriptorMatcherType, args.queryDescriptors, args.trainDescriptors);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "Features2D.match");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("match", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "Features2D.match");
  }

  oprot->writeMessageBegin("match", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "Features2D.match", bytes);
  }
}

::boost::shared_ptr< ::apache::thrift::TProcessor > Features2DProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< Features2DIfFactory > cleanup(handlerFactory_);
  ::boost::shared_ptr< Features2DIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::boost::shared_ptr< ::apache::thrift::TProcessor > processor(new Features2DProcessor(handler));
  return processor;
}


