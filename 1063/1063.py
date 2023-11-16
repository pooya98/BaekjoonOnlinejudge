if __name__ == "__main__":
    k, s, n = input().split()
    k_x = ord(k[0]) - ord('A') + 1
    k_y = int(k[1])

    s_x = ord(s[0]) - ord('A') + 1
    s_y = int(s[1])

    n = int(n)

    for i in range(n):
        move = input()

        new_k_x, new_k_y, new_s_x, new_s_y = k_x, k_y, s_x, s_y

        if move == 'R':
            new_k_x = k_x + 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_x = s_x + 1

        elif move == 'L':
            new_k_x = k_x - 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_x = s_x - 1

        elif move == 'B':
            new_k_y = k_y - 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_y = s_y - 1

        elif move == 'T':
            new_k_y = k_y + 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_y = s_y + 1

        elif move == 'RT':
            new_k_x = k_x + 1
            new_k_y = k_y + 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_x = s_x + 1
                new_s_y = s_y + 1
                
        elif move == 'LT':
            new_k_x = k_x - 1
            new_k_y = k_y + 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_x = s_x - 1
                new_s_y = s_y + 1

        elif move == 'RB':
            new_k_x = k_x + 1
            new_k_y = k_y - 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_x = s_x + 1
                new_s_y = s_y - 1
        elif move == 'LB':
            new_k_x = k_x - 1
            new_k_y = k_y - 1
            if new_k_x == s_x and new_k_y == s_y:
                new_s_x = s_x - 1
                new_s_y = s_y - 1
        else:
            pass

        if (1 <= new_k_x <= 8) and (1 <= new_k_y <= 8) and (1 <= new_s_x <= 8) and (1 <= new_s_y <= 8):
            k_x, k_y, s_x, s_y = new_k_x, new_k_y, new_s_x, new_s_y

    
    print("{}{}\n{}{}".format(chr(k_x+ord('A') - 1), k_y, chr(s_x+ord('A') - 1), s_y))