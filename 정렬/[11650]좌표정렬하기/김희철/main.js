const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const input = []
rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  input.shift()
  const locations = input.map((line) => line.split(' ').map((n) => parseInt(n)))
  locations.sort((a, b) => {
    const [ax, ay] = a
    const [bx, by] = b
    if (ax === bx) {
      return ay - by
    }
    return ax - bx
  })
  let result = ''
  for (let i = 0; i < locations.length; i++) {
    const [x, y] = locations[i]
    result += `${x} ${y}\n`
  }

  console.log(result)
})
