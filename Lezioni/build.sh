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
  echo "Enter the grade of optimization (0,1,2,3,s):"

  read opt
else
  opt=$2
fi

# check if path is given or is empty
if [ -z "$3" ]; then
  echo "Enter the path to the folder where the file cpp are located:"

  read path
else
  path=$3
fi

# check if filename is given or is empty
if [ -z "$4" ]; then
  echo "Enter the name for the file to execute:"

  read filename
else
  filename=$4
fi

# Get the directory of the script
script_dir=$(dirname "$0")

eval_output=$(eval "$script_dir/compile.sh $compiler $opt $path $filename" 2>&1)
# Check if there was an error
if [ $? -ne 0 ]; then
  echo "Error occurred:"
  echo "$eval_output"
  exit 1
fi

echo "$eval_output"

echo -e "\nCompilation complete\nExecuting $path/$filename.bin:\n"
eval_output=$(eval "$script_dir/run.sh $path/$filename" 2>&1)

# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred"
    echo "$eval_output"
    exit 1
fi

echo "$eval_output"
