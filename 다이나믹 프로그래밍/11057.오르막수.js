const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

const num = Number(input);

const memo = [[], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]];

function bottomUp(num) {
    for (let i = 2; i <= num; i++) {
        memo[i] = [];
        for (let j = 0; j < 10; j++) {
            memo[i][j] = memo[i - 1].reduce((acc, cur, idx) => {
                return (idx <= j ? acc + cur : acc) % 10007;
            });
        }
    }
    return memo[num].reduce((acc, cur) => {
        return (acc + cur) % 10007;
    });
}

console.log(bottomUp(num));
