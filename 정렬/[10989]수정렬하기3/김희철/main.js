const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})


const input = []

rl.on('line', (line) => {
  input.push(parseInt(line))
}).on('close', () => {
  input.shift()

  const max = input.reduce((a, b) => Math.max(a, b))
  const min = input.reduce((a, b) => Math.min(a, b))

  let counting = new Array(max).fill(0)
  let output = new Array(input.length)

  // 카운팅
  for (let i = 0; i < input.length; i++) {
    counting[input[i] - min]++
  }
  // 누적
  for (let i = 1; i < counting.length; i++) {
    counting[i] += counting[i - 1]
  }

  for (let i = input.length - 1; i >= 0; i--) {
    output[--counting[input[i] - min]] = input[i]
  }

  output.map((v) => console.log(v))

  process.exit()
})
