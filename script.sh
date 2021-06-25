#!/bin/bash

DIR="/home/aryan/.cp-archive"
cd ${DIR}
git add .
git commit -m "$(date +'%Y-%m-%d %H:%M:%S')"
git push