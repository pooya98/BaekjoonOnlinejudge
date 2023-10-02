import math

def grahamScan(points):

    result = []

    # step1. 우측하단점 찾고, 결과 리스트에 삽입
    start_point = points[0]

    for point in points:
        if point[1] < start_point[1]:
            start_point = point
        elif point[1] == start_point[1]:
            if point[0] > start_point[0]:
                start_point = point

    #print("start", start_point)
    
    # step2. 각 지점의 (인덱스, 각) 튜플 구하기
    angle_list = []

    for index in range(len(points)):
        target_point = points[index]
        angle = math.atan2(target_point[1]-start_point[1], target_point[0]-start_point[0])/math.pi*180
        dist = math.pow((target_point[1]-start_point[1]),2) + math.pow((target_point[0]-start_point[0]),2)
        #print(target_point, start_point, end="")
        #print(index, angle, dist)
        angle_list.append((index, angle, dist))

    
    # step3. 각를 기준으로 점 정렬하기
    sorted_angle_list = sorted(angle_list, key = lambda p: (p[1], p[2]))
    #print(sorted_angle_list)

    # step4. convex hull에 포함하는 점 찾아 추가하기
    result.append(start_point)

    for index in range(1, len(sorted_angle_list)):
        k = points[sorted_angle_list[index][0]]

        while True:
            if len(result) > 1:
                i = result[-2]
                j = result[-1]

                det = (j[0] - i[0])*(k[1] - i[1]) - (j[1] - i[1])*(k[0] - i[0])

                if det > 0:
                    break
                else:
                    result.pop()
            else:
                break

        result.append(k)


    # step5. 마지막 점 검사하기
    k = start_point

    while True:
        if len(result) > 1:
            i = result[-2]
            j = result[-1]

            det = (j[0] - i[0])*(k[1] - i[1]) - (j[1] - i[1])*(k[0] - i[0])

            if det > 0:
                break
            else:
                result.pop()
        else:
            break

    
    return result


n = int(input())
input_list = []

for _ in range(n):
    a, b = map(int, input().split())
    input_list.append((a, b))

print(len(grahamScan(input_list)))