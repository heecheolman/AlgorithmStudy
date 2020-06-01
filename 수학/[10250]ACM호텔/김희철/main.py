import math

T = int(input())

for _ in range(T):
  H, W, N = map(int, input().split())
  x = math.ceil(N / H)
  y = N % H
  print((H if y == 0 else y)  * 100 + x)