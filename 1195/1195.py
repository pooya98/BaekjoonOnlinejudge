first_part = input()
second_part = input()

len_of_first_part = len(first_part)
len_of_second_part = len(second_part)

tester = "1"*len_of_second_part + first_part + "1"*len_of_second_part
start_first_part = len_of_second_part
end_first_part = start_first_part +len_of_first_part

min_len = len_of_first_part + len_of_second_part

for i in range(end_first_part):
    test_result = True

    for j in range(len_of_second_part):
        if tester[i + j] == '2' and second_part[j] == '2':
            test_result = False
            break

    start_point = 0
    end_point = 0

    if test_result == True:
        if i > start_first_part:
            start_point = start_first_part
        else:
            start_point = i
    
        if i + len_of_second_part > end_first_part:
            end_point = i + len_of_second_part
        else:
            end_point = end_first_part

        kickdown_len = end_point - start_point
        #print(kickdown_len)

        if kickdown_len < min_len:
            min_len = kickdown_len

print(min_len)