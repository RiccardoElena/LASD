#!/bin/bash

# Get the directory of the script
script_dir=$(dirname "$0")

echo "Enter the compiler command (e.g. g++, clang++, etc...):"
read compiler

echo "Enter the name for the executable file:"
read filename

eval_output=$(eval "$script_dir/compile.sh $compiler $filename" 2>&1)
# Check if there was an error
if [ $? -ne 0 ]; then
  echo "Error occurred:"
  echo "$eval_output"
  exit 1
fi

echo -e "\nCompilation complete\nExecuting ./$filename:\n"
eval_output=$(eval "$script_dir/run.sh $filename" 2>&1)

# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred"
    echo "$eval_output"
    exit 1
fi

echo "$eval_output"
