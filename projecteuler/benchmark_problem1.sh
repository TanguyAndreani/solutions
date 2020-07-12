#!/usr/bin/env bash
set -e

# USAGE: ./benchmark_problem1 1000000

make problem1
make problem1-slow

if [[ ${1} != "--only-make" ]]
then
  echo "./problem1"
  time ./problem1 $1
  echo
  echo "./problem1-slow"
  time ./problem1-slow $1
fi