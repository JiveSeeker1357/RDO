#!/bin/bash -x
echo ">>> Cleaning old builds..."
rm -f rdo
echo ">>> Compiling rdo.c..."
gcc -o rdo rdo.c -Wall -Wextra -O2
if [ $? -eq 0 ]; then
    echo ">>> Build successful! Running test:"
    ./rdo -fm 90.8
else
    echo ">>> Build failed!"
    exit 1
fi
