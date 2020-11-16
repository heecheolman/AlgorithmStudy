const COMMAND = {
  ENTER: 'Enter',
  CHANGE: 'Change',
  LEAVE: 'Leave',
}

function solution(record) {
  const userTable = new Map()

  record.map((row) => {
    const [command, uid, nickname] = row.split(' ')
    switch (command) {
      case COMMAND.ENTER:
      case COMMAND.CHANGE:
        userTable.set(uid, nickname)
    }
  })

  const result = []
  record.map((row) => {
    const [command, uid, nickname] = row.split(' ')
    switch (command) {
      case COMMAND.ENTER:
        result.push(`${userTable.get(uid)}님이 들어왔습니다.`)
        break
      case COMMAND.LEAVE:
        result.push(`${userTable.get(uid)}님이 나갔습니다.`)
        break
    }
  })

  return result
}
