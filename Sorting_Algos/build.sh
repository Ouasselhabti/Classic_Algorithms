#!/bin/bash

# Specify the name of the output executable
OUTPUT="test"

# Compile the program with GCC
gcc -o $OUTPUT test.c sorting_algorithms.c

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable '$OUTPUT' created."
else
    echo "Compilation failed."
fi
