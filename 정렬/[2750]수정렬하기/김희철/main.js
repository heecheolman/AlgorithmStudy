const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
  input.push(parseInt(line));
}).on("close", () => {
  input.shift();
  for (let i = 0; i < input.length; i++) {
    for (let j = 0; j < input.length - 1 - i; j++) {
      if (input[j] > input[j + 1]) {
        [input[j], input[j + 1]] = [input[j + 1], input[j]];
      }
    }
  }

  input.map((v) => console.log(v));

  process.exit();
});
