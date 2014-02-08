/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MatUtil_H
#define MatUtil_H

#include <thrift/TDispatchProcessor.h>
#include "OpenCVThrift/OpenCV/Core/MatUtil_types.h"



class MatUtilIf {
 public:
  virtual ~MatUtilIf() {}
  virtual void pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked) = 0;
  virtual void unpack( ::MatUnpacked& _return, const  ::Mat& mat) = 0;
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
  void pack( ::Mat& /* _return */, const  ::CVType::type /* type */, const  ::MatUnpacked& /* matUnpacked */) {
    return;
  }
  void unpack( ::MatUnpacked& /* _return */, const  ::Mat& /* mat */) {
    return;
  }
};


class MatUtil_pack_args {
 public:

  static const char* ascii_fingerprint; // = "585F80C111320DFDCFD1CB463781D21C";
  static const uint8_t binary_fingerprint[16]; // = {0x58,0x5F,0x80,0xC1,0x11,0x32,0x0D,0xFD,0xCF,0xD1,0xCB,0x46,0x37,0x81,0xD2,0x1C};

  MatUtil_pack_args() : type(( ::CVType::type)0) {
  }

  virtual ~MatUtil_pack_args() throw() {}

   ::CVType::type type;
   ::MatUnpacked matUnpacked;

  void __set_type(const  ::CVType::type val) {
    type = val;
  }

  void __set_matUnpacked(const  ::MatUnpacked& val) {
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

  const  ::CVType::type* type;
  const  ::MatUnpacked* matUnpacked;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MatUtil_pack_result__isset {
  _MatUtil_pack_result__isset() : success(false) {}
  bool success;
} _MatUtil_pack_result__isset;

class MatUtil_pack_result {
 public:

  static const char* ascii_fingerprint; // = "944D360C52F98BBE4C6BB5ED53B4FDB7";
  static const uint8_t binary_fingerprint[16]; // = {0x94,0x4D,0x36,0x0C,0x52,0xF9,0x8B,0xBE,0x4C,0x6B,0xB5,0xED,0x53,0xB4,0xFD,0xB7};

  MatUtil_pack_result() {
  }

  virtual ~MatUtil_pack_result() throw() {}

   ::Mat success;

  _MatUtil_pack_result__isset __isset;

  void __set_success(const  ::Mat& val) {
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

  static const char* ascii_fingerprint; // = "944D360C52F98BBE4C6BB5ED53B4FDB7";
  static const uint8_t binary_fingerprint[16]; // = {0x94,0x4D,0x36,0x0C,0x52,0xF9,0x8B,0xBE,0x4C,0x6B,0xB5,0xED,0x53,0xB4,0xFD,0xB7};


  virtual ~MatUtil_pack_presult() throw() {}

   ::Mat* success;

  _MatUtil_pack_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class MatUtil_unpack_args {
 public:

  static const char* ascii_fingerprint; // = "15373E49370A4F9C7408527B3E33EF7E";
  static const uint8_t binary_fingerprint[16]; // = {0x15,0x37,0x3E,0x49,0x37,0x0A,0x4F,0x9C,0x74,0x08,0x52,0x7B,0x3E,0x33,0xEF,0x7E};

  MatUtil_unpack_args() {
  }

  virtual ~MatUtil_unpack_args() throw() {}

   ::Mat mat;

  void __set_mat(const  ::Mat& val) {
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

  static const char* ascii_fingerprint; // = "15373E49370A4F9C7408527B3E33EF7E";
  static const uint8_t binary_fingerprint[16]; // = {0x15,0x37,0x3E,0x49,0x37,0x0A,0x4F,0x9C,0x74,0x08,0x52,0x7B,0x3E,0x33,0xEF,0x7E};


  virtual ~MatUtil_unpack_pargs() throw() {}

  const  ::Mat* mat;

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

   ::MatUnpacked success;

  _MatUtil_unpack_result__isset __isset;

  void __set_success(const  ::MatUnpacked& val) {
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

   ::MatUnpacked* success;

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
  void pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked);
  void send_pack(const  ::CVType::type type, const  ::MatUnpacked& matUnpacked);
  void recv_pack( ::Mat& _return);
  void unpack( ::MatUnpacked& _return, const  ::Mat& mat);
  void send_unpack(const  ::Mat& mat);
  void recv_unpack( ::MatUnpacked& _return);
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
  void pack( ::Mat& _return, const  ::CVType::type type, const  ::MatUnpacked& matUnpacked) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pack(_return, type, matUnpacked);
    }
    ifaces_[i]->pack(_return, type, matUnpacked);
    return;
  }

  void unpack( ::MatUnpacked& _return, const  ::Mat& mat) {
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
