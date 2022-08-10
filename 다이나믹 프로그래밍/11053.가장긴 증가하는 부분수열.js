const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(/[\n ]/).map((e) => e * 1);

const memo = [0, 1];
let temp = 1;

function bottomUp(num) {
    for (let i = 2; i <= num; i++) {
        memo[i] = 1;
        for (let j = i - 1; j > 0; j--) {
            if (input[j] < input[i]) {
                if (memo[j] >= memo[i]) memo[i] = memo[j] + 1;
            }
        }
        if (memo[i] > temp) temp = memo[i];
    }
    return temp;
}

console.log(bottomUp(input[0]));