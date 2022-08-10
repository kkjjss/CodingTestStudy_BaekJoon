const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(/[\n ]/).map((e) => e * 1);

const memo = [0, input[1]];
let temp = input[1];

function bottomUp(num) {
    for (let i = 2; i <= num; i++) {
        memo[i] = input[i];
        for (let j = i - 1; j > 0; j--) {
            if (input[j] < input[i]) {
                if (memo[j] + input[i] >= memo[i]) memo[i] = memo[j] + input[i];
            }
        }
        if (memo[i] > temp) temp = memo[i];
    }
    return temp;
}

console.log(bottomUp(input[0]));
