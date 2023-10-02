def GCD(a,b):
  while b != 0:
    [a, b] = [b, a%b]

  return a

def LCM(a, b):
  return a * b // GCD(a, b)

a, b = map(int, input().split())
c, d = map(int, input().split())
numerator = 0
denominator = 0

numerator = a * d + c * b
denominator = b * d

gcd = GCD(numerator, denominator)

print(numerator // gcd, denominator // gcd)