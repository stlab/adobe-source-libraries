#!/bin/bash
set -e

BUILDDIR=${1:-../build_asl}

#
# CLANG
#

# system BOOST
BUILDMODE=RELEASE USE_SYSTEM_BOOST=ON   TOOLSET=clang++ BUILDDIR=${BUILDDIR} sh cmake_build.sh
BUILDMODE=DEBUG   USE_SYSTEM_BOOST=ON   TOOLSET=clang++ BUILDDIR=${BUILDDIR} sh cmake_build.sh

# local BOOST
BUILDMODE=RELEASE USE_SYSTEM_BOOST=OFF  TOOLSET=clang++ BUILDDIR=${BUILDDIR} sh cmake_build.sh
BUILDMODE=DEBUG   USE_SYSTEM_BOOST=OFF  TOOLSET=clang++ BUILDDIR=${BUILDDIR} sh cmake_build.sh

#
# GCC
#

# system BOOST
BUILDMODE=RELEASE USE_SYSTEM_BOOST=ON   TOOLSET=g++     BUILDDIR=${BUILDDIR} sh cmake_build.sh
BUILDMODE=DEBUG   USE_SYSTEM_BOOST=ON   TOOLSET=g++     BUILDDIR=${BUILDDIR} sh cmake_build.sh

# local BOOST
BUILDMODE=RELEASE USE_SYSTEM_BOOST=OFF  TOOLSET=g++     BUILDDIR=${BUILDDIR} sh cmake_build.sh
BUILDMODE=DEBUG   USE_SYSTEM_BOOST=OFF  TOOLSET=g++     BUILDDIR=${BUILDDIR} sh cmake_build.sh
