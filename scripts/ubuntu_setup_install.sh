#!/usr/bin/ bash

sudo apt-get update

# WGet
sudo apt-get install wget

# CMake
wget https://cmake.org/files/v3.12/cmake-3.12.3-Linux-x86_64.sh
chmod +x cmake-3.12.3-Linux-x86_64.sh
sudo ./cmake-3.12.3-Linux-x86_64.sh

# Visual Studio Code
wget https://go.microsoft.com/fwlink/?LinkID=760868
sudo dpkg -i code_1.28.0-1538751525_amd64.deb

# Install Clang

# Set variables for tool versions to corresponding script argument or default
CLANG_VERSION=6.0

echo '--> uninstall other versions of clang compiler & tools...'
sudo apt-get remove clang* -y

echo '--> install Clang compiler and tools...'
sudo apt-get install -y \
        clang-${CLANG_VERSION} \
        clang-tidy-${CLANG_VERSION} \
        clang-format-${CLANG_VERSION}

echo '--> make clang the default compiler and set aliases for clang tools...'
sudo update-alternatives --install /usr/bin/cc cc /usr/bin/clang-${CLANG_VERSION} 100
sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-${CLANG_VERSION} 100
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-${CLANG_VERSION} 100
sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-${CLANG_VERSION} 100
sudo update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-${CLANG_VERSION} 100
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-${CLANG_VERSION} 100
