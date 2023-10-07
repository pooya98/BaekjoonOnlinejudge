import math

n = int(input())

square_count = 4 ** n 
print(square_count + 2 * int(math.sqrt(square_count)) + 1)