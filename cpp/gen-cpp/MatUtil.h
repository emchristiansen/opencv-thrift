/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MatUtil_H
#define MatUtil_H

#include <thrift/TDispatchProcessor.h>
#include "modules/core/gen-cpp/mat_types.h"



class MatUtilIf {
 public:
  virtual ~MatUtilIf() {}
  virtual void pack(Mat& _return, const CVType::type type, const MatUnpacked& matUnpacked) = 0;
  virtual void unpack(MatUnpacked& _return, const Mat& mat) = 0;
};

class MatUtilIfFactory {
 public:
  typedef MatUtilIf Handler;

  virtual ~MatUtilIfFactory() {}

  virtual MatUtilIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(MatUtilIf* /* handler */) = 0;
};

class MatUtilIfSingletonFactory : virtual public MatUtilIfFactory {
 public:
  MatUtilIfSingletonFactory(const boost::shared_ptr<MatUtilIf>& iface) : iface_(iface) {}
  virtual ~MatUtilIfSingletonFactory() {}

  virtual MatUtilIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(MatUtilIf* /* handler */) {}

 protected:
  boost::shared_ptr<MatUtilIf> iface_;
};

class MatUtilNull : virtual public MatUtilIf {
 public:
  virtual ~MatUtilNull() {}
  void pack(Mat& /* _return */, const CVType::type /* type */, const MatUnpacked& /* matUnpacked */) {
    return;
  }
  void unpack(MatUnpacked& /* _return */, const Mat& /* mat */) {
    return;
  }
};

typedef struct _MatUtil_pack_args__isset {
  _MatUtil_pack_args__isset() : type(false), matUnpacked(false) {}
  bool type;
  bool matUnpacked;
} _MatUtil_pack_args__isset;

class MatUtil_pack_args {
 public:

  static const char* ascii_fingerprint; // = "585F80C111320DFDCFD1CB463781D21C";
  static const uint8_t binary_fingerprint[16]; // = {0x58,0x5F,0x80,0xC1,0x11,0x32,0x0D,0xFD,0xCF,0xD1,0xCB,0x46,0x37,0x81,0xD2,0x1C};

  MatUtil_pack_args() : type((CVType::type)0) {
  }

  virtual ~MatUtil_pack_args() throw() {}

  CVType::type type;
  MatUnpacked matUnpacked;

  _MatUtil_pack_args__isset __isset;

  void __set_type(const CVType::type val) {
    type = val;
  }

  void __set_matUnpacked(const MatUnpacked& val) {
    matUnpacked = val;
  }

  bool operator == (const MatUtil_pack_args & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    if (!(matUnpacked == rhs.matUnpacked))
      return false;
    return true;
  }
  bool operator != (const MatUtil_pack_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MatUtil_pack_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MatUtil_pack_pargs {
 public:

  static const char* ascii_fingerprint; // = "585F80C111320DFDCFD1CB463781D21C";
  static const uint8_t binary_fingerprint[16]; // = {0x58,0x5F,0x80,0xC1,0x11,0x32,0x0D,0xFD,0xCF,0xD1,0xCB,0x46,0x37,0x81,0xD2,0x1C};


  virtual ~MatUtil_pack_pargs() throw() {}

  const CVType::type* type;
  const MatUnpacked* matUnpacked;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MatUtil_pack_result__isset {
  _MatUtil_pack_result__isset() : success(false) {}
  bool success;
} _MatUtil_pack_result__isset;

class MatUtil_pack_result {
 public:

  static const char* ascii_fingerprint; // = "CF63703DAE983CE80B9C7EC6043885EE";
  static const uint8_t binary_fingerprint[16]; // = {0xCF,0x63,0x70,0x3D,0xAE,0x98,0x3C,0xE8,0x0B,0x9C,0x7E,0xC6,0x04,0x38,0x85,0xEE};

  MatUtil_pack_result() {
  }

  virtual ~MatUtil_pack_result() throw() {}

  Mat success;

  _MatUtil_pack_result__isset __isset;

  void __set_success(const Mat& val) {
    success = val;
  }

  bool operator == (const MatUtil_pack_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MatUtil_pack_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MatUtil_pack_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MatUtil_pack_presult__isset {
  _MatUtil_pack_presult__isset() : success(false) {}
  bool success;
} _MatUtil_pack_presult__isset;

class MatUtil_pack_presult {
 public:

  static const char* ascii_fingerprint; // = "CF63703DAE983CE80B9C7EC6043885EE";
  static const uint8_t binary_fingerprint[16]; // = {0xCF,0x63,0x70,0x3D,0xAE,0x98,0x3C,0xE8,0x0B,0x9C,0x7E,0xC6,0x04,0x38,0x85,0xEE};


  virtual ~MatUtil_pack_presult() throw() {}

  Mat* success;

  _MatUtil_pack_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _MatUtil_unpack_args__isset {
  _MatUtil_unpack_args__isset() : mat(false) {}
  bool mat;
} _MatUtil_unpack_args__isset;

class MatUtil_unpack_args {
 public:

  static const char* ascii_fingerprint; // = "96E7516BB47ADDAD7B6FB950F3CB265B";
  static const uint8_t binary_fingerprint[16]; // = {0x96,0xE7,0x51,0x6B,0xB4,0x7A,0xDD,0xAD,0x7B,0x6F,0xB9,0x50,0xF3,0xCB,0x26,0x5B};

  MatUtil_unpack_args() {
  }

  virtual ~MatUtil_unpack_args() throw() {}

  Mat mat;

  _MatUtil_unpack_args__isset __isset;

  void __set_mat(const Mat& val) {
    mat = val;
  }

  bool operator == (const MatUtil_unpack_args & rhs) const
  {
    if (!(mat == rhs.mat))
      return false;
    return true;
  }
  bool operator != (const MatUtil_unpack_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MatUtil_unpack_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MatUtil_unpack_pargs {
 public:

  static const char* ascii_fingerprint; // = "96E7516BB47ADDAD7B6FB950F3CB265B";
  static const uint8_t binary_fingerprint[16]; // = {0x96,0xE7,0x51,0x6B,0xB4,0x7A,0xDD,0xAD,0x7B,0x6F,0xB9,0x50,0xF3,0xCB,0x26,0x5B};


  virtual ~MatUtil_unpack_pargs() throw() {}

  const Mat* mat;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MatUtil_unpack_result__isset {
  _MatUtil_unpack_result__isset() : success(false) {}
  bool success;
} _MatUtil_unpack_result__isset;

class MatUtil_unpack_result {
 public:

  static const char* ascii_fingerprint; // = "C91E96C8C703929413DC4A2325F9520B";
  static const uint8_t binary_fingerprint[16]; // = {0xC9,0x1E,0x96,0xC8,0xC7,0x03,0x92,0x94,0x13,0xDC,0x4A,0x23,0x25,0xF9,0x52,0x0B};

  MatUtil_unpack_result() {
  }

  virtual ~MatUtil_unpack_result() throw() {}

  MatUnpacked success;

  _MatUtil_unpack_result__isset __isset;

  void __set_success(const MatUnpacked& val) {
    success = val;
  }

  bool operator == (const MatUtil_unpack_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MatUtil_unpack_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MatUtil_unpack_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MatUtil_unpack_presult__isset {
  _MatUtil_unpack_presult__isset() : success(false) {}
  bool success;
} _MatUtil_unpack_presult__isset;

class MatUtil_unpack_presult {
 public:

  static const char* ascii_fingerprint; // = "C91E96C8C703929413DC4A2325F9520B";
  static const uint8_t binary_fingerprint[16]; // = {0xC9,0x1E,0x96,0xC8,0xC7,0x03,0x92,0x94,0x13,0xDC,0x4A,0x23,0x25,0xF9,0x52,0x0B};


  virtual ~MatUtil_unpack_presult() throw() {}

  MatUnpacked* success;

  _MatUtil_unpack_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class MatUtilClient : virtual public MatUtilIf {
 public:
  MatUtilClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  MatUtilClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void pack(Mat& _return, const CVType::type type, const MatUnpacked& matUnpacked);
  void send_pack(const CVType::type type, const MatUnpacked& matUnpacked);
  void recv_pack(Mat& _return);
  void unpack(MatUnpacked& _return, const Mat& mat);
  void send_unpack(const Mat& mat);
  void recv_unpack(MatUnpacked& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class MatUtilProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<MatUtilIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (MatUtilProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_pack(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_unpack(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MatUtilProcessor(boost::shared_ptr<MatUtilIf> iface) :
    iface_(iface) {
    processMap_["pack"] = &MatUtilProcessor::process_pack;
    processMap_["unpack"] = &MatUtilProcessor::process_unpack;
  }

  virtual ~MatUtilProcessor() {}
};

class MatUtilProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MatUtilProcessorFactory(const ::boost::shared_ptr< MatUtilIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< MatUtilIfFactory > handlerFactory_;
};

class MatUtilMultiface : virtual public MatUtilIf {
 public:
  MatUtilMultiface(std::vector<boost::shared_ptr<MatUtilIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~MatUtilMultiface() {}
 protected:
  std::vector<boost::shared_ptr<MatUtilIf> > ifaces_;
  MatUtilMultiface() {}
  void add(boost::shared_ptr<MatUtilIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void pack(Mat& _return, const CVType::type type, const MatUnpacked& matUnpacked) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pack(_return, type, matUnpacked);
    }
    ifaces_[i]->pack(_return, type, matUnpacked);
    return;
  }

  void unpack(MatUnpacked& _return, const Mat& mat) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->unpack(_return, mat);
    }
    ifaces_[i]->unpack(_return, mat);
    return;
  }

};



#endif
