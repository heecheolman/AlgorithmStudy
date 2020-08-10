const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const input = []
const visit = new Array(100001).fill(false)
const parent = {}

function bfs(tree) {
  const queue = []
  visit[1] = true
  queue.push(1)

  while (queue.length > 0) {
    const front = queue.pop()

    for (let i = 0; i < tree[front].length; i++) {
      const current = tree[front][i]

      if (!visit[current]) {
        queue.push(current)
        visit[current] = true
        parent[current] = front
      }
    }
  }
}

rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  const N = parseInt(input.shift())
  const tree = []
  for (let i = 0; i < N + 1; i++) {
    tree.push([])
  }

  tree[0][0] = 1

  for (let i = 0; i < input.length; i++) {
    let [node1, node2] = input[i].split(' ')
    tree[node1].push(node2)
    tree[node2].push(node1)
  }

  bfs(tree)

  let result = ''
  for (let i = 2; i <= N; i++) {
    result += `${parent[i]}\n`
  }
  console.log(result)

  process.exit()
})
