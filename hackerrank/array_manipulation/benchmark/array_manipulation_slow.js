'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

function arrayManipulation(n, queries) {
    // Fill with 0 to avoid issues with NaN
    let arr = new Array(n).fill(0)
    
    for (const idx in queries) {
        const [left, right, to_add] = queries[idx]
        for (let i = left-1; i < right; i+=1) {
            arr[i] += to_add
        }
    }

    let max = 0

    for (const idx in arr) {
        if (arr[idx] > max)
            max = arr[idx]
    }

    return max
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);
    const its = parseInt(process.env.BENCH_ITERATIONS, 10)

    const firstMultipleInput = readLine().replace(/\s+$/g, '').split(' ');

    const n = parseInt(firstMultipleInput[0], 10);

    const m = parseInt(firstMultipleInput[1], 10);

    let queries = Array(m);

    for (let i = 0; i < m; i++) {
        queries[i] = readLine().replace(/\s+$/g, '').split(' ').map(queriesTemp => parseInt(queriesTemp, 10));
    }

    let result = null
    for (let i = 0; i < its; i+=1) {
        result = arrayManipulation(n, queries);
    }

    ws.write(result + '\n');

    ws.end();
}
