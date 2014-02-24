#!/bin/bash

thriftier --stub --cpp interface implementation
thriftier --client --cpp interface cpp
