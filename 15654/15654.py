# start : 현재 탐색 여부를 결정할 원소들 중 가장 작은 index
# end : 종료 원소의 index
# count : 현재 sequence에 포함되어 있는 원소 수
def backtracking(count):
    global visited, seq, m, n, a

    for i in range(n):
        if visited[i] == False:
            visited[i] = True
            seq.append(a[i])
            count += 1

            if count == m:
                for e in seq:
                    print(f"{e} ", end="")
                print()
            else:
                backtracking(count)

            visited[i] = False
            del seq[-1]
            count -= 1

    
if __name__ == "__main__":
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    visited = [False for _ in range(n)] 
    seq = []
    backtracking(0)
