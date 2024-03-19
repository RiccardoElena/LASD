#!/bin/bash

# Default values
compiler="g++"
opt="0"
path="."
filename="a"

# Analizza le opzioni del comando
while getopts c:o:p:f: option
do
  case "${option}"
  in
  c) compiler=${OPTARG};;
  o) case ${OPTARG} in
       0|1|2|3|s) opt=${OPTARG};;
       *) opt="";;
     esac;;
  p) path=${OPTARG};;
  f) filename=${OPTARG};;
  esac
done

# check if filename is given or is empty
if [ -z "$opt" ]; then
  read -p "Grade of optimization not given or invalid. Please enter the grade of optimization (0, 1, 2, 3, s): " opt
  while [[ ! $opt =~ ^[0123s]$ ]]; do
    if [ -z "$opt" ]; then
      opt="0"
      break
    fi
    read -p "Invalid input. Enter the grade of optimization (0, 1, 2, 3, s): " opt
  done
fi

# Get the directory of the script
script_dir=$(dirname "$0")

eval_output=$(eval "$script_dir/compile.sh -c $compiler -o $opt -p $path -f $filename" 2>&1)
# Check if there was an error
if [ $? -ne 0 ]; then
  echo "Error occurred:"
  echo "$eval_output"
  exit 1
fi

echo "$eval_output"

echo -e "\nCompilation complete\nExecuting $path/$filename.out:\n"
eval_output=$(eval "$script_dir/run.sh -f $path/$filename" 2>&1)

# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred"
    echo "$eval_output"
    exit 1
fi

echo "$eval_output"
