 find ./.. -name makefile | while read makefile; do
            dir=$(dirname "$makefile")
            echo "compiling $dir/makefile"
            make -C "$dir"
          done