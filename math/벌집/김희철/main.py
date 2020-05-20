
target = int(input());

n = 1
start = 1
end = 1


while True:
  if target == 1:
    print(n)
    break

  start = end + 1
  end = start + ((6 * n) - 1)
  n += 1

  if start <= target and target <= end:
    print(n)
    break
