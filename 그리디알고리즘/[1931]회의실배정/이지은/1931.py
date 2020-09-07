N = int(input())

arr = []
endTime, count = 0, 0

for _ in range(N):
    inputText = input().split()
    arr.append((int(inputText[0]), int(inputText[1])))

arr.sort(key=lambda x: (x[1], x[0]))

for i in range(N):
    if endTime <= arr[i][0]:
        endTime = arr[i][1]
        count = count + 1

print(count)
