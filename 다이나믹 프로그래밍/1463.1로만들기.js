const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim();

const num = Number(input);

const memo = [0, 0, 1, 1];

function topDown(x) {
    if (x === 3 || x === 2 || x === 1) return 1;

    const arr = [];

    const a = x % 3 === 0 ? (memo[x / 3] ? memo[x / 3] : makeOne(x / 3)) : 0;
    const b = x % 2 === 0 ? (memo[x / 2] ? memo[x / 2] : makeOne(x / 2)) : 0;
    const c = memo[x - 1] ? memo[x - 1] : makeOne(x - 1);

    if (a) arr.push(a);
    if (b) arr.push(b);
    if (c) arr.push(c);

    const min = Math.min(...arr) + 1;
    memo[x] = min;
    return min;
}

function bottomUp(x) {
    for (let i = 4; i <= x; i++) {
        memo[i]=memo[i - 1]+1;
        if (i % 3 === 0) {
            memo[i]= Math.min(memo[i / 3]+1, memo[i]);
        }
        if (i % 2 === 0) {
            memo[i]= Math.min(memo[i / 2]+1, memo[i]);
        }
    }
    return memo[x];
}

console.log(bottomUp(num));