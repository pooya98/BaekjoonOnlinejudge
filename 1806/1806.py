from collections import deque

N, S = map(int, input().split())
a = list(map(int, input().split()))
sum = [0]
min_len = 200000

for i in range(1, N + 1):
    sum.append(sum[i - 1] + a[i - 1])

i = 0; j = 0

while True:
    if sum[j] - sum[i] >= S:
        if j - i < min_len:
            min_len = j - i

        i += 1
    else:
        if j == N:
            break
        
        j += 1




if min_len == 200000:
    print("0")
else:         
    print(min_len)