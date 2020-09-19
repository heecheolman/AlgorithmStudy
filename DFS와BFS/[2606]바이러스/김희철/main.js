const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const MAX = 100
const input = []
const graph = []
const visited = new Array(MAX + 1).fill(false)

for (let i = 0; i < MAX + 1; i++) {
  graph.push([])
}

function bfs(node) {
  const queue = []
  queue.push(node)
  visited[node] = true

  while (queue.length > 0) {
    const currentNode = queue.shift()
    for (let i = 0; i < graph[currentNode].length; i++) {
      const nextNode = graph[currentNode][i]
      if (!visited[nextNode]) {
        queue.push(nextNode)
        visited[nextNode] = true
      }
    }
  }
}

function getVisitedCount() {
  return visited.filter((visit) => !!visit).length
}

rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  const computerCount = input.shift()
  const connectCounnt = input.shift()

  for (let i = 0; i < input.length; i++) {
    const [com1, com2] = input[i].split(' ').map((value) => parseInt(value))
    graph[com1].push(com2)
    graph[com2].push(com1)
  }

  bfs(1)
  console.log(getVisitedCount() - 1)
})
