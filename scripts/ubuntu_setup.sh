#!/usr/bin/env bash
set -xe

sudo apt-get update

# basic stuff
sudo apt-get install -y \
    wget \
    curl \
    apt-transport-https \
    git \
    build-essential

git --version
gcc --version
g++ --version
make --version

# CMake
wget -qO- "https://cmake.org/files/v3.12/cmake-3.12.3-Linux-x86_64.tar.gz" | sudo tar --strip-components=1 -xz -C /usr/local

cmake --version

# Visual Studio Code
curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/
rm -f microsoft.gpg
sudo sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" > /etc/apt/sources.list.d/vscode.list'
sudo apt-get update
sudo apt-get install -y code

code --version

code --install-extension eamodio.gitlens
code --install-extension ms-vscode.cpptools
code --install-extension twxs.cmake
code --install-extension vector-of-bool.cmake-tools

# clone repo
pushd $HOME
git clone https://github.com/MatthiasU/TDD-by-example.git
popd
