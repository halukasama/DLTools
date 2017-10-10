#!/bin/bash

set -e

print_help()
{
    echo "Usage: $0 <topdir> <destdir> <debug|release> "
}

DestDir=$2
buildmode=$3

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR 
TopDir=$(git rev-parse --show-toplevel)
cd -

ProjectName=DeviceToolbox
if [ "$buildmode" == "debug" ];
then
    binname=${ProjectName}-d
else
    binname=${ProjectName}
fi

mkdir -p ${DestDir}/bin/
mv ${TopDir}/bin/$binname ${DestDir}/bin/DeviceToolbox


