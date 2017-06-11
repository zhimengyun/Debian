#!/bin/bash

cp /etc/apt/sources.list /etc/apt/sources.list.bak
wget https://raw.githubusercontent.com/zhimengyun/Debian/master/sources.list
cp ./sources.list /etc/apt/sources.list
