const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const input = []
rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  const [num] = input
  console.log(
    num
      .split('')
      .map((n) => parseInt(n))
      .sort((a, b) => b - a)
      .join('')
  )
})
