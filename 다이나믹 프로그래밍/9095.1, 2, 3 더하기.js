const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n").map((e)=>{
    return Number(e);
});

const memo = [0, 1, 2, 4];

function bottomUp(x) {
    for (let i = 4; i <= x; i++) {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    return memo[x];
}

for (let i = 1; i <= input[0]; i++) {
    console.log(bottomUp(input[i]));
}
