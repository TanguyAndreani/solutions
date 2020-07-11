#!/usr/bin/env bash

# USAGE: ./benchmark_problem2 4000000

make problem2
make problem2-slow

echo "./problem2"
time ./problem2 $1
echo
echo "./problem2-slow"
time ./problem2-slow $1