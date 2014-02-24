#OpenCV-Thrift
This is a hand-written wrapper / RPC interface to [OpenCV](https://github.com/Itseez/opencv) using [Apache Thrift](https://github.com/apache/thrift).
It was originally created to provide a Haskell interface, but it should make it easy to call OpenCV from [any one of a number of languages](http://thrift.apache.org/docs/features/), including: C++, C#, Cocoa, D, Delphi, Erlang, Haskell, Java, OCaml, Perl, PHP, Python, Ruby, and Smalltalk.
Like [Protocol Buffers](https://developers.google.com/protocol-buffers/), it allows any wrapped type to be serialized to an efficient format, for say disk storage.
Finally it provides an RPC mechanism for making function calls across network connections.

(Update: This isn't even alpha yet. Check back later.)

[![Build Status](https://drone.io/github.com/emchristiansen/opencv-thrift/status.png)](https://drone.io/github.com/emchristiansen/opencv-thrift/latest)
<!--[![Build Status](https://travis-ci.org/emchristiansen/opencv-thrift.png)](https://travis-ci.org/emchristiansen/opencv-thrift)-->

##How this is different from OpenCV's existing FFIs
OpenCV already has foreign function interfaces (FFIs) to a number of languages besides C++, including Python, Java, Matlab.
These interfaces tend to expose pointers to C++ objects, rather than copying and translating those objects into native types of the target language.
This avoids copying-related overhead, but can make using such interfaces difficult from languages which are substantially different from C++ (e.g. Haskell).

A more serious problem with the existing FFIs is that they are automatically generated to mirror the C++ API, and the C++ API poses problems for non-C++-like languages.
In particular, it is not [referentially transparent](http://en.wikipedia.org/wiki/Referential_transparency_\(computer_science\)), making it a pain to expose to Haskell.
So, to support Haskell, we need to write a new interface.
And we might as well write it in Thrift's IDL so we can talk to other languages for free.

##Related works

  * There are a number of Haskell projects which have attempted to wrap OpenCV.
    * The most recent that I know of is [by](https://github.com/arjuncomar/revelation) [Arjun](https://github.com/arjuncomar/opencv-raw) [Comar](https://github.com/arjuncomar/opencv).
This was taking the same tack as the official autogenerated wrappers for the other languages, so it had to work around difficulties with OpenCV's non-referentially-transparent API.
Unfortunately, the project seems dead at this point.
    * [HOpenCV](http://hackage.haskell.org/package/HOpenCV) and [CV](http://hackage.haskell.org/package/CV) both manually wrap a subset of OpenCV 2.x and seem poorly maintained.
  * [Cap'n Proto](http://kentonv.github.io/capnproto/capnp-tool.html), created by an author of Google's Protocol Buffers, seems like it may one day replace Thrift.
I'd like to use it, but I'll wait for it to officially support Haskell.

#Getting started
This project has a few moving parts, but I've tried to make it as simple and easy to understand as possible.
This section contains a brief guide for getting started as a developer (or as a user).

If you get lost trying to build things, remember to check out the build files: `continuousIntegration.sh` and `Dockerfile`.
They will tell you everything you need to know to build the project.
You can also test everything yourself, from installation to running examples, using [Docker](https://www.docker.io/).
Install Docker using [the instructions here](https://www.docker.io/gettingstarted/), then go to the root of this project and run `sudo docker build .`.
Note, this will eventually be run in continuous integration mode, but currently Travis CI does not support Docker.

##The interface and implementation
Apache Thrift requires a project's API be defined in terms of its own [interface definition language](http://thrift.apache.org/docs/idl/) (IDL).
It can then generate language-specific server-side stubs and client interfaces.
Those IDL files are in `interface/`.
Note: I'm staying as close as possible to the original code structure in OpenCV; each interface file corresponds to a single header in OpenCV and shares its name.
The only exception so far is `OpenCVThrift/OpenCV/Core/MatUtil.thrift`, which defines code for converting between OpenCV and Thrift types.

The implementation of the interface, written using C++ and OpenCV, is in `implementation/`.

If you want to extend the interface, make the appropriate changes in `interface/`, then run `thriftier --stub --cpp interface/ implementation/`.
(Note you will need to [install Thriftier first](https://github.com/emchristiansen/thriftier).)
This will update the server-side stub code in `implementation/`.
It will clobber the `hpp` files (you shouldn't modify them anyway), but will leave any `cpp` files you've added unchanged.
You'll then need to fill out the stubbed implementations in files named `*Handler.cpp`.

##Client languages
The client interfaces are in directories named for the languages.
For example, `cpp/` has the interface for C++, and `hs/` has the interface for Haskell.
Apache Thrift doesn't do a great job with Haskell, so the autogenerated interface has been modified a bit.

To generate or update an interface for a client language, we make sure the appropriate client directory exists, then again invoke Thrifter.
For example, to update the C++ interface we'd run `thriftier --client --cpp interface/ cpp/`.

##Running a program
Currently, Apache Thrift only works via RPC over some kind of network connection.
This isn't fundamental to the protocol, but for now you need to start an OpenCV server on a local port and connect to it with a network client.
`serverLocalhost/` defines an executable OpenCV server; start it before you run your client.
`cppLocalhost/` and `hsLocalhost/` contain convenience functions for using the OpenCV interface over a local port.
Look in their `example/` folders for example executables.

#TODO

  * The installed version of the project should probably be renamed to OpenCVThrift to avoid naming conflicts with OpenCV itself.
  * Fix Thrift's Haskell generator so it generates more idiomatic code.
  * Enhance Thrift so it doesn't require RPC.
