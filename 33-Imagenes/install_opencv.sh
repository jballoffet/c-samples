#!/bin/bash
# @brief   Script para compilar e instalar OpenCV.
#          Ver https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html.
# @author  Javier Balloffet <jballoffet@frba.utn.edu.ar>
# @date    Oct 24, 2021
# @details Para ejecutar:
#            Opcion 1) $ sudo bash install_opencv.sh
#            Opcion 2) $ chmod +x install_opencv.sh
#                      $ sudo ./install_opencv.sh

set -e

# Este script debe ejecutarse como usuario root.
if [[ $UID != 0 ]]; then
  echo "Por favor ejecute este script como usuario root:"
  echo "sudo bash $0 $*"
  exit 1
fi

# Instalar dependencias.
apt-get update
apt-get install -y cmake g++ wget unzip libgtk2.0-dev

# Compilar OpenCV.
wget -O opencv.zip https://github.com/opencv/opencv/archive/refs/tags/3.4.16.zip
unzip opencv.zip
mkdir -p build && cd build
cmake  ../opencv-3.4.16
cmake --build .

# Instalar OpenCV.
make install
ldconfig

echo "Instalacion finalizada exitosamente!"
