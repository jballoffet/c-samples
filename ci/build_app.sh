#!/bin/bash

set -ex

find -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
