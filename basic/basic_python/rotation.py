import sys
import math

normal = list(map(float, sys.stdin.readline().split()))

angle = math.radians(float(sys.stdin.readline()))

cosine = math.cos(angle)
sine = math.sin(angle)

matrix = [[0. for i in range(4)] for j in range(4)]

for i in range(3):
    matrix[i][i] = normal[i] * normal[i] * (1 - cosine) + cosine

matrix[0][1] = normal[0] * normal[1] * (1 - cosine) - normal[2] * sine
matrix[0][2] = normal[2] * normal[0] * (1- cosine) + normal[1] * sine
matrix[1][0] = normal[0] * normal[1] * (1 - cosine) + normal[2] * sine
matrix[1][2] = normal[1] * normal[2] * (1 - cosine) - normal[0] * sine
matrix[2][0] = normal[2] * normal[0] * (1 - cosine) - normal[1] * sine
matrix[2][1] = normal[1] * normal[2] * (1 - cosine) + normal[0] * sine
matrix[3][3] = 1

for i in range(4):
    for j in range(4):
        print(matrix[i][j],end=' ')

    print('\n',end='')

