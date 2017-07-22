#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/8.x/sources.list"
filename=$(basename $sourcesfile)

#验证权限
if [ "$(whoami)" != "root" ]; then
	echo "This script must be run as root!!" 1>&2
	exit 1
fi

if [ -f "sources.list" ];
then
  echo "backup sources.list.bak~"
  mv /etc/apt/sources.list /etc/apt/sources.list.bak
  sleep 0.1

  echo "wget sources.list~"
  wget $sourcesfile -O "$filename"
  sleep 0.1

  echo "replace sources.list~"
  cp ./sources.list /etc/apt/sources.list
else
  echo "wget sources.list~"
  wget $sourcesfile -O "$filename"
  sleep 0.1

  echo "cp sources.list~"
  cp ./sources.list /etc/apt/sources.list
fi
