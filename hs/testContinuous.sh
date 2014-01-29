run() {
  cabal clean &&
  sh configure.sh &&
  cabal build &&
  cabal test
}

while inotifywait -qq -r -e modify .; do run; echo "Done"; done
