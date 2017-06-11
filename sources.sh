#!/bin/bash
sourcesfile="https://raw.githubusercontent.com/zhimengyun/Debian/master/sources.list"

if [ ! -f "sources.list" ];
then
  echo "wget sources.list~"
  wget $sourcesfile
  sleep 0.1

  echo "backup sources.list.bak~"
  cp /etc/apt/sources.list /etc/apt/sources.list.bak
  sleep 0.1

  echo "replace sources.list~"
  cp ./sources.list /etc/apt/sources.list
fi
