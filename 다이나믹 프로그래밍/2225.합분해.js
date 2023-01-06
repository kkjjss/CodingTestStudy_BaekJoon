// const [N, K] = require("fs").readFileSync("/dev/stdin").toString().split(" ");

const [N, K] = "200 1".split(" ");

const memo = [[0], [0]];

(function bottomUp() {
    for (let n = 1; n <= N; n++) {
        memo[n] = [0];
        for (let k = 1; k <= K; k++) {
            memo[n][k] = (n == 1 ? k : memo[n - 1][k] + memo[n][k - 1]) % 1000000000;
        }
    }
    console.log(memo[N][K]);
})();
