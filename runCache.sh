#!/usr/bin/env bash
count=1
reps=500000
size=8192
test=1
echo "" > cachetestreport
while [ $test -le 2 ]
do
    echo "cachetest$((test))" >> cachetestreport
    while [ $count -le 2048 ]
    do
        ./CS304-A3-mkem114-6273632/task_1/cachetest$((test)) --repetitions $((reps/count)) --array_size $((size*count)) | grep "time" | grep -oE '[0-9]+.[0-9]+' >> cachetestreport
        count=$(( $count * 2 ))
    done
    test=$(( $test + 1 ))
done