#! /bin/bash

export NUM_CPU="`grep processor /proc/cpuinfo | wc -l`"; echo $NUM_CPU

# Exit at the first error.
set -e

configureSystem() {
  sudo apt-get update
  #sudo apt-get dist-upgrade

  # General build tools.
  sudo apt-get install -y \
    libtool \
    autoconf \
    git \
    build-essential \
    cmake \
    clang \
    llvm \
    libc++-dev \
    ghc \
    cabal-install \
    pkg-config

  # Thrift prereqs.
  # http://thrift.apache.org/docs/install/ubuntu/
  sudo apt-get install -y \
    libboost-dev \
    libboost-test-dev \
    libboost-program-options-dev \
    libevent-dev \
    automake \
    libtool \
    flex \
    bison \
    pkg-config \
    libssl-dev \
    python-all \
    python-all-dev \
    python-all-dbg

    #g++-4.8 \

  # Haskell prereqs.
  cabal update
  cabal install HTTP hashable network text unordered-containers vector

  # Let's use clang and libc++ for everything.
  #sudo update-alternatives --set c++ /usr/bin/clang++-libc++
  #sudo update-alternatives --set c++ /usr/bin/clang++
}

installThrift() {
  git clone https://github.com/apache/thrift
  cd thrift
  ./bootstrap.sh
  # TODO: Try to let it build all the languages.
  ./configure \
    --with-ruby=no \
    --with-qt4=no \
    --with-c_glib=no \
    --with-csharp=no \
    --with-java=no \
    --with-haskell=no \
    --with-erlang=no \
    --with-nodejs=no \
    --with-python=yes \
    --with-perl=no \
    --with-php=no \
    --with-php_extension=no \
    --with-ruby=no \
    --with-go=no \
    --with-d=no
  make -j$NUM_CPU
  sudo make install
  cd ..
}

installOpenCV() {
  git clone https://github.com/Itseez/opencv.git
  cd opencv
  mkdir build
  cd build
  cmake ..
  make -j$NUM_CPU
  sudo make -j$NUM_CPU install
  cd ../..
}

installOpenCVThrift() {
  git clone https://github.com/emchristiansen/opencv-thrift
  cd opencv-thrift

  # Build and install the C++ implementation of the interface.
  #cd implementation
  #mkdir build
  #cd build
  #cmake ..
  #make -j$NUM_CPU
  #sudo make install
  #cd ../..

  # Build the localhost server.
  cd serverLocalhost
  mkdir build
  cd build
  cmake ..
  make -j$NUM_CPU
  cd ../..

  # Build the cpp localhost client.
  cd cppLocalhost
  mkdir build
  cd build
  cmake ..
  make -j$NUM_CPU
  cd ../..

  # Build the Haskell client wrapper.
  #cd hs
  #./configure.sh
  #cabal configure --enable-tests
  #cabal build
}

