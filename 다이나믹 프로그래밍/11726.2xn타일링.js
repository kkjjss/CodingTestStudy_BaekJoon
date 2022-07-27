const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

const num = Number(input);

const memo = [0, 1, 2];

function bottomUp(x) {
    for(let i = 3; i<=x; i++){
        memo[i] = (memo[i-1]+memo[i-2])%10007;
    }
    return memo[x];
}

console.log(bottomUp(num));
