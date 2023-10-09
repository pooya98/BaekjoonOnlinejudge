n = int(input())
a = list(map(int, input().split()))
x = int(input())
count = 0

a.sort()

i = 0; j = n -1

while i < j:
    if a[i] + a[j] == x:
        count += 1
        i += 1
    elif a[i] + a[j] < x:
        i += 1
    else:
        j -= 1

print(count)
