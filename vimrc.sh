#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/8.x/.vimrc"

echo "wget .vimrc~"
wget $sourcesfile
sleep 0.1

if [ -f "~/.vimrc" ];
then
  echo "backup .vimrc.bak~"
  cp ./.vimrc ~/.vimrc.bak
  sleep 0.1

  echo "replace .vimrc~"
  cp ./.vimrc ~/.vimrc
else
  echo "cp .vimrc~"
  cp ./.vimrc ~/.vimrc
fi
