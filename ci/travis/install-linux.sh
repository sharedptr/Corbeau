#!/usr/bin/env bash

# Exit on first error
set -e

sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo add-apt-repository -y ppa:beineri/opt-qt591-trusty
sudo apt-get update -qq

#gcc with c++-14 support and Qt 5.9
sudo apt-get install -qq g++-5 qt59-meta
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 90

# modern cmake version
CMAKE_VERSION=3.9.1
CMAKE_VERSION_DIR=v3.9

CMAKE_OS=Linux-x86_64
CMAKE_TAR=cmake-$CMAKE_VERSION-$CMAKE_OS.tar.gz
CMAKE_URL=http://www.cmake.org/files/$CMAKE_VERSION_DIR/$CMAKE_TAR
CMAKE_DIR=$(pwd)/cmake-$CMAKE_VERSION

wget --quiet $CMAKE_URL
mkdir -p $CMAKE_DIR
tar --strip-components=1 -xzf $CMAKE_TAR -C $CMAKE_DIR
export PATH=$CMAKE_DIR/bin:$PATH
