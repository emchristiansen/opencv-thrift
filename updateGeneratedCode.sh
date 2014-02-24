#!/bin/bash

thriftier --stub --cpp interface implementation
thriftier --client --cpp interface cpp
# This introduces some minor breaks into the Haskell code, since Thrift is a 
# bit buggy here.
thriftier --client --haskell interface hs
