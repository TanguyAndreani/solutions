#!/usr/bin/env bash

tests_dir=test/

temp_file_stdout=$(mktemp)
temp_file_stderr=$(mktemp)

for f in $(find $tests_dir -type f)
do

    command=$(sed -n 1p "$f")
    expected_status=$(sed -n 2p "$f")

    echo -ne $f

    echo $command > $temp_file_stdout
    echo $expected_status >> $temp_file_stdout

    eval "$command >> $temp_file_stdout 2> $temp_file_stderr"
    actual_status=$?

    git diff --no-index $f $temp_file_stdout > /dev/null

    if [ $? -eq 1 ] || [ $actual_status -ne $expected_status ]
    then 
        echo -e " (\e[31mFAILED\e[0m)"
        echo --------------------------------------
        echo -ne $command
        echo " (expected $expected_status, exited $actual_status)"
        echo --------------------------------------
        git --no-pager diff --no-index $f $temp_file_stdout
        echo --------------------------------------
        cat $temp_file_stderr
        echo --------------------------------------

    else
        echo -e " (\e[32mSUCCESS\e[0m)"
    fi
done

# Author: Tanguy Andreani <tanguy.andreani@tuta.io>, Adlan Sadou <adlan.sadou@epitech.eu>