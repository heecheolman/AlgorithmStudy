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
  let result = ''
  input
    .map((person, order) => {
      const [age, name] = person.split(' ')
      return {
        order,
        age: parseInt(age),
        name,
      }
    })
    .sort((p1, p2) => {
      if (p1.age === p2.age) {
        return p1.order - p2.order
      }
      return p1.age - p2.age
    })
    .map((people) => {
      result += `${people.age} ${people.name}\n`
    })

  console.log(result)
})
