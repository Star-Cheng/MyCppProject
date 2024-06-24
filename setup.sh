#!/usr/bin/env bash
cd ..
if [ ! -d "build" ]; then
    mkdir build
else
    echo "build directory already exists, skipping mkdir"
fi