const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split('\n').map((e) => e * 1);

const [num] = input;

const memo = [0, input[1], input[1] + input[2]];

function bottomUp(num) {
    for (let i = 3; i <= num; i++) {
        memo[i] = Math.max(input[i] + memo[i - 2], input[i] + input[i - 1] + memo[i - 3], memo[i-1]);
    }
    return Math.max(memo[num-1], memo[num]);
}

console.log(bottomUp(num));
