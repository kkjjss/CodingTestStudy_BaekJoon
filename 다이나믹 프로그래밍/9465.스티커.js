const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split('\n');

const caseNum = input[0];

const inputArr = [];

for (let i = 0; i < caseNum; i++) {
    inputArr[i] = { n: input[3 * i + 1], sticker: [input[3 * i + 2].split(" ").map((n) => Number(n)), input[3 * i + 3].split(" ").map((n) => Number(n))] };
}

for (let i = 0; i < caseNum; i++) {
    console.log(bottomUp(inputArr[i]));
}

function bottomUp({ n, sticker }) {
    const memo = [
        [sticker[0][0], sticker[1][0] + sticker[0][1]],
        [sticker[1][0], sticker[0][0] + sticker[1][1]],
    ];

    for (let i = 2; i < n; i++) {
        memo[0][i] = sticker[0][i] + memo[1][i - 1] > sticker[0][i] + memo[1][i - 2] ? sticker[0][i] + memo[1][i - 1] : sticker[0][i] + memo[1][i - 2];
        memo[1][i] = sticker[1][i] + memo[0][i - 1] > sticker[1][i] + memo[0][i - 2] ? sticker[1][i] + memo[0][i - 1] : sticker[1][i] + memo[0][i - 2];
    }
    return Number(memo[0][n - 1] > memo[1][n - 1] ? memo[0][n - 1] : memo[1][n - 1]);
}
