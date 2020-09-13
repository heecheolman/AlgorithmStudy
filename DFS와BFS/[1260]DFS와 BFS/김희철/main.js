const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const MAX = 1000
const input = []
const graph = []
const visited = new Array(MAX + 1).fill(false)
for (let i = 0; i < MAX + 1; i++) {
  graph.push([])
}

let bfsOutput = ''
let dfsOutput = ''

function bfs(rootNode) {
  const queue = []
  visited[rootNode] = true
  queue.push(rootNode)
  bfsOutput += `${rootNode}`

  while (queue.length > 0) {
    const current = queue.shift()
    for (let i = 0; i < graph[current].length; i++) {
      const nextNode = graph[current][i]
      if (!visited[nextNode]) {
        queue.push(nextNode)
        visited[nextNode] = true
        bfsOutput += ` ${nextNode}`
      }
    }
  }
}

function dfs(node) {
  if (visited[node]) {
    return
  }
  visited[node] = true
  dfsOutput += ` ${node}`
  for (let i = 0; i < graph[node].length; i++) {
    const nextNode = graph[node][i]
    dfs(nextNode)
  }
}

rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  const [N, M, V] = input
    .shift()
    .split(' ')
    .map((v) => parseInt(v))
  for (let i = 0; i < input.length; i++) {
    const [v1, v2] = input[i].split(' ')
    graph[v1].push(v2)
    graph[v2].push(v1)
  }
  for (let i = 0; i < graph.length; i++) {
    graph[i].sort((a, b) => a - b)
  }

  dfs(V)
  visited.fill(false)
  bfs(V)

  console.log(dfsOutput.trim())
  console.log(bfsOutput.trim())
})
