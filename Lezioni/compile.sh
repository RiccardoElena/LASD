#!/bin/bash

# check if compiler is given or is empty
if [ -z "$1" ]; then
  echo "Enter the compiler command (e.g. g++, clang++, etc...):"

  read compiler
else
  compiler=$1
fi

# check if filename is given or is empty
if [ -z "$2" ]; then
  echo "Enter the name for the file to execute:"

  read filename
else
  filename=$2
fi

command=$compiler 

for file in *.cpp; do
    command+=" $file"
done

command+=" -o $filename"

echo -e "\nCompiling all files into $filename\n$command\n"
eval_output=$(eval "$command" 2>&1)
# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred:"
    echo "$eval_output"
    exit 1
fi