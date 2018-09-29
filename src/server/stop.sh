#!/bin/bash
bin="./bin/run"
PID=`ps -eopid,cmd | grep "run" |  grep -v "grep"|grep -v "sh" |awk '{print $1}'`
echo $PID
if [ "$PID" != "" ]; then
        kill -9 $PID
            echo "kill -9 $PID"
fi
