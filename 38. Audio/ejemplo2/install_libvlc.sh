#!/bin/bash
# @brief   Script para compilar e instalar libVLC.
#          Ver https://wiki.videolan.org/LibVLC_Tutorial.
# @author  Javier Balloffet <javier.balloffet@gmail.com>
# @date    Oct 24, 2021
# @details Para ejecutar:
#            Opcion 1) $ sudo bash instalar_libvlc.sh
#            Opcion 2) $ chmod +x instalar_libvlc.sh
#                      $ sudo ./instalar_libvlc.sh

set -e

# Este script debe ejecutarse como usuario root.
if [[ $UID != 0 ]]; then
  echo "Por favor ejecute este script como usuario root:"
  echo "sudo bash $0 $*"
  exit 1
fi

# Instalar libVLC y sus dependencias.
apt-get update
apt-get install -y vlc libvlccore-dev libvlc-dev

echo "Instalacion finalizada exitosamente!"
