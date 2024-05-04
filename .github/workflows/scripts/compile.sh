find ./.. -name 'exercise*' -type d | grep -P 'exercise\d+$' | sort -V | tail -n 1 | while read dir; do
    g++ --version
    makefile="$dir/makefile"
    if [ -f "$makefile" ]; then
        echo "compiling $makefile"
        make -C "$dir"
    else
        echo "No makefile found in $dir"
    fi
done