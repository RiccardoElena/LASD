 find ./.. -name makefile | while read makefile; do
            dir=$(dirname "$makefile")
            make -C "$dir"
            $dir/main
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