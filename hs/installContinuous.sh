run() {
  #cabal clean &&
  #sh configure.sh &&
  cabal build &&
  cabal install 
}

while inotifywait -qq -r -e modify .; do run; echo "Done"; done
