const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const dx = [-1, 0, 1, 0]
const dy = [0, 1, 0, -1]
const input = []
const map = []
const visited = []
const queue = []
let front = 0
let N,
  M = 0
let day = 0

function isAllRipe() {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (!visited[i][j]) {
        return false
      }
    }
  }

  return true
}

function bfs() {
  while (queue.length - front) {
    const currentPoint = queue[front]
    for (let i = 0; i < 4; i++) {
      const nextX = currentPoint.x + dx[i]
      const nextY = currentPoint.y + dy[i]

      if (
        0 <= nextX &&
        nextX < M &&
        0 <= nextY &&
        nextY < N &&
        map[nextY][nextX] === 0 &&
        !visited[nextY][nextX]
      ) {
        const nextPoint = {
          x: parseInt(nextX),
          y: parseInt(nextY),
          day: currentPoint.day + 1,
        }
        day = nextPoint.day
        visited[nextY][nextX] = true
        map[nextY][nextX] = 1
        queue.push(nextPoint)
      }
    }
    front++
  }
}

rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  const [X, Y] = input
    .shift()
    .split(' ')
    .map((value) => parseInt(value))
  N = Y
  M = X

  for (let i = 0; i < input.length; i++) {
    const row = input[i].split(' ').map((value) => parseInt(value))
    map.push(row)
    visited.push(new Array(row.length).fill(false))
  }

  for (let y = 0; y < N; y++) {
    for (let x = 0; x < M; x++) {
      if (map[y][x] === 1) {
        const point = {
          x: parseInt(x),
          y: parseInt(y),
          day: 0,
        }
        queue.push(point)
        visited[y][x] = true
      } else if (map[y][x] === -1) {
        visited[y][x] = true
      }
    }
  }

  bfs()
  isAllRipe() ? console.log(day) : console.log(-1)
})
