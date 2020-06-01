import math

T = int(input())

for _ in range(T):
  start, end = map(int, input().split())
  distance = end - start
  move_count = 0

  while not distance == 1:
    move_amount = math.floor(math.sqrt(distance))
    distance -= move_amount
    move_count += 1

  print(move_count + 1)