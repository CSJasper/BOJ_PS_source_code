import sys

row_num, column_num = int(sys.stdin.readline().split())

board = [['0' for i in range(column_num)] for j in range(row_num)]

for i in range(column_num):
    