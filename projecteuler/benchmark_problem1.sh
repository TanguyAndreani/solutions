#!/usr/bin/env bash

# USAGE: ./benchmark_problem1 1000000

make problem1
make problem1-slow

echo "./problem1"
time ./problem1 $1
echo
echo "./problem1-slow"
time ./problem1-slow $1