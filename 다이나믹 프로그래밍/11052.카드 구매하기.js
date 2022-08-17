const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(/[\n ]/).map((e) => e * 1);

const n = input[0];
const memo = [0, input[1]];

(function bottomUp() {
    for (let i = 2; i <= n; i++) {
        memo[i] = input[i];
        for (let j = i - 1; j >= i / 2; j--) {
            memo[i] = Math.max(memo[i], memo[j] + memo[i - j]);
        }
    }
})();

console.log(memo[n]);