const fs = require("fs");
const input = fs
    .readFileSync("/dev/stdin")
    .toString()
    .split(/[ \n]/)
    .map((e) => e * 1);

// 이건 안됨
// const [n, k, ...numbers] = input;

const [n, k] = input;

const sortedNumbers = input.slice(2, n+2).sort((a, b) => a - b);

console.log(sortedNumbers[k - 1]);
