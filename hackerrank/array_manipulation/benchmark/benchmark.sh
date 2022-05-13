#!/bin/bash

echo "Input size: 4000 cells and 30000 queries"
export BENCH_ITERATIONS=100
echo "Number of iterations for benchmark: 100"
echo "Faster algorithm:"
time ./entrypoint.sh ./array_manipulation.js ./array_manipulation.input
echo "Slow algorithm:"
time ./entrypoint.sh ./array_manipulation_slow.js ./array_manipulation.input