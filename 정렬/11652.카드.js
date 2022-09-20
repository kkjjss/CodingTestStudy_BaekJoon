// const fs = require("fs");
// const input = fs
//     .readFileSync("/dev/stdin")
//     .toString()
//     .split(/\n/)
//     .map((e) => e * 1);

const input = `5
2
1
1
2
1
2`
    .split(/\n/)
    .map((e) => BigInt(e));

const countsOfCards = new Array();

let greatestNum = 0;

input.forEach((num) => {
    if (!countsOfCards[num]) countsOfCards[num] = 0;
    countsOfCards[num] += 1;
});

countsOfCards.forEach((v, i) => {
    if (greatestNum === 0) greatestNum = i;
    else if (countsOfCards[greatestNum] < v) greatestNum = i;
});

console.log(greatestNum);
