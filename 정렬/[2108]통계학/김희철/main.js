const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const input = []

function getAverage(array, divide) {
  return Math.round(
    array.reduce((acc, cur) => parseInt(acc) + parseInt(cur), 0) / divide
  )
}

function getMode(array) {
  const map = {}
  // reduce 를 쓰면 timeout
  for (let i = 0; i < array.length; i++) {
    if (map[array[i]]) {
      map[array[i]]++
    } else {
      map[array[i]] = 1
    }
  }
  const max = Object.values(map).reduce((a, b) => Math.max(a, b))
  const maxValues = []
  for (const key in map) {
    if (map[key] === max) {
      maxValues.push(parseInt(key))
    }
  }
  maxValues.sort((a, b) => parseInt(a) - parseInt(b))
  const [first, second] = maxValues
  return second || first
}

rl.on('line', (line) => {
  input.push(parseInt(line))
}).on('close', () => {
  const N = input.shift()

  input.sort((a, b) => a - b)

  const average = getAverage(input, N)
  const center = input[Math.floor(input.length / 2)]
  const mode = getMode(input)
  const range = input[input.length - 1] - input[0]

  console.log(average)
  console.log(center)
  console.log(mode)
  console.log(range)
})
