#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/8.x/sources.list"
filename=$(basename $sourcesfile)

#验证权限
if [ "$(whoami)" != "root" ]; then
	echo "This script must be run as root!!" 1>&2
	exit 1
fi

#备份目标文件
if [ -e "/etc/apt/sources.list" ];
then
	echo "backup sources.list.bak~"
	mv /etc/apt/sources.list /etc/apt/"sources.list".$(date +%Y%m%d%H%M%S).bak
fi

if [ -e "sources.list" ];
then
	mv ./sources.list ./"sources.list".$(date +%Y%m%d%H%M%S).bak
fi

echo "wget sources.list~"
wget $sourcesfile -O "$filename"

#更新目标文件
echo "replace sources.list~"
cp ./sources.list /etc/apt/sources.list
