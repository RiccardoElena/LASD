set -e
total_time=0
execs=${1:-2000}
# Install bc if not already installed
if ! command -v bc &> /dev/null
then
    echo "bc could not be found, installing..."
    sudo apt-get update && sudo apt-get install -y bc
fi
find ./Esercizi -name 'exercise*' -type d -maxdepth 1 | grep -P 'exercise\d+$' | sort -V | tail -n 1 | while read dir; do
  make -C $dir
  for ((i=1; i<=execs; i++)); do
      runtime=$( { time $dir/main a > /dev/null; } 2>&1 | awk '/real/ { split($2, time, /[ms]/); print time[1]*60 + time[2] }' )
      
      total_time=$(echo "$total_time + $runtime" | bc)
      current_average=$(echo "scale=9; $total_time / $i" | bc)
      echo "Time at Exec $i: $runtime - Avg Time: $current_average" 
  done

  average_time=$(echo "scale=9; $total_time / $execs" | bc)
  echo "Average execution time: $average_time seconds"
done