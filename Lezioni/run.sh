#!/bin/bash

# Default values
file="a"

while getopts f: option
do
  case "${option}"
  in
  f) file=${OPTARG};;
  esac
done

echo -e "\nExecuting $file:\n"


./"$file"
# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred:"
    echo "$eval_output"
    exit 1
fi