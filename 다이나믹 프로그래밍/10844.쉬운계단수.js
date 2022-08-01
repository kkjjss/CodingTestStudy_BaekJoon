// const fs = require("fs");
// const input = fs.readFileSync("/dev/stdin").toString().trim();

// const num = Number(input);

const memo = [[], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]];

function bottomUp(num) {
    for (let i = 2; i <= num; i++) {
        memo[i] = [];
        for (let j = 0; j < 10; j++) {
            memo[i][j] = ((memo[i - 1][j - 1] || 0) + (memo[i - 1][j + 1] || 0)) % 1000000000;
        }
    }
    return memo[num].reduce((acc, i) => {
        return (acc + i) % 10000000000;
    }, 0);
}

console.log(bottomUp(4));
