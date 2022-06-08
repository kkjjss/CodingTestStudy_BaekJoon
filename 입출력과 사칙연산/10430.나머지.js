const fs = require("fs");

let [a, b, c] = fs.readFileSync("/dev/stdin").toString().trim().split(" ").map((e) => e = e*1);

const result1 = (a + b) % c;
const result2 = ((a % c) + (b % c)) % c;
const result3 = (a * b) % c;
const result4 = ((a % c) * (b % c)) % c;

console.log(result1);
console.log(result2);
console.log(result3);
console.log(result4);
