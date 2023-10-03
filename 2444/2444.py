n = int(input())

for i in range(1, 2 * n):
  if i <= n:
    print(" " * (n - i), end = "")
    print("*" * (2 * (i - 1) + 1))
  else:
    print(" " * (i - n), end = "")
    print("*" * (2 * (2*n - i - 1) + 1))