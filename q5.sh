#!/bin/bash
i=100
echo "3 digit numbers that contain 0,1,2,3 ::"
while (($i<400))
do
  x=$i
  f=0
while (($x!=0)); do
    r=$((x%10))

    echo "$r" | grep -q [0-3]
    if [[ $? -eq 0 ]]; then
        x=$((x/10))
    else
      f=1
      break
    fi
done
  if [[ $f -eq 0 ]];
  then
    echo "$i"
  fi
  i=$((i+1))
done
