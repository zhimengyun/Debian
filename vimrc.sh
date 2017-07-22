#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/8.x/.vimrc"
filename=$(basename $sourcesfile)

# echo $sourcesfile
if [ -f "~/.vimrc" ];
then
  echo "backup .vimrc.bak~"
  mv ~/.vimrc ~/.vimrc.bak
  sleep 0.1

  echo "wget .vimrc~"
  wget $sourcesfile -O "$filename"
  sleep 0.1

  echo "replace .vimrc~"
  cp ./.vimrc ~/.vimrc
else
  echo "wget .vimrc~"
  wget $sourcesfile -O "$filename"
  sleep 0.1

  echo "cp .vimrc~"
  cp ./.vimrc ~/.vimrc
fi
