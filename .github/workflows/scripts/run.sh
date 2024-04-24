dir=$(ls -d ../exercise* | sort -V | tail -n 1)

# Controlla se la cartella contiene un makefile
if [ -f "$dir/makefile" ]; then
    $dir/main a
    result=$?
    output="Test terminated with $result error"
    if [ "$result" -ne 1 ]; then
      output+="s"
    fi
    echo $output
    if [ "$result" -ne 0 ]; then
      echo "Test failed! Please check the code before pushing again."
      exit 1
    fi
else
    echo "No makefile found in $dir"
fi