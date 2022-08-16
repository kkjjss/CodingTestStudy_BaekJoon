// const fs = require("fs");
// const input = fs.readFileSync("/dev/stdin").toString();
const input = `10
10 -4 3 1 5 6 -35 12 21 -1`
    .split(/[\n ]/)
    .map((e) => e * 1);

memo = [0, input[1]];
let temp = input[1];

(function bottomUp() {
    for (let i = 2; i <= input[0]; i++) {
        memo[i] = Math.max(input[i], input[i] + memo[i - 1]);
        temp = Math.max(temp, memo[i]);
    }
    console.log(temp);
})();
