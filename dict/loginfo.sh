#!/bin/bash

# check for command line argument
if [ $# -eq 1 ] && [ $1 -gt 0 ]; then
  # invoke last with -n option to print only last N login lines
  S=$(last -n $1)
else
  # invoke last without any options to process entire last-log output
  S=$(last)
fi

# split the string S into an array A using new-line characters as delimiters
IFS=$'\n' read -d '' -ra A <<< "$S"

# get the size of the array A
n=${#A[@]}

# initialize an associative array H to store login counts of different users
declare -A H

# loop through the array A and extract the username from each line using a regular expression
for ((i=0;i<$n-2;i++))
do
  user=$(echo ${A[$i]} | grep -Eo "^[^[:space:]]+")
  # increment the login count of the user in the associative array H
  H[$user]=$(( ${H[$user]} + 1 ))
done

# print the list of users that logged on to the server and their respective login counts
echo "List of users that logged on to the server:"
for user in "${!H[@]}"
do
  echo "$user: ${H[$user]}"
done

