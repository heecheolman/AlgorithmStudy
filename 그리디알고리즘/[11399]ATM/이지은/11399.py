

N = int(input())
peeple = list(map(int, input().split()))
result = 0

peeple.sort()

for i in range(N):
    result = result + sum(peeple[:i+1])

print(str(result))
