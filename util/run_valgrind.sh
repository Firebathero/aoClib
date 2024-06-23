#!/bin/bash

# Check if day number is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <day_number>"
    exit 1
fi

DAY=$1
OUTPUT_DIR="valgrind_output"
BINARY="./build/aoc_solve"

# Check if binary exists
if [ ! -f "$BINARY" ]; then
    echo "Error: $BINARY not found. Have you built the project?"
    exit 1
fi

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Run Callgrind
valgrind --tool=callgrind \
    --collect-jumps=yes \
    --cache-sim=yes \
    --branch-sim=yes \
    --callgrind-out-file="$OUTPUT_DIR/callgrind_day$DAY.out" \
    "$BINARY" "$DAY"

echo "Valgrind analysis complete. Output file: $OUTPUT_DIR/callgrind_day$DAY.out"
echo "You can analyze this file with a tool like KCachegrind."