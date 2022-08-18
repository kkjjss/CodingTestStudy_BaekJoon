const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("");

const memo = [1];

(function bottomUp() {
    for (let i = 1; i <= input.length; i++) {
        let two = (input[i - 2] + input[i - 1]) * 1;
        memo[i] = ((input[i - 1] !== "0" ? memo[i - 1] : 0) + (input[i - 2] && 10 <= two && 26 >= two ? memo[i - 2] : 0)) % 1000000;
        if (memo[i] == 0) {
            console.log(0);
            return;
        }
    }
    console.log(memo[input.length]);
})();
