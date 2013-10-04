#!/bin/bash
toDo=$1

dirnum=`find $toDo -type d | wc -l`
regnum=`find $toDo -type f | wc -l`

echo "Processed all the files from <$toDo>."
echo "There were $dirnum directories."
echo "There were $regnum regular files."
