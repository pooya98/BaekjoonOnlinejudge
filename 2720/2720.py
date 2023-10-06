t = int(input())
coin = [25, 10, 5, 1]

for _ in range(t):
  count = [0, 0, 0, 0]
  pay = int(input())

  for i in range(4):
    count[i] = pay // coin[i]
    pay = pay % coin[i]

  for i in count:
    print(i, end=" ")

  print()
