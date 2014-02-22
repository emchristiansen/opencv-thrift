#include "OpenCVLocalhost.hpp"

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include "OpenCVThrift/OpenCV/Core/MatUtil.h"
#include "OpenCVThrift/OpenCV/Features2D/Features2D.h"
#include "OpenCVThrift/Ports_constants.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace boost;

template <typename Client>
Client connectClient(const int port) {
  boost::shared_ptr<TTransport> socket(new TSocket("localhost", port));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  Client client(protocol);

  // I'm guessing this connection is closed when the object is destroyed.
  // Still, you probably don't want to create more than one of these 
  // per client per machine.
  transport->open();

  return client;
}

OpenCV::Core::Core() : 
  matUtil(connectClient<MatUtilClient>(
    g_Ports_constants.basePort + g_Ports_constants.matUtilPortOffset)) {
  cout << "Connected MatUtil." << endl;
}

OpenCV::Features2D::Features2D() : 
  features2D(connectClient<Features2DClient>(
    g_Ports_constants.basePort + g_Ports_constants.features2DPortOffset)) {
  cout << "Connected Features2D." << endl;
}

