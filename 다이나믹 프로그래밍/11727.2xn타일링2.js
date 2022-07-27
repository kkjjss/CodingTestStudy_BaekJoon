const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

const num = Number(input);

const memo = [0, 1];

function bottomUp(x) {
    for (let i = 2; i <= x; i++) {
        if (i % 2 === 0) {
            memo[i] = (2 * memo[i - 1] + 1) % 10007;
        } else {
            memo[i] = (2 * memo[i - 1] - 1) % 10007;
        }
    }
    return memo[x];
}

console.log(bottomUp(num));
