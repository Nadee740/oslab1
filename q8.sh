#!/bin/bash
echo "Enter the value of n::"
read n
echo "Enter the numbers::"
for ((i=0; i<n; i++))
do
  read a[$i]
done
echo "Enter the key to be searched::"
read key
f=0
for ((i=0; i<n; i++))
do
  if [ ${a[i]} -eq $key ]
  then
    f=1
    break
  fi
done
if [ $f -eq 1 ]
then
  echo "key found at index $i"
else
  echo "Key not found!"
fi
