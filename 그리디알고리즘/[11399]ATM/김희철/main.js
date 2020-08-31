const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const input = []
rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  const N = parseInt(input.shift())
  const source = [
    0,
    ...input
      .pop()
      .split(' ')
      .map((v) => parseInt(v))
      .sort((a, b) => a - b),
  ]

  const accumulated = []
  source.reduce((acc, cur) => {
    const sum = acc + cur
    accumulated.push(sum)
    return sum
  })
  const result = accumulated.reduce((acc, cur) => acc + cur)
  console.log(result)
})
