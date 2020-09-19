const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const MAX = 50
const input = []
const map = []
let label = 2

function initialize() {
  for (let i = 0; i < MAX; i++) {
    map.push(new Array(MAX).fill(0))
  }
  label = 2
}

function bfs(point) {
  const queue = []
  queue.push(point)
  map[point.y][point.x] = label

  while (queue.length > 0) {
    const currentPoint = queue.shift()
    const dx = [-1, 0, 1, 0]
    const dy = [0, 1, 0, -1]
    for (let i = 0; i < 4; i++) {
      const nextX = currentPoint.x + dx[i]
      const nextY = currentPoint.y + dy[i]

      if (
        0 <= nextX &&
        nextX < MAX &&
        0 <= nextY &&
        nextY < MAX &&
        map[nextY][nextX] === 1
      ) {
        const nextPoint = {
          x: parseInt(nextX),
          y: parseInt(nextY),
        }
        queue.push(nextPoint)
        map[nextY][nextX] = label
      }
    }
  }
}

rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  const T = parseInt(input.shift())

  for (let i = 0; i < T; i++) {
    initialize()

    const [M, N, K] = input
      .shift()
      .split(' ')
      .map((value) => parseInt(value))

    for (let j = 0; j < K; j++) {
      const [x, y] = input
        .shift()
        .split(' ')
        .map((value) => parseInt(value))
      map[x][y] = 1
    }

    for (let y = 0; y < MAX; y++) {
      for (let x = 0; x < MAX; x++) {
        if (map[y][x] === 1) {
          const point = {
            x: parseInt(x),
            y: parseInt(y),
          }
          bfs(point)
          label = label + 1
        }
      }
    }

    console.log(label - 2)
  }
})
