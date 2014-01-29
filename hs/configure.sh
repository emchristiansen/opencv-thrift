#! /bin/sh

cabal configure \
  --enable-tests \
  --enable-library-profiling \
  --enable-executable-profiling
