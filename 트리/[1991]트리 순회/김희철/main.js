const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
})

const input = []
const tree = {}
const output = {
  preOrder: '',
  inOrder: '',
  postOrder: '',
}

function preOrder(current) {
  if (current === '.') {
    return
  }

  const [left, right] = tree[current]

  output.preOrder += current
  preOrder(left, output)
  preOrder(right, output)
}

function inOrder(current) {
  if (current === '.') {
    return
  }

  const [left, right] = tree[current]

  inOrder(left, output)
  output.inOrder += current
  inOrder(right, output)
}

function postOrder(current) {
  if (current === '.') {
    return
  }

  const [left, right] = tree[current]

  postOrder(left, output)
  postOrder(right, output)
  output.postOrder += current
}

rl.on('line', (line) => {
  input.push(line)
}).on('close', () => {
  input.shift()
  for (let i = 0; i < input.length; i++) {
    const [node, left, right] = input[i].split(' ')

    if (tree[node]) {
      tree[node].push(left)
      tree[node].push(right)
    } else {
      tree[node] = []
      tree[node].push(left)
      tree[node].push(right)
    }
  }

  preOrder('A')
  inOrder('A')
  postOrder('A')
  console.log(output.preOrder)
  console.log(output.inOrder)
  console.log(output.postOrder)
})
