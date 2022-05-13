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
        
    // Instead of computing every sums, we
    // produce an array to represent the intervals
    // of the queries.
    //
    // By adding 'to_add' at the beginning and by substracting
    // it right after the end of the interval,
    // we build an intermediate representation of what arr should
    // look like in the end.
    
    for (const idx in queries) {
        const [left, right, to_add] = queries[idx]
        arr[left-1] += to_add
        arr[right] -= to_add
    }

    // By summing every cells from left to right,
    // we 'propagate' each query value to the right
    // until the end of the interval.
    // When we come across another non-zero value,
    // we start propagating it too.

    let max = 0

    for (const idx in arr) {
        if (idx > 0)
            arr[idx] += arr[idx-1]
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
