

inputList = input().split()
N, K = int(inputList[0]), int(inputList[1])

# 최소 동전 개수
minCoinCount = 0


# coinList = [int(input()) for _ in range(N)]  # 오름차순으로 주어진다.
coinList = []  # 오름차순으로 주어진다.

for _ in range(N):
    inputNum = int(input())
    if inputNum <= K:
        coinList.append(inputNum)

for i in range(1, len(coinList)+1):
    # print(str(coinList[-i]))
    coin = coinList[-i]
    if K >= coin:
        # //연산자는 나누고 소수점 이하 버림
        count = K//coin
        K -= coin * count
        minCoinCount = minCoinCount + count

print(str(minCoinCount))

