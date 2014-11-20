#!/usr/bin/env bash

NAME="brightness-wrapper"
INSTALL_DIR="/usr/local/bin"

#Compile and give privileges to the wrapper
gcc main.c -o $NAME
chown root:root $NAME && chmod 4755 $NAME

#Past scripts to install directory
cp Brightness-up $INSTALL_DIR
cp Brightness-down $INSTALL_DIR
cp $NAME $INSTALL_DIR
