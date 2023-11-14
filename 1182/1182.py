def backtracking(start_index, sum):
    global n, k, count, a

    if start_index >= n:
        return
    else:
        new_sum = sum + a[start_index]

        if new_sum == k:
            count += 1
            
        backtracking(start_index + 1, new_sum)
        backtracking(start_index + 1, sum)


if __name__ == "__main__":
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    count = 0

    backtracking(0, 0)
    print(f"{count}")
