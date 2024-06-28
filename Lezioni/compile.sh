#!/bin/bash

# Default values
compiler="g++"
opt="3"
path="."
filename="a"
standard="c++20"

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
  std) standard=${OPTARG};;
  esac
done

# check if opt given is a valid optimization level
while [[ ! $opt =~ ^[0123s]$ ]]; do
  read -p "Invalid input. Enter the grade of optimization (0, 1, 2, 3, s): " opt
  if [ -z "$opt" ]; then
    opt="0"
    break
  fi
done

command="$compiler -O$opt -std=$standard"

for file in *.cpp; do
    command+=" $file"
done

command+=" -o $filename.out -std=c++17 -Wall -Wextra -Wpedantic -Werror"

echo -e "\nCompiling all files into $filename\n$command\n"
eval_output=$(cd "$path" && eval "$command" 2>&1)
# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred:"
    echo "$eval_output"
    exit 1
fi