#!/bin/bash

for fn in "$@"
do
  if [[ ! -f $fn ]]
  then
    echo "File $fn does not exists in the current directory"
  else
    echo "$fn-"
   tr '[a-z]' '[A-Z]' < "$fn"
  fi
done
