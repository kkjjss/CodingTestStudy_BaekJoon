const fs = require("fs");

// const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ");
const input = ["1", "2"];

const [A, B] = input;

// const answer = A * 1 + B * 1;
// const answer = A * 1 - B * 1;
// const answer = (A * 1) * (B * 1);
const answer = (A * 1) / (B * 1);

console.log(answer);
