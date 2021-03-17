import sys

people_num = int(sys.stdin.readline())

info = [[0, 0] for i in range(people_num)]

for i in range(people_num):
    info[i][0], info[i][1] = map(int, sys.stdin.readline().split())

grade_list = []

for i in range(people_num):
    size_grade = 1
    for j in range(people_num):
        if j == i:
            continue
        if info[i][0] < info[j][0] and info[i][1] < info[j][1]:
            size_grade += 1
    grade_list.append(size_grade)

for i in range(len(grade_list)):
    print(grade_list[i], end=' ')