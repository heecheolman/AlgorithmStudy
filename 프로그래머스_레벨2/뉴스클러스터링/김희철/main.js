function getSlicedWords(
  { word, amount = 2, filterRegex = null } = {
    word: '',
    amount: 2,
    filterRegex: null,
  }
) {
  const words = []
  const sliceEnd = word.length || 0
  let sliceStart = 0
  let sliceAmount = amount

  for (let i = sliceStart; i <= sliceEnd - amount; i++) {
    const slicedWord = word.slice(i, sliceAmount + i).toUpperCase()
    if (filterRegex) {
      filterRegex.test(slicedWord) && words.push(slicedWord)
    } else {
      words.push(slicedWord)
    }
  }
  return words
}

function getMap(array = []) {
  const map = new Map()
  array.map((x) => {
    if (map.has(x)) {
      map.set(x, map.get(x) + 1)
    } else {
      map.set(x, 1)
    }
  })
  return map
}

function getInterSectionAmount(a = [], b = []) {
  const aMap = getMap(a)
  const bMap = getMap(b)

  let interSectionAmount = 0

  for (let [key, value] of aMap) {
    if (bMap.has(key)) {
      interSectionAmount =
        value > bMap.get(key)
          ? interSectionAmount + bMap.get(key)
          : interSectionAmount + value
    }
  }

  return interSectionAmount
}

function getUnionAmount(a = [], b = []) {
  const aMap = getMap(a)
  const bMap = getMap(b)
  const cMap = new Map()
  let unionAmount = 0

  for (const [key, value] of aMap) {
    if (bMap.has(key)) {
      value > bMap.get(key)
        ? cMap.set(key, value)
        : cMap.set(key, bMap.get(key))
    } else {
      cMap.set(key, value)
    }
  }

  for (const [key, value] of bMap) {
    if (!cMap.get(key)) {
      cMap.set(key, value)
    }
  }

  for (const [key, value] of cMap) {
    unionAmount += value
  }
  return unionAmount
}

function solution(str1, str2) {
  const wordList1 = getSlicedWords({
    word: str1,
    filterRegex: /^[a-zA-Z]{0,}$/,
  })
  const wordList2 = getSlicedWords({
    word: str2,
    filterRegex: /^[a-zA-Z]{0,}$/,
  })

  const interSectionAmount = getInterSectionAmount(wordList1, wordList2)
  const unionAmount = getUnionAmount(wordList1, wordList2)
  if (interSectionAmount === 0 && unionAmount === 0) {
    return 65536
  }
  return Math.floor((interSectionAmount / unionAmount) * 65536)
}
