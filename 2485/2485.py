def GCD(a, b):
  while b != 0:
    [a, b] = [b, a % b]

  return a


if __name__ == '__main__':
  n =  int(input())
  gcd = 0
  
  tree_location = []
  gap_list = []
  
  for _ in range(n):
    input_value = int(input())
    tree_location.append(input_value)

  gcd = GCD(tree_location[1] - tree_location[0], tree_location[2] - tree_location[1])

  for i in range(2, len(tree_location) - 1):
    gcd = GCD(gcd, tree_location[i + 1] - tree_location[i])


  total_distance = tree_location[-1] - tree_location[0]

  print(total_distance // gcd - n + 1)