a, b = input().split()
b = int(b)
result = 0

for i in range(0, len(a)):
  if a[-1*(i + 1)] in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    cur_value = 10 + ord(a[-1*(i + 1)]) - 65
  else:
    cur_value = int(a[-1*(i + 1)])

  result += cur_value * b**i

print(result)
