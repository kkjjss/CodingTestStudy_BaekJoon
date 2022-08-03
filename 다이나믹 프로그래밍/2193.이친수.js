// const fs = require("fs");
// const input = fs.readFileSync("/dev/stdin").toString().trim();

// const num = Number(input);

const memo = [[], [0, 1]];

function bottomUp(num) {
    for (let i = 2; i <= num; i++) {
        memo[i] = [BigInt(memo[i - 1][0] + memo[i - 1][1]), BigInt(memo[i - 1][0])];
    }
    return BigInt(memo[num][0] + memo[num][1]).toString();
}

console.log(bottomUp(90));
