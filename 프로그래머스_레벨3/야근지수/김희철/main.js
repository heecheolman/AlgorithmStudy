function solution(n, works) {
  const workList = [...works].sort()
  let N = n
  let index = workList.length - 1

  while (N > 0) {
    N = N - 1

    if (workList[index] > 0) {
      workList[index]--
    }
    if (workList[index] < workList[index - 1]) {
      index = index - 1
    }
  }

  return workList.reduce((acc, cur) => Math.pow(cur, 2) + acc, 0)
}
