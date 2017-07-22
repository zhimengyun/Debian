#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/8.x/.bashrc"
filename=$(basename $sourcesfile)

#验证权限
if [ "$(id -u)" != "0" ]; then
	echo "This script must be run as root!" 1>&2
	exit 1
fi

if [ "$HOME" != "/root" ]; then
	echo "This script must be run under /root!!!" 1>&2
	exit 1
fi

# echo $sourcesfile
if [ -f "~/.bashrc" ];
then
  echo "backup .bashrc.bak~"
  mv ~/.bashrc ~/.bashrc.bak
  sleep 0.1

  echo "wget .bashrc~"
  wget $sourcesfile -O "$filename"
  sleep 0.1

  echo "replace .bashrc~"
  cp ./.bashrc ~/.bashrc

	source ./.bashrc
else
  echo "wget .bashrc~"
  wget $sourcesfile -O "$filename"
  sleep 0.1

  echo "cp .bashrc~"
  cp ./.bashrc ~/.bashrc

	source ./.bashrc
fi
