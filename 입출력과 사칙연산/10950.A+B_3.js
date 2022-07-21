const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [count] = input;

for(let i=1; i<=count; i++){
    const [a,b]=input[i].split(' ');
    console.log(a*1+b*1);
}

