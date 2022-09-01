const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n").map((e) => e * 1);

input.slice(1, input[0]+1).sort((a, b) => a - b).map((e) => console.log(e));