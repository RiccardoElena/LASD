# check if filename is given or is empty
if [ -z "$1" ]; then
  echo "Enter the file to execute with the path:"

  read filename
else
  file="$1.bin"
fi

./"$file"
# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred:"
    echo "$eval_output"
    exit 1
fi