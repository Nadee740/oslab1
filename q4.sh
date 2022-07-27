#!/bin/bash
echo "Enter password ::"
read password
l=${#password}
if [[ $l -ge 8 ]]; then
  echo "$password" | grep -q [A-Z] 
  if [[ $? -eq 0 ]]; then
    echo "$password" | grep -q [a-z]
    if [[ $? -eq 0 ]]; then
      echo "$password" | grep -q _
      if [[ $? -eq 0 ]]; then
        echo "Strong password"
      else
        echo "Weak password"
      fi
    else
      echo "Weak password"
    fi
  else
    echo "Weak password"
  fi
else
  echo "Weak password"
fi
