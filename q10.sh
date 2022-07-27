#!/bin/bash
echo "Enter the number of rows::"
read n
echo "Pattern ::"
for ((i=0; i<=n/2; i++))
do
  for ((j=0; j<n/2-i; j++))
  do
    echo -n "  "
  done
  for ((j=1; j<=2*i+1; j++))
  do
    echo -n "* "
  done
  echo
done
for ((i=n/2-1; i>=0; i--))
do
  for ((j=0; j<n/2-i; j++))
  do
    echo -n "  "
  done
  for ((j=1; j<=2*i+1; j++))
  do
    echo -n "* "
  done
  echo
done
