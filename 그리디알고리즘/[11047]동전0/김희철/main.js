const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const input = []
rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  let [N, K] = input
    .shift()
    .split(' ')
    .map((v) => parseInt(v))
  let count = 0
  for (let i = input.length - 1; i >= 0; i--) {
    const money = parseInt(input[i])
    const quotient = Math.floor(K / money)
    K -= quotient * money
    count += quotient
  }
  console.log(count)
})
