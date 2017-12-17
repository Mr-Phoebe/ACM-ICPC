# Read from the file file.txt and output the tenth line to stdout.
#!/bin/bash
lines=0
while read -r line
do
    let lines=lines+1
    if(($lines == 10));then
        echo "$line"
    fi 
done<file.txt