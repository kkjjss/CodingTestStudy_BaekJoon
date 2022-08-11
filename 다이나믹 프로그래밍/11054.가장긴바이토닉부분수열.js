const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(/[\n ]/).map((e) => e * 1);

const incMemo = [0, 1];
const decMemo = [0, 1];
let temp = 1;

function bottomUp(num) {
    for (let i = 2; i <= num; i++) {
        incMemo[i] = 1;
        decMemo[i] = 1;
        for (let j = i - 1; j > 0; j--) {
            if (input[j] < input[i]) {
                if (incMemo[j] + 1 > incMemo[i]) incMemo[i] = incMemo[j] + 1;
            } else if (input[j] > input[i]) {
                let prev = Math.max(decMemo[j], incMemo[j]);
                if (prev + 1 > decMemo[i]) decMemo[i] = prev + 1;
            }
        }
        if (Math.max(decMemo[i], incMemo[i]) > temp) temp = Math.max(decMemo[i], incMemo[i]);
    }

    return temp;
}

console.log(bottomUp(input[0]));
