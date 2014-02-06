#OpenCV-Thrift
This is a hand-written wrapper / RPC interface to [OpenCV](https://github.com/Itseez/opencv) using [Apache Thrift](https://github.com/apache/thrift).
It should make it easy to call OpenCV from [any one of a number of languages](http://thrift.apache.org/docs/features/), including: C++, C#, Cocoa, D, Delphi, Erlang, Haskell, Java, OCaml, Perl, PHP, Python, Ruby, and Smalltalk.
Like [Protocol Buffers](https://developers.google.com/protocol-buffers/), it allows any wrapped type to be serialized to an efficient format, for say disk storage.
Finally it provides an RPC mechanism, for making function calls across network connections.

##How this is different from OpenCV's existing FFIs
OpenCV already has foreign function interfaces (FFIs) to a number of languages besides C++, including Python, Java, Matlab.
These interfaces tend to expose pointers to C++ objects, rather than copying and translating those objects into native types of the target language.
This avoids copying-related overhead, but can make using such interfaces difficult from languages which are substantially different from C++ (e.g. Haskell).

A more serious problem with the existing FFIs is that they are automatically generated to mirror the C++ API, and the C++ API poses problems for non-C++-like languages.
In particular, it is not [referentially transparent](http://en.wikipedia.org/wiki/Referential_transparency_\(computer_science\)), making it a pain to integrate from Haskell.

 
This author (emchristiansen) actually helped develop the desktop Java interface.

#Getting started
Apache Thrift requires that a project's API be defined in terms of its own [interface definition language](http://thrift.apache.org/docs/idl/) (IDL).
It can then generate language-specifict server- and client-side stub code.

The installed version of the project should probably be renamed to OpenCVThrift to avoid naming conflicts with OpenCV itself.
