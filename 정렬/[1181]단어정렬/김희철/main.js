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
  const words = [...new Set(input)]
  let result = ''
  words
    .sort((a, b) => {
      if (a.length === b.length) {
        return a < b ? -1 : a > b ? 1 : 0
      }
      return a.length - b.length
    })
    .map((word) => (result += `${word}\n`))

  console.log(result)
})
