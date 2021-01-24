import sys

DIVIDER = 1000000009
MAX_NUM = 1000001

way = [0 for i in range(MAX_NUM)]
way[1] = 1
way[2] = 2
way[3] = 4


def get_way(nth):
    if nth <= 3:
        return way[nth]
    if way[nth] != 0:
        return way[nth]
    else:
        way[nth] = get_way(nth-1) + get_way(nth-2) + get_way(nth-3)
        return way[nth]


test_num = int(sys.stdin.readline())

for i in range(test_num):
    n = int(sys.stdin.readline())
    print(get_way(n))