import sys

SUDOKU_SIZE = 9

sudoku = [[] for i in range(SUDOKU_SIZE)]

for i in range(SUDOKU_SIZE):
    sudoku[i] = list(map(int, sys.stdin.readline().split()))

for i in range(SUDOKU_SIZE):
    for j in range(SUDOKU_SIZE):
        if sudoku[i][j] != 0:
            continue
        # 만약 0이라면 3가지 조건을 만족하는지 확인한다.
        for candidate in range(1,10):
            if candidate not in sudoku[i]:  # 이러면 가로줄에 candidate 는 위배되지 않게 올 수 있는것!

