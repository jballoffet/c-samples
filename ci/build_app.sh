#!/bin/bash

set -e

find -type f -name 'Makefile' -exec bash -c 'cd "$(dirname "{}")" && make' \;
