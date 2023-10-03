import math

n = int(input())
a = list(map(int, input().split()))
result = (0, 0)

threshold = 2000000000

a.sort()

i = 0; j = n-1

while i < j:
    cur_value = math.fabs(a[i] + a[j])

    if cur_value < threshold:
        threshold = cur_value
        result = (i, j)

    if math.fabs(a[i]) < math.fabs(a[j]):
        j -= 1
    else:
        i += 1

print(a[result[0]], a[result[1]])