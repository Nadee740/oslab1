#!/bin/bash
echo "Enter the value of n::"
read n
i=$((n+1))
flag=0
while (($flag==0))
do
  j=2
  f=0
  while (($j<=$i/2&&$f==0))
  do
    if (($i%$j==0))
    then
      f=1
    fi
      j=$((j+1))
  done
  if [ $f -eq 0 ]
  then
    s=$i
    p=0
    while (($s!=0))
    do
      p=$((p*10+s%10))
      s=$((s/10))
    done
    if [ $p -eq $i ]
    then
      flag=1
    fi
  fi
  i=$((i+1))
done
echo "Smallest prime number greater than $n which is palindromic is $p."
