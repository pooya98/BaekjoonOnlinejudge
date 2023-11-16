n, m = map(int, input().split())
board = []

# step01. Board 생성
for i in range(n):
    new_row = []
    in_str = input()

    for c in in_str:
        new_row.append(int(c))

    board.append(new_row)

# step02. Board 순회하며 검사
max_step = 1
end_step = min(n, m)

for step in range(2, end_step + 1):
    for s_x in range(0, m):
        for s_y in range(0, n):
            e_x = s_x + step - 1
            e_y = s_y + step - 1

            if e_x < m and e_y < n:
                if board[s_y][s_x] == board[e_y][s_x] and board[s_y][s_x] == board[s_y][e_x] and board[s_y][s_x] == board[e_y][e_x]:
                    if step > max_step:
                        max_step = step

print(max_step * max_step)