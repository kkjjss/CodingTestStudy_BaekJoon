// const fs = require("fs");
// const input = fs.readFileSync("/dev/stdin").toString().trim();

// const num = Number(input);

const memo = [[], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]];
const date = new Date().getMilliseconds();

function bottomUp(num) {
    for (let i = 2; i <= num; i++) {
        memo[i] = [];
        for (let j = 0; j < 10; j++) {
            if (j === 0) {
                memo[i][0] = memo[i - 1][j + 1];
            } else if (j === 9) {
                memo[i][9] = memo[i - 1][j - 1];
            } else {
                memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j + 1];
            }
        }
    }
    let result = 0;
    memo[num].map((e) => {
        result += e;
    });
    return new Promise((resolve, reject) => {
        resolve(result % 1000000000);
    });
}

(async function () {
    console.log(await bottomUp(100));
})();

console.log(date - new Date().getMilliseconds());
