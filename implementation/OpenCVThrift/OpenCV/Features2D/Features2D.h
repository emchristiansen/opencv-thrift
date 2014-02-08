/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Features2D_H
#define Features2D_H

#include <thrift/TDispatchProcessor.h>
#include "OpenCVThrift/OpenCV/Features2D/Features2D_types.h"



class Features2DIf {
 public:
  virtual ~Features2DIf() {}
  virtual void detect(std::vector< ::KeyPoint> & _return, const std::string& detectorType, const  ::Mat& image) = 0;
};

class Features2DIfFactory {
 public:
  typedef Features2DIf Handler;

  virtual ~Features2DIfFactory() {}

  virtual Features2DIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(Features2DIf* /* handler */) = 0;
};

class Features2DIfSingletonFactory : virtual public Features2DIfFactory {
 public:
  Features2DIfSingletonFactory(const boost::shared_ptr<Features2DIf>& iface) : iface_(iface) {}
  virtual ~Features2DIfSingletonFactory() {}

  virtual Features2DIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(Features2DIf* /* handler */) {}

 protected:
  boost::shared_ptr<Features2DIf> iface_;
};

class Features2DNull : virtual public Features2DIf {
 public:
  virtual ~Features2DNull() {}
  void detect(std::vector< ::KeyPoint> & /* _return */, const std::string& /* detectorType */, const  ::Mat& /* image */) {
    return;
  }
};

typedef struct _Features2D_detect_args__isset {
  _Features2D_detect_args__isset() : detectorType(false), image(false) {}
  bool detectorType;
  bool image;
} _Features2D_detect_args__isset;

class Features2D_detect_args {
 public:

  static const char* ascii_fingerprint; // = "7746DEDACDC329AE11FA968092879CF2";
  static const uint8_t binary_fingerprint[16]; // = {0x77,0x46,0xDE,0xDA,0xCD,0xC3,0x29,0xAE,0x11,0xFA,0x96,0x80,0x92,0x87,0x9C,0xF2};

  Features2D_detect_args() : detectorType() {
  }

  virtual ~Features2D_detect_args() throw() {}

  std::string detectorType;
   ::Mat image;

  _Features2D_detect_args__isset __isset;

  void __set_detectorType(const std::string& val) {
    detectorType = val;
  }

  void __set_image(const  ::Mat& val) {
    image = val;
  }

  bool operator == (const Features2D_detect_args & rhs) const
  {
    if (!(detectorType == rhs.detectorType))
      return false;
    if (!(image == rhs.image))
      return false;
    return true;
  }
  bool operator != (const Features2D_detect_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Features2D_detect_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Features2D_detect_pargs {
 public:

  static const char* ascii_fingerprint; // = "7746DEDACDC329AE11FA968092879CF2";
  static const uint8_t binary_fingerprint[16]; // = {0x77,0x46,0xDE,0xDA,0xCD,0xC3,0x29,0xAE,0x11,0xFA,0x96,0x80,0x92,0x87,0x9C,0xF2};


  virtual ~Features2D_detect_pargs() throw() {}

  const std::string* detectorType;
  const  ::Mat* image;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Features2D_detect_result__isset {
  _Features2D_detect_result__isset() : success(false) {}
  bool success;
} _Features2D_detect_result__isset;

class Features2D_detect_result {
 public:

  static const char* ascii_fingerprint; // = "7204B800EC302039A020352D2E17125B";
  static const uint8_t binary_fingerprint[16]; // = {0x72,0x04,0xB8,0x00,0xEC,0x30,0x20,0x39,0xA0,0x20,0x35,0x2D,0x2E,0x17,0x12,0x5B};

  Features2D_detect_result() {
  }

  virtual ~Features2D_detect_result() throw() {}

  std::vector< ::KeyPoint>  success;

  _Features2D_detect_result__isset __isset;

  void __set_success(const std::vector< ::KeyPoint> & val) {
    success = val;
  }

  bool operator == (const Features2D_detect_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Features2D_detect_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Features2D_detect_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Features2D_detect_presult__isset {
  _Features2D_detect_presult__isset() : success(false) {}
  bool success;
} _Features2D_detect_presult__isset;

class Features2D_detect_presult {
 public:

  static const char* ascii_fingerprint; // = "7204B800EC302039A020352D2E17125B";
  static const uint8_t binary_fingerprint[16]; // = {0x72,0x04,0xB8,0x00,0xEC,0x30,0x20,0x39,0xA0,0x20,0x35,0x2D,0x2E,0x17,0x12,0x5B};


  virtual ~Features2D_detect_presult() throw() {}

  std::vector< ::KeyPoint> * success;

  _Features2D_detect_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class Features2DClient : virtual public Features2DIf {
 public:
  Features2DClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  Features2DClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void detect(std::vector< ::KeyPoint> & _return, const std::string& detectorType, const  ::Mat& image);
  void send_detect(const std::string& detectorType, const  ::Mat& image);
  void recv_detect(std::vector< ::KeyPoint> & _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class Features2DProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<Features2DIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (Features2DProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_detect(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  Features2DProcessor(boost::shared_ptr<Features2DIf> iface) :
    iface_(iface) {
    processMap_["detect"] = &Features2DProcessor::process_detect;
  }

  virtual ~Features2DProcessor() {}
};

class Features2DProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  Features2DProcessorFactory(const ::boost::shared_ptr< Features2DIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< Features2DIfFactory > handlerFactory_;
};

class Features2DMultiface : virtual public Features2DIf {
 public:
  Features2DMultiface(std::vector<boost::shared_ptr<Features2DIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~Features2DMultiface() {}
 protected:
  std::vector<boost::shared_ptr<Features2DIf> > ifaces_;
  Features2DMultiface() {}
  void add(boost::shared_ptr<Features2DIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void detect(std::vector< ::KeyPoint> & _return, const std::string& detectorType, const  ::Mat& image) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->detect(_return, detectorType, image);
    }
    ifaces_[i]->detect(_return, detectorType, image);
    return;
  }

};



#endif
