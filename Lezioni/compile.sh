#!/bin/bash

# Default values
compiler="g++"
opt="0"
path="."
filename="program"

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

command="$compiler -O$opt"

for file in *.cpp; do
    command+=" $file"
done

command+=" -o $filename.bin"

echo -e "\nCompiling all files into $filename\n$command\n"
eval_output=$(cd "$path" && eval "$command" 2>&1)
# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred:"
    echo "$eval_output"
    exit 1
fi