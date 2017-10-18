#!/usr/bin/env bash
reps=1000000
size=8192
test=1
[ -e cachetestreport ] && rm cachetestreport
while [ $test -le 2 ]
do
    echo "cachetest$((test))" >> cachetestreport
    count=1
    while [ $count -le 2048 ]
    do
        ./CS304-A3-mkem114-6273632/task_1/cachetest$((test)) --repetitions $((reps/count)) --array_size $((size*count)) | grep "time" | grep -oE '[0-9]+.[0-9]+' >> cachetestreport
        count=$(( $count * 2 ))
    done
    test=$(( $test + 1 ))
done