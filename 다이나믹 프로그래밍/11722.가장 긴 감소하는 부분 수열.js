const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(/[\n ]/).map((e) => e * 1);

const memo = [0, 1];
let temp = 1;

function bottomUp() {
    for (let i = 2; i <= input[0]; i++) {
        memo[i] = 1;
        for (let j = i - 1; j > 0; j--) {
            if (input[j] > input[i]) memo[i] = Math.max(memo[i], memo[j]+1);
        }
        temp = Math.max(temp, memo[i]);
    }
    return temp;
}

console.log(bottomUp());
