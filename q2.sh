#!/bin/bash
echo "Enter two numbers::"
read a
read b
echo "Amstrong numbers between $a and $b are "
n=$a
while [[ $n -le $b ]]
do
  x=$n
  y=$n
  r=0
  s=0
  while [[ $x -gt 0 ]]
  do
    r=$((x%10))
    s=$((s+r*r*r))
    x=$((x/10))
  done
  if [ $s -eq $y ]
  then
    echo "$n"
  fi
  n=$((n+1))
done
