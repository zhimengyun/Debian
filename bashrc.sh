#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/9.x/.bashrc"
filename=$(basename $sourcesfile)

#验证权限
if [ "$(id -u)" != "0" ]; then
	echo "This script must be run as root!" 1>&2
	exit 1
fi

#备份目标文件
if [ -e "$HOME/.bashrc" ];
then
	echo "backup .bashrc.bak~"
	mv $HOME/.bashrc $HOME/".bashrc".$(date +%Y%m%d%H%M%S).bak
fi

if [ -e ".bashrc" ];
then
	mv ./.bashrc ./".bashrc".$(date +%Y%m%d%H%M%S).bak
fi

echo "wget .bashrc~"
wget $sourcesfile -O "$filename"

#更新目标文件
echo "replace .bashrc~"
cp ./.bashrc $HOME/.bashrc

# need bash exec
# source $HOME/.bashrc
