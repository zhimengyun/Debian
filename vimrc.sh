#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/8.x/.vimrc"
filename=$(basename $sourcesfile)

#备份目标文件
if [ -e "$HOME/.vimrc" ];
then
  echo "backup .vimrc.bak~"
  mv $HOME/.vimrc $HOME/".vimrc".$(date +%Y%m%d%H%M%S).bak
fi

if [ -e ".vimrc" ];
then
  mv ./.vimrc ./".vimrc".$(date +%Y%m%d%H%M%S).bak
fi

echo "wget .vimrc~"
wget $sourcesfile -O "$filename"

#更新目标文件
echo "replace .vimrc~"
cp ./.vimrc $HOME/.vimrc
