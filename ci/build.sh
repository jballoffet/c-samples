#!/bin/bash

set -ex

#find -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
pushd ../01-Introduccion-a-C/ejemplo01/ && make && popd
