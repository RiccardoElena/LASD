

find ./.. -name 'exercise*' -type d | grep -P 'exercise\d+$' | sort -V | tail -n 1 | while read dir; do
#  find ./.. -name 'exercise*' -type d | grep -P 'exercise2$' | sort -V | tail -n 2 | while read dir; do
    make -C $dir
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
done

