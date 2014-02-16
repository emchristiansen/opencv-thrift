#! /bin/bash

export NUM_CPU="`grep processor /proc/cpuinfo | wc -l`"; echo $NUM_CPU

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
    g++ \
    libssl-dev \
    python-all \
    python-all-dev \
    python-all-dbg

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
  ./configure --without-ruby
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
  cd implementation
  mkdir build
  cd build
  cmake ..
  make -j$NUM_CPU
  sudo make install
  cd ../..

  # Build the localhost server.
  cd serverLocalhost
  mkdir build
  cd build
  cmake ..
  make -j$NUM_CPU
  cd ../..

  # Build the Haskell client wrapper.
  cd hs
  ./configure.sh
  cabal build
}

