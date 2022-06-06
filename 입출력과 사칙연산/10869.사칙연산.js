const fs = require("fs");

// const [ input1, input2] = fs.readFileSync("/dev/stdin").toString().trim().split(" ");
let [input1, input2] = ["7", "3"];
input1 *= 1;
input2 *= 1;

//더하기
console.log(input1 + input2);
//빼기
console.log(input1 - input2);
//곱하기
console.log(input1 * input2);
//나누기
console.log(Math.floor(input1 / input2));
//나머지
console.log(input1 % input2);
