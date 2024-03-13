# check if filename is given or is empty
if [ -z "$1" ]; then
  echo "Enter the name for the file to execute:"

  read filename
else
  filename=$1
fi

./"$filename"
# Check if there was an error
if [ $? -ne 0 ]; then
    echo "Error occurred:"
    echo "$eval_output"
    exit 1
fi